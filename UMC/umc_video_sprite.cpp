#include "umc_video_sprite.h"



UMCVideoSprite::UMCVideoSprite()
	: UMCBaseSprite()
{
	m_pSource = new UMCCapture();
	m_pTexture = nullptr;

	m_pRect = new SDL_Rect();
	m_pRect->w = UMC_VIDEO_SPRITE_WIDTH;
	m_pRect->h = UMC_VIDEO_SPRITE_HEIGHT;
	m_pRect->x = UMC_VIDEO_SPRITE_X;
	m_pRect->y = UMC_VIDEO_SPRITE_Y;
}

UMCVideoSprite::~UMCVideoSprite()
{
}

SDL_Rect* UMCVideoSprite::GetRect()
{
	return m_pRect;
}

void UMCVideoSprite::RenderDraw(SDL_Renderer* render)
{
	BITMAPINFO info = m_pSource->ReadBimapInfo();
	void* pixels = m_pSource->ReadBimapData();
	int pitch = m_pSource->GetPitch();

	if (m_pTexture == nullptr) {
		uint Rmask = 0x00FF0000, Gmask = 0x0000FF00, Bmask = 0x000000FF, Amask = 0x00000000;
		SDL_Surface* surface = SDL_CreateRGBSurfaceFrom(
			pixels,
			info.bmiHeader.biWidth,
			info.bmiHeader.biHeight,
			info.bmiHeader.biBitCount,
			pitch,
			Rmask,
			Gmask,
			Bmask,
			Amask
		);
		m_pTexture = SDL_CreateTextureFromSurface(render, surface);
		SDL_FreeSurface(surface);
	}
	else {
		SDL_UpdateTexture(m_pTexture, NULL, pixels, pitch);
	}

	SDL_SetRenderDrawColor(render, 255, 0, 0, 255);
	SDL_RenderCopyEx(render, m_pTexture, nullptr, m_pRect, 0, NULL, SDL_FLIP_VERTICAL);
	HeapFree(GetProcessHeap(), HEAP_NO_SERIALIZE, pixels);

	//»æÖÆ±ß¿ò
	SDL_RenderDrawRect(render, m_pRect);

	SDL_Rect tmp_rect;
	tmp_rect.x = m_pRect->x - UMC_BASE_SPRITE_MARGIN;
	tmp_rect.y = m_pRect->y - UMC_BASE_SPRITE_MARGIN;
	tmp_rect.w = 2 * UMC_BASE_SPRITE_MARGIN;
	tmp_rect.h = 2 * UMC_BASE_SPRITE_MARGIN;
	SDL_RenderDrawRect(render, &tmp_rect);

	tmp_rect.x += m_pRect->w;
	SDL_RenderDrawRect(render, &tmp_rect);

	tmp_rect.y += m_pRect->h;
	SDL_RenderDrawRect(render, &tmp_rect);

	tmp_rect.x -= m_pRect->w;
	SDL_RenderDrawRect(render, &tmp_rect);
}

void UMCVideoSprite::RenderDrawEx(SDL_Renderer* render, void* pixels, int pitch)
{
	//TODO:À©Õ¹
}
