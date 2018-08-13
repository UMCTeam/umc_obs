#include "umc_image_sprite.h"

UMCImageSprite::UMCImageSprite(const char* filename, int x, int y, int width, int height)
	:UMCBaseSprite(),
	m_pfilename(filename)
{
	m_pTexture = nullptr;
	m_pRect = new SDL_Rect();
	m_pRect->x = x;
	m_pRect->y = y;
	m_pRect->w = width;
	m_pRect->h = height;
}


UMCImageSprite::~UMCImageSprite()
{
}

SDL_Rect* UMCImageSprite::GetRect()
{
	return m_pRect;
}

void UMCImageSprite::RenderDraw(SDL_Renderer* render)
{
	if (m_pTexture == nullptr) {
		SDL_Surface* surface = IMG_Load(m_pfilename);
		m_pTexture = SDL_CreateTextureFromSurface(render, surface);
		SDL_FreeSurface(surface);
	} 

	SDL_RenderCopy(render, m_pTexture, nullptr, m_pRect);
	SDL_SetRenderDrawColor(render, 255, 0, 0, 255);
	
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

void UMCImageSprite::RenderDrawEx(SDL_Renderer* render, void* pixels, int pitch)
{
	//TODO:À©Õ¹
}
