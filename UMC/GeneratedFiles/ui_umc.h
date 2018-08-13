/********************************************************************************
** Form generated from reading UI file 'umc.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UMC_H
#define UI_UMC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <umc_Stage_manager.h>
#include <umc_stage.h>

QT_BEGIN_NAMESPACE

class Ui_UMCClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QWidget *aside_left;
    QVBoxLayout *verticalLayout_4;
    UMCStageManager *stage_manager;
    QHBoxLayout *horizontalLayout_4;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QWidget *Widget;
    QVBoxLayout *verticalLayout;
    QWidget *stage_background;
    QVBoxLayout *verticalLayout_2;
    UMCStage *stage;
    QWidget *tool;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QWidget *aside_right;
    QVBoxLayout *verticalLayout_3;
    QWidget *danmu;
    QHBoxLayout *horizontalLayout_5;
    QListView *listView_2;
    QWidget *userCenter;
    QHBoxLayout *horizontalLayout_6;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label;
    QWidget *widget_4;

    void setupUi(QMainWindow *UMCClass)
    {
        if (UMCClass->objectName().isEmpty())
            UMCClass->setObjectName(QStringLiteral("UMCClass"));
        UMCClass->resize(1100, 650);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(UMCClass->sizePolicy().hasHeightForWidth());
        UMCClass->setSizePolicy(sizePolicy);
        UMCClass->setMinimumSize(QSize(1100, 650));
        UMCClass->setMaximumSize(QSize(1100, 650));
        UMCClass->setStyleSheet(QLatin1String("#centralWidget {\n"
" color: #2e2e2e;\n"
"}\n"
"\n"
"#aside_left {\n"
"  background-color: #fafafa;\n"
"  border-right: 2px solid  #e5e5e5;\n"
"}\n"
"\n"
"#aside_right {\n"
"  background-color: #fafafa;\n"
"  border-left: 2px solid  #e5e5e5;\n"
"}\n"
"\n"
"#stage_background {\n"
"  background-color: rgba(76, 76, 76, 1)\n"
"}\n"
"\n"
"#tool {\n"
"  background-color: #fafafa;\n"
"}\n"
""));
        centralWidget = new QWidget(UMCClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        aside_left = new QWidget(centralWidget);
        aside_left->setObjectName(QStringLiteral("aside_left"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(aside_left->sizePolicy().hasHeightForWidth());
        aside_left->setSizePolicy(sizePolicy1);
        aside_left->setMaximumSize(QSize(180, 16777215));
        verticalLayout_4 = new QVBoxLayout(aside_left);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        stage_manager = new UMCStageManager(aside_left);
        stage_manager->setObjectName(QStringLiteral("stage_manager"));
        horizontalLayout_4 = new QHBoxLayout(stage_manager);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));

        verticalLayout_4->addWidget(stage_manager);

        widget = new QWidget(aside_left);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(0, 30));
        widget->setMaximumSize(QSize(16777215, 30));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_3->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout_3->addWidget(pushButton_3);


        verticalLayout_4->addWidget(widget);


        horizontalLayout->addWidget(aside_left);

        Widget = new QWidget(centralWidget);
        Widget->setObjectName(QStringLiteral("Widget"));
        verticalLayout = new QVBoxLayout(Widget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        stage_background = new QWidget(Widget);
        stage_background->setObjectName(QStringLiteral("stage_background"));
        sizePolicy.setHeightForWidth(stage_background->sizePolicy().hasHeightForWidth());
        stage_background->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(stage_background);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        stage = new UMCStage(stage_background);
        stage->setObjectName(QStringLiteral("stage"));

        verticalLayout_2->addWidget(stage);


        verticalLayout->addWidget(stage_background);

        tool = new QWidget(Widget);
        tool->setObjectName(QStringLiteral("tool"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tool->sizePolicy().hasHeightForWidth());
        tool->setSizePolicy(sizePolicy2);
        tool->setMinimumSize(QSize(0, 200));
        tool->setMaximumSize(QSize(16777215, 200));
        horizontalLayout_2 = new QHBoxLayout(tool);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton = new QPushButton(tool);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy3);
        pushButton->setMinimumSize(QSize(150, 50));
        pushButton->setMaximumSize(QSize(150, 50));

        horizontalLayout_2->addWidget(pushButton);


        verticalLayout->addWidget(tool);


        horizontalLayout->addWidget(Widget);

        aside_right = new QWidget(centralWidget);
        aside_right->setObjectName(QStringLiteral("aside_right"));
        sizePolicy1.setHeightForWidth(aside_right->sizePolicy().hasHeightForWidth());
        aside_right->setSizePolicy(sizePolicy1);
        aside_right->setMaximumSize(QSize(280, 16777215));
        verticalLayout_3 = new QVBoxLayout(aside_right);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        danmu = new QWidget(aside_right);
        danmu->setObjectName(QStringLiteral("danmu"));
        horizontalLayout_5 = new QHBoxLayout(danmu);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        listView_2 = new QListView(danmu);
        listView_2->setObjectName(QStringLiteral("listView_2"));

        horizontalLayout_5->addWidget(listView_2);


        verticalLayout_3->addWidget(danmu);

        userCenter = new QWidget(aside_right);
        userCenter->setObjectName(QStringLiteral("userCenter"));
        sizePolicy2.setHeightForWidth(userCenter->sizePolicy().hasHeightForWidth());
        userCenter->setSizePolicy(sizePolicy2);
        userCenter->setMinimumSize(QSize(0, 120));
        userCenter->setMaximumSize(QSize(16777215, 120));
        horizontalLayout_6 = new QHBoxLayout(userCenter);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        widget_3 = new QWidget(userCenter);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        horizontalLayout_7 = new QHBoxLayout(widget_3);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label = new QLabel(widget_3);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_7->addWidget(label);


        horizontalLayout_6->addWidget(widget_3);

        widget_4 = new QWidget(userCenter);
        widget_4->setObjectName(QStringLiteral("widget_4"));

        horizontalLayout_6->addWidget(widget_4);


        verticalLayout_3->addWidget(userCenter);


        horizontalLayout->addWidget(aside_right);

        UMCClass->setCentralWidget(centralWidget);

        retranslateUi(UMCClass);

        QMetaObject::connectSlotsByName(UMCClass);
    } // setupUi

    void retranslateUi(QMainWindow *UMCClass)
    {
        UMCClass->setWindowTitle(QApplication::translate("UMCClass", "UMC", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("UMCClass", "\344\270\212\347\247\273", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("UMCClass", "\344\270\213\347\247\273", Q_NULLPTR));
        pushButton->setText(QApplication::translate("UMCClass", "\345\274\200\345\247\213\347\233\264\346\222\255", Q_NULLPTR));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class UMCClass: public Ui_UMCClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UMC_H
