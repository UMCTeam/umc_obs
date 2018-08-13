#include "umc_stage.h"

UMCStage::UMCStage(QWidget *parent)
	: QWidget(parent),
	m_isLiveThread(true)
{
	ui.setupUi(this);
	setUpdatesEnabled(false);

	SDLRegister();
}

UMCStage::~UMCStage()
{
	m_isLiveThread = false;
	SDL_WaitThread(m_pSDLRenderThread, 0);
	SDL_WaitThread(m_pSDLEventThread, 0);
	SDL_WaitThread(m_pSDLCaptureThread, 0);
	SDL_Quit();
	IMG_Quit();

	m_pRenderer ? SDL_DestroyRenderer(m_pRenderer) :"";
}

void UMCStage::setObjectName(const QString &name)
{
	this->QWidget::setObjectName(name);
}

void UMCStage::SDLRegister()
{
	SDL_Init(SDL_INIT_VIDEO);
	SDL_InitSubSystem(SDL_INIT_VIDEO);
	IMG_Init(IMG_INIT_PNG);
}

void UMCStage::Load(UMCStageMediator* mediator)
{
	m_pWin = SDL_CreateWindowFrom((void*)winId());
	m_pRenderer = SDL_CreateRenderer(m_pWin, -1, SDL_RENDERER_SOFTWARE);
	m_pSpriteVector = new SpriteVector();

	m_pSDLRenderThread = SDL_CreateThread(SDLRenderThread, "umc_sdl_render_thread", this);
	m_pSDLEventThread = SDL_CreateThread(SDLEventThread, "umc_sdl_event_thread", this);
	m_pSDLCaptureThread = SDL_CreateThread(SDLCaptureThread, "umc_sdl_capture_thread", this);
}

UMCStage::SpriteVector* UMCStage::GetSurfaceVector()
{
	return m_pSpriteVector;
}

void UMCStage::AddSprite(UMCBaseSprite* sprite)
{
	m_pSpriteVector->push_back(sprite);
}

int UMCStage::SDLRenderThread(void * data)
{
	SDL_Event event;
	UMCStage* widget = static_cast<UMCStage*>(data);
	//SDL thread 
	while (widget->m_isLiveThread)
	{
		int timeStart = SDL_GetTicks();

		UMCStage::HandleSDLDraw(widget);

		int timeEnd = SDL_GetTicks();

		if ((timeEnd - timeStart) < (1000 / FPS)) {
			SDL_Delay((1000 / FPS) - (timeEnd - timeStart));
		}

		Sleep(1);
	}
	return 0;
}

int UMCStage::SDLEventThread(void * data)
{
	SDL_Event event;
	UMCStage* widget = static_cast<UMCStage*>(data);
	//SDL thread 
	while (widget->m_isLiveThread)
	{
		SDL_PollEvent(&event);
		UMCStage::HandleSDLEvent(widget, event);
		Sleep(1);
	}
	return 0;
}


int UMCStage::SDLCaptureThread(void* data)
{
	UMCStage* widget = static_cast<UMCStage*>(data);
	SDL_Renderer*  render = widget->m_pRenderer;
	while (widget->m_isLiveThread)
	{
		int timeStart = SDL_GetTicks();

		uint Rmask = 0x00FF0000, Gmask = 0x0000FF00, Bmask = 0x000000FF, Amask = 0x00000000;
		SDL_Surface* surface = SDL_CreateRGBSurface(0, 1000, 600, 32, Rmask, Gmask, Bmask, Amask);
		SDL_RenderReadPixels(render, nullptr, 0, surface->pixels, surface->pitch);
		int i = SDL_SaveBMP(surface, "c:/demo.bmp");
		SDL_FreeSurface(surface);

		int timeEnd = SDL_GetTicks();
		if ((timeEnd - timeStart) < (1000 / FPS)) {
			SDL_Delay((1000 / FPS) - (timeEnd - timeStart));
		}

		Sleep(1);
	}

	return 0;
}

int UMCStage::HandleSDLEvent(UMCStage* widget, SDL_Event& event)
{
	static EventTargetType target_event = EventTargetType(nullptr, UMCDistrictType::Without);

	int motion_x = event.motion.x;
	int motion_y = event.motion.y;
	int motionXrel = event.motion.xrel;
	int motionYrel = event.motion.yrel;

	if (event.type == SDL_EventType::SDL_MOUSEBUTTONDOWN) {

		target_event = widget->GetEventTarget(event.button.x, event.button.y);

	} else if (event.type == SDL_EventType::SDL_MOUSEMOTION) {

		static int before_motion_x = motion_x;
		static int before_motion_y = motion_y;
		
		if (before_motion_x == event.motion.x && before_motion_y == event.motion.y) return 0;
		
		before_motion_x = motion_x;
		before_motion_y = motion_y;
		
		UMCBaseSprite* layer = target_event.first;
		UMCDistrictType where = target_event.second;

		if (target_event.first) {

			if (where != UMCDistrictType::Within) {
				switch (target_event.second)
				{
				case TL:
					layer->TLResize(motionXrel, motionYrel);
					break;
				case TR:
					layer->TRResize(motionXrel, motionYrel);
					break;
				case BL:
					layer->BLResize(motionXrel, motionYrel);
					break;
				case BR:
					layer->BRResize(motionXrel, motionYrel);
					break;
				}
			}
			else {
				layer->Move(motionXrel, motionYrel);
			}
		}
	} else if (event.type == SDL_EventType::SDL_MOUSEBUTTONUP) {
		target_event.first = nullptr;
		target_event.second = UMCDistrictType::Without;
	}
	return 0;
}

bool UMCStage::HandleSDLDraw(UMCStage* widget)
{
	SpriteVector* sVector = widget->m_pSpriteVector;

	SDL_RenderClear(widget->m_pRenderer);

	//定义数据锁作用域
	{
		unique_lock<mutex> lock(widget->m_layerVectorMutex);
		for (auto layer : *sVector)
		{
			layer->RenderDraw(widget->m_pRenderer);
		}
	}

	//设置黑色幕布
	SDL_SetRenderDrawColor(widget->m_pRenderer, 0, 0, 0, 255);
	SDL_RenderPresent(widget->m_pRenderer);

	return 0;
}

UMCStage::EventTargetType UMCStage::GetEventTarget(int x, int y)
{
	vector<UMCBaseSprite*>::reverse_iterator r_iter;

	unique_lock<mutex> lock(m_layerVectorMutex);
	for (r_iter = m_pSpriteVector->rbegin(); r_iter != m_pSpriteVector->rend(); ++r_iter)
	{
		UMCDistrictType where = (*r_iter)->GetDistrict(x, y);
		if ( UMCDistrictType::Without != where) {
			return EventTargetType(*r_iter, where);
		}
	}

	return EventTargetType(nullptr, UMCDistrictType::Without);
}
