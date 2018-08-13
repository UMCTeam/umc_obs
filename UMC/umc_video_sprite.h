#pragma once
#include <qglobal.h>
#include "umc_base_sprite.h"
#include "umc_capture.h"

class UMCVideoSprite:public UMCBaseSprite
{
public:
	UMCVideoSprite();
	~UMCVideoSprite();
	
	SDL_Rect* GetRect() final;
	void RenderDraw(SDL_Renderer* render) final;
	void RenderDrawEx(SDL_Renderer* render, void* pixels, int pitch) final;
	
private:
	SDL_Texture* m_pTexture;
	UMCCapture* m_pSource;
};

