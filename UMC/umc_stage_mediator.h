#pragma once
#include "umc_base_sprite.h"
#include "umc_stage_manager.h"
#include "umc_stage.h"
#include "umc_stage_store.h"

class UMCStageMediator
{
public:
	UMCStageMediator(UMCStage* stage, UMCStageManager* manager, UMCStageStore* store);
	~UMCStageMediator();

public:
	void AddSprite(UMCBaseSprite* sprite);
	void GetStore();

private:
	UMCStage*        m_pStage;
	UMCStageManager* m_pStageManager;
	UMCStageStore*   m_pStageStore;
};

