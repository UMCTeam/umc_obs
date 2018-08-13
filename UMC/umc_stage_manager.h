#pragma once

#include <QWidget>
#include <QListWidgetItem>
#include <QVBoxLayout>
#include <QPushButton>
#include "ui_umc_stage_manager.h"
#include "umc_stage_mediator.h"
#include "umc_base_sprite.h"
#include "umc_image_sprite.h"
#include "umc_video_sprite.h"

#include "umc_define.h"

class UMCStageManager : public QWidget
{
	Q_OBJECT

public:
	UMCStageManager(QWidget *parent = Q_NULLPTR);
	~UMCStageManager();

private:
	QPushButton* CreateNewLayerButton();

signals:
	void Up(UMCBaseSprite* layer);
	void Down(UMCBaseSprite* layer); 

public slots:
	void AddSprite();

public:
	void Load(UMCStageMediator* mediator);

private:
	Ui::UMCStageManager ui;

private:
	UMCStageMediator* m_pMediator;
};
