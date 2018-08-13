#include "umc_stage_mediator.h"



UMCStageMediator::UMCStageMediator(UMCStage* stage, UMCStageManager* manager, UMCStageStore* store)
	:m_pStage(stage),
	m_pStageManager(manager),
	m_pStageStore(store)
{
}


UMCStageMediator::~UMCStageMediator()
{
}

void UMCStageMediator::AddSprite(UMCBaseSprite* sprite)
{
	m_pStageStore->PushFront(sprite);
}

void UMCStageMediator::GetStore() {

}