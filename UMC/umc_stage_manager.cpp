#include "umc_stage_manager.h"

UMCStageManager::UMCStageManager(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	CreateNewLayerButton();
}

UMCStageManager::~UMCStageManager()
{
}

QPushButton* UMCStageManager::CreateNewLayerButton()
{
	QPushButton* button = new QPushButton();
	button->setText(QStringLiteral("增加图层"));
	button->setFixedHeight(UMC_MANAGER_SPRITE_HEIGHT);

	QListWidgetItem* item = new QListWidgetItem;
	QFrame* itemWidget = new QFrame(ui.listWidget);
	QLayout* layout = new QVBoxLayout();

	layout->setMargin(UMC_MANAGER_SPRITE_MARAGER);
	layout->addWidget(button);
	itemWidget->setLayout(layout);
	itemWidget->setFixedHeight(UMC_MANAGER_SPRITE_HEIGHT + 2 * UMC_MANAGER_SPRITE_MARAGER);

	ui.listWidget->addItem(item);
	ui.listWidget->setItemWidget(item, itemWidget);

	QObject::connect(button, &QPushButton::clicked, this, &UMCStageManager::AddSprite);
	return button;
}

void UMCStageManager::AddSprite()
{
	//TODO: 区分类型添加图层
	
}

void UMCStageManager::Load(UMCStageMediator* mediator)
{
	//TODO:还原配置
}
