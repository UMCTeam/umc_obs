#include "umc_stage_store.h"

UMCStageStore::UMCStageStore()
{
	
}


UMCStageStore::~UMCStageStore()
{

}

void UMCStageStore::Load(UMCStageMediator* mediator)
{
	m_pStore = new SpriteVector();
}

void UMCStageStore::PushFront(UMCBaseSprite* sprite)
{
	unique_lock<mutex> lock(m_mutex);
	m_pStore->insert(m_pStore->begin(), sprite);
}

void UMCStageStore::Swap(UMCBaseSprite* src, UMCBaseSprite* dst)
{
	unique_lock<mutex> lock(m_mutex);
	//TODO: 
}

void UMCStageStore::Clear()
{
	
}
