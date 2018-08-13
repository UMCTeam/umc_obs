#include "umc_sprite_factor.h"



UMCSpriteFactor::UMCSpriteFactor()
{
}


UMCSpriteFactor::~UMCSpriteFactor()
{
}

UMCBaseSprite* UMCSpriteFactor::CreateLayer(LayerData data) { 
	switch (data.type)
	{
	case UMCSpriteFactor::IMAGE:
		return nullptr;
		break;
	case UMCSpriteFactor::VIDEO:
		return new UMCVideoSprite();
		break;
	case UMCSpriteFactor::TEXT:
		return nullptr;
		break;
	default:
		break;
	}
	
	return nullptr;
}