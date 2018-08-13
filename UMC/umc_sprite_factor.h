#pragma once
#include "umc_base_sprite.h"
#include "umc_video_sprite.h"

class UMCSpriteFactor
{
public:
	enum LayerType {
		IMAGE,
		VIDEO,
		TEXT
	};

	struct LayerData
	{
		LayerType type;
		char filename[];
	}; 

	UMCSpriteFactor();
	~UMCSpriteFactor();
	static UMCBaseSprite* CreateLayer(LayerData data);
};

