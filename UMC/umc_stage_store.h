#pragma once
#include <vector>
#include <mutex>

#include "umc_base_sprite.h"
#include "umc_stage_mediator.h"

using namespace std;

class UMCStageStore
{
protected:
	typedef vector<UMCBaseSprite*> SpriteVector;

public:
	UMCStageStore();
	~UMCStageStore();
public:
	//************************************
	// Method:    Load
	// FullName:  UMCStageStore::Load
	// Access:    private 
	// Returns:   void
	// Description: ªπ‘≠≈‰÷√
	//************************************
	void Load(UMCStageMediator* mediator);

	void PushFront(UMCBaseSprite* sprite);
	void Swap(UMCBaseSprite* srcSprite, UMCBaseSprite* dst);
	void Clear();
private:
	SpriteVector* m_pStore;
	mutex         m_mutex;
};

