#pragma once
#include <Windows.h>

const int SCREEN_X = GetSystemMetrics(SM_CXSCREEN);
const int SCREEN_Y = GetSystemMetrics(SM_CYSCREEN);

const int UMC_VIDEO_SPRITE_WIDTH  = 400;
const int UMC_VIDEO_SPRITE_HEIGHT = 250;
const int UMC_VIDEO_SPRITE_X = 30;
const int UMC_VIDEO_SPRITE_Y = 30;


const int UMC_BASE_SPRITE_MARGIN  = 6;
const int UMC_BASE_SPRITE_PADDING = 6;

const int UMC_MANAGER_SPRITE_MARAGER = 4;
const int UMC_MANAGER_SPRITE_HEIGHT  = 110;

struct UMCRectType
{
	int x;
	int y;
	int width;
	int height;
};

enum UMCDistrictType {
	TL,
	TR,
	BL,
	BR,
	Within,
	Without
};