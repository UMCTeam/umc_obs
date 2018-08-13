#include "umc.h"

UMC::UMC(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	
	m_pStage = this->ui.stage;
	m_pStageManager = this->ui.stage_manager;

	m_pStageMediator = new UMCStageMediator();
	m_pStageStore = new UMCStageStore();
	
	//必须优先装载配置文件
	m_pStageStore->Load(m_pStageMediator);
	m_pStage->Load(m_pStageMediator);
	m_pStageManager->Load(m_pStageMediator);


	UMCVideoSprite* layer = new UMCVideoSprite();
	UMCImageSprite* layer1 = new UMCImageSprite("F:/chendaole/sdlqwidget/out/res/123.png", 0, 0, 300, 200);
	m_pStage->AddSprite(layer);
	m_pStage->AddSprite(layer1);
}
