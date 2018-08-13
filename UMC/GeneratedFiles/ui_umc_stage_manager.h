/********************************************************************************
** Form generated from reading UI file 'umc_stage_manager.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UMC_STAGE_MANAGER_H
#define UI_UMC_STAGE_MANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UMCStageManager
{
public:
    QHBoxLayout *horizontalLayout;
    QListWidget *listWidget;

    void setupUi(QWidget *UMCStageManager)
    {
        if (UMCStageManager->objectName().isEmpty())
            UMCStageManager->setObjectName(QStringLiteral("UMCStageManager"));
        UMCStageManager->resize(207, 691);
        UMCStageManager->setStyleSheet(QStringLiteral(""));
        horizontalLayout = new QHBoxLayout(UMCStageManager);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        listWidget = new QListWidget(UMCStageManager);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        horizontalLayout->addWidget(listWidget);


        retranslateUi(UMCStageManager);

        QMetaObject::connectSlotsByName(UMCStageManager);
    } // setupUi

    void retranslateUi(QWidget *UMCStageManager)
    {
        UMCStageManager->setWindowTitle(QApplication::translate("UMCStageManager", "UMCLayerManager", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class UMCStageManager: public Ui_UMCStageManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UMC_STAGE_MANAGER_H
