#pragma once
#include "umc_base_sprite.h"

#include <QDebug>

class UMCImageSprite:public UMCBaseSprite
{
public:
	UMCImageSprite(const char* filename, int x, int y, int width, int height);
	~UMCImageSprite();

	SDL_Rect* GetRect() final;
	void RenderDraw(SDL_Renderer* render) final;
	void RenderDrawEx(SDL_Renderer* render, void* pixels, int pitch) final;

private:
	int m_id;
	const char* m_pfilename;

	SDL_Texture* m_pTexture;
};

