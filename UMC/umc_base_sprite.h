#pragma once
#include <stdlib.h>
#include <QDebug>
extern "C"
{
#include "SDL.h"
#include "SDL_image.h"
}

#include "umc_define.h"

class UMCBaseSprite
{

public:
	UMCBaseSprite();
	~UMCBaseSprite();

	int x();
	int y();
	int width();
	int height();

	UMCDistrictType GetDistrict(int x , int y);
	void TLResize(int xrel, int yrel);
	void TRResize(int xrel, int yrel);
	void BLResize(int xrel, int yrel);
	void BRResize(int xrel, int yrel);
	void Move(int xrel , int yrel);
	
	virtual SDL_Rect* GetRect();
	virtual void RenderDraw(SDL_Renderer* render);
	virtual void RenderDrawEx(SDL_Renderer* render, void* pixels, int pitch);
	
protected:
	SDL_Rect* m_pRect;
};

