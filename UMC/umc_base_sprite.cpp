#include "umc_base_sprite.h"



UMCBaseSprite::UMCBaseSprite()
{
}


UMCBaseSprite::~UMCBaseSprite()
{
}

int UMCBaseSprite::x()
{
	return m_pRect->x;
}

int UMCBaseSprite::y()
{
	return m_pRect->y;
}

int UMCBaseSprite::width()
{
	return m_pRect->w;
}

int UMCBaseSprite::height()
{
	return m_pRect->h;
}

UMCDistrictType UMCBaseSprite::GetDistrict(int x, int y)
{
	bool l = abs(this->x() - x) < UMC_BASE_SPRITE_PADDING;
	bool r = abs(this->x() + width() - x) < UMC_BASE_SPRITE_PADDING;
	bool t = abs(this->y() - y) < UMC_BASE_SPRITE_PADDING;
	bool b = abs(this->y() + height() - y) < UMC_BASE_SPRITE_PADDING;

	if (t && l) {
		return TL;
	}
	else if (t && r) {
		return TR;
	}
	else if (b && l) {
		return BL;
	}
	else if (b & r) {
		return BR;
	}
	
	if (this->x() <= x  && 
		x < (this->x() + this->width()) && 
		this->y() <= y &&
		y < (this->y() + this->height()))
	{
		return Within;
	}
	
	return Without;
}

void UMCBaseSprite::TLResize(int xrel, int yrel)
{

	this->m_pRect->x += xrel;
	this->m_pRect->y += yrel;
	this->m_pRect->w -= xrel * 2;
	this->m_pRect->h -= yrel * 2;
}

void UMCBaseSprite::TRResize(int xrel, int yrel)
{
	this->m_pRect->x -= xrel;
	this->m_pRect->y += yrel;
	this->m_pRect->w += xrel * 2;
	this->m_pRect->h -= yrel * 2;
}

void UMCBaseSprite::BLResize(int xrel, int yrel)
{
	this->m_pRect->x += xrel;
	this->m_pRect->y -= yrel;
	this->m_pRect->w -= xrel * 2;
	this->m_pRect->h += yrel * 2;
}

void UMCBaseSprite::BRResize(int xrel, int yrel)
{
	this->m_pRect->x -= xrel;
	this->m_pRect->y -= yrel;

	this->m_pRect->w += xrel * 2;
	this->m_pRect->h += yrel * 2;
}

void UMCBaseSprite::Move(int xrel, int yrel)
{
	this->m_pRect->x += xrel;
	this->m_pRect->y += yrel;
}

SDL_Rect* UMCBaseSprite::GetRect() { return nullptr; }
void UMCBaseSprite::RenderDraw(SDL_Renderer* render) {}
void UMCBaseSprite::RenderDrawEx(SDL_Renderer* render, void* pixels, int pitch) {}