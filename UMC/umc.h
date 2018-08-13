#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_umc.h"

#include "umc_stage_store.h"
#include "umc_stage_mediator.h"
#include "umc_stage.h"
#include "umc_video_sprite.h"
#include "umc_image_sprite.h"

class UMC : public QMainWindow
{
	Q_OBJECT

public:
	UMC(QWidget *parent = Q_NULLPTR);

private:
	Ui::UMCClass ui;

private:
	//UMCStage÷–ΩÈ’ﬂ
	UMCStageMediator* m_pStageMediator;

	UMCStageManager*  m_pStageManager;
	UMCStage*         m_pStage;
	UMCStageStore*    m_pStageStore;
};
