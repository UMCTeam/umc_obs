/********************************************************************************
** Form generated from reading UI file 'umc_stage.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UMC_STAGE_H
#define UI_UMC_STAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UMCStage
{
public:

    void setupUi(QWidget *UMCStage)
    {
        if (UMCStage->objectName().isEmpty())
            UMCStage->setObjectName(QStringLiteral("UMCStage"));
        UMCStage->resize(400, 300);

        retranslateUi(UMCStage);

        QMetaObject::connectSlotsByName(UMCStage);
    } // setupUi

    void retranslateUi(QWidget *UMCStage)
    {
        UMCStage->setWindowTitle(QApplication::translate("UMCStage", "UMCCanvas", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class UMCStage: public Ui_UMCStage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UMC_STAGE_H
