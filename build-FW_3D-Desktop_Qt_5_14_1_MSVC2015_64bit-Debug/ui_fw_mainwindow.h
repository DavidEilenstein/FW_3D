/********************************************************************************
** Form generated from reading UI file 'fw_mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FW_MAINWINDOW_H
#define UI_FW_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FW_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_BotSettings;
    QGridLayout *gridLayout_4;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QPushButton *pushButton_Restart;
    QPushButton *pushButton_ClearConsole;
    QComboBox *comboBox_Bot_Mode;
    QCheckBox *checkBox_TrippleDefend;
    QSpinBox *spinBox_Bot_Param;
    QCheckBox *checkBox_TrippleAttack;
    QGroupBox *groupBox_FieldControl;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout_FieldControl;
    QPushButton *pushButton_Field_01;
    QPushButton *pushButton_Field_23;
    QPushButton *pushButton_Field_33;
    QPushButton *pushButton_Field_03;
    QPushButton *pushButton_Field_13;
    QPushButton *pushButton_Field_02;
    QPushButton *pushButton_Field_00;
    QPushButton *pushButton_Field_12;
    QPushButton *pushButton_Field_22;
    QPushButton *pushButton_Field_32;
    QPushButton *pushButton_Field_11;
    QPushButton *pushButton_Field_21;
    QPushButton *pushButton_Field_31;
    QPushButton *pushButton_Field_10;
    QPushButton *pushButton_Field_20;
    QPushButton *pushButton_Field_30;
    QPlainTextEdit *plainTextEdit_Output;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *FW_MainWindow)
    {
        if (FW_MainWindow->objectName().isEmpty())
            FW_MainWindow->setObjectName(QString::fromUtf8("FW_MainWindow"));
        FW_MainWindow->resize(536, 777);
        centralwidget = new QWidget(FW_MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox_BotSettings = new QGroupBox(centralwidget);
        groupBox_BotSettings->setObjectName(QString::fromUtf8("groupBox_BotSettings"));
        groupBox_BotSettings->setMinimumSize(QSize(0, 250));
        groupBox_BotSettings->setMaximumSize(QSize(16777215, 250));
        gridLayout_4 = new QGridLayout(groupBox_BotSettings);
        gridLayout_4->setSpacing(3);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(3, 3, 3, 3);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer, 6, 0, 1, 1);

        label = new QLabel(groupBox_BotSettings);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_4->addWidget(label, 0, 0, 1, 1);

        pushButton_Restart = new QPushButton(groupBox_BotSettings);
        pushButton_Restart->setObjectName(QString::fromUtf8("pushButton_Restart"));

        gridLayout_4->addWidget(pushButton_Restart, 7, 0, 1, 1);

        pushButton_ClearConsole = new QPushButton(groupBox_BotSettings);
        pushButton_ClearConsole->setObjectName(QString::fromUtf8("pushButton_ClearConsole"));

        gridLayout_4->addWidget(pushButton_ClearConsole, 8, 0, 1, 1);

        comboBox_Bot_Mode = new QComboBox(groupBox_BotSettings);
        comboBox_Bot_Mode->setObjectName(QString::fromUtf8("comboBox_Bot_Mode"));

        gridLayout_4->addWidget(comboBox_Bot_Mode, 1, 0, 1, 1);

        checkBox_TrippleDefend = new QCheckBox(groupBox_BotSettings);
        checkBox_TrippleDefend->setObjectName(QString::fromUtf8("checkBox_TrippleDefend"));
        checkBox_TrippleDefend->setChecked(true);

        gridLayout_4->addWidget(checkBox_TrippleDefend, 4, 0, 1, 1);

        spinBox_Bot_Param = new QSpinBox(groupBox_BotSettings);
        spinBox_Bot_Param->setObjectName(QString::fromUtf8("spinBox_Bot_Param"));
        spinBox_Bot_Param->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_Bot_Param->setMinimum(1);
        spinBox_Bot_Param->setMaximum(15);
        spinBox_Bot_Param->setValue(5);

        gridLayout_4->addWidget(spinBox_Bot_Param, 2, 0, 1, 1);

        checkBox_TrippleAttack = new QCheckBox(groupBox_BotSettings);
        checkBox_TrippleAttack->setObjectName(QString::fromUtf8("checkBox_TrippleAttack"));
        checkBox_TrippleAttack->setChecked(true);

        gridLayout_4->addWidget(checkBox_TrippleAttack, 3, 0, 1, 1);


        gridLayout->addWidget(groupBox_BotSettings, 0, 1, 1, 1);

        groupBox_FieldControl = new QGroupBox(centralwidget);
        groupBox_FieldControl->setObjectName(QString::fromUtf8("groupBox_FieldControl"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_FieldControl->sizePolicy().hasHeightForWidth());
        groupBox_FieldControl->setSizePolicy(sizePolicy);
        groupBox_FieldControl->setMinimumSize(QSize(250, 250));
        groupBox_FieldControl->setMaximumSize(QSize(250, 250));
        gridLayout_2 = new QGridLayout(groupBox_FieldControl);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_FieldControl = new QGridLayout();
        gridLayout_FieldControl->setObjectName(QString::fromUtf8("gridLayout_FieldControl"));
        pushButton_Field_01 = new QPushButton(groupBox_FieldControl);
        pushButton_Field_01->setObjectName(QString::fromUtf8("pushButton_Field_01"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_Field_01->sizePolicy().hasHeightForWidth());
        pushButton_Field_01->setSizePolicy(sizePolicy1);
        pushButton_Field_01->setFlat(false);

        gridLayout_FieldControl->addWidget(pushButton_Field_01, 2, 0, 1, 1);

        pushButton_Field_23 = new QPushButton(groupBox_FieldControl);
        pushButton_Field_23->setObjectName(QString::fromUtf8("pushButton_Field_23"));
        sizePolicy1.setHeightForWidth(pushButton_Field_23->sizePolicy().hasHeightForWidth());
        pushButton_Field_23->setSizePolicy(sizePolicy1);
        pushButton_Field_23->setFlat(false);

        gridLayout_FieldControl->addWidget(pushButton_Field_23, 0, 2, 1, 1);

        pushButton_Field_33 = new QPushButton(groupBox_FieldControl);
        pushButton_Field_33->setObjectName(QString::fromUtf8("pushButton_Field_33"));
        sizePolicy1.setHeightForWidth(pushButton_Field_33->sizePolicy().hasHeightForWidth());
        pushButton_Field_33->setSizePolicy(sizePolicy1);
        pushButton_Field_33->setFlat(false);

        gridLayout_FieldControl->addWidget(pushButton_Field_33, 0, 3, 1, 1);

        pushButton_Field_03 = new QPushButton(groupBox_FieldControl);
        pushButton_Field_03->setObjectName(QString::fromUtf8("pushButton_Field_03"));
        sizePolicy1.setHeightForWidth(pushButton_Field_03->sizePolicy().hasHeightForWidth());
        pushButton_Field_03->setSizePolicy(sizePolicy1);
        pushButton_Field_03->setStyleSheet(QString::fromUtf8(""));
        pushButton_Field_03->setFlat(false);

        gridLayout_FieldControl->addWidget(pushButton_Field_03, 0, 0, 1, 1);

        pushButton_Field_13 = new QPushButton(groupBox_FieldControl);
        pushButton_Field_13->setObjectName(QString::fromUtf8("pushButton_Field_13"));
        sizePolicy1.setHeightForWidth(pushButton_Field_13->sizePolicy().hasHeightForWidth());
        pushButton_Field_13->setSizePolicy(sizePolicy1);
        pushButton_Field_13->setFlat(false);

        gridLayout_FieldControl->addWidget(pushButton_Field_13, 0, 1, 1, 1);

        pushButton_Field_02 = new QPushButton(groupBox_FieldControl);
        pushButton_Field_02->setObjectName(QString::fromUtf8("pushButton_Field_02"));
        sizePolicy1.setHeightForWidth(pushButton_Field_02->sizePolicy().hasHeightForWidth());
        pushButton_Field_02->setSizePolicy(sizePolicy1);
        pushButton_Field_02->setFlat(false);

        gridLayout_FieldControl->addWidget(pushButton_Field_02, 1, 0, 1, 1);

        pushButton_Field_00 = new QPushButton(groupBox_FieldControl);
        pushButton_Field_00->setObjectName(QString::fromUtf8("pushButton_Field_00"));
        sizePolicy1.setHeightForWidth(pushButton_Field_00->sizePolicy().hasHeightForWidth());
        pushButton_Field_00->setSizePolicy(sizePolicy1);
        pushButton_Field_00->setFlat(false);

        gridLayout_FieldControl->addWidget(pushButton_Field_00, 3, 0, 1, 1);

        pushButton_Field_12 = new QPushButton(groupBox_FieldControl);
        pushButton_Field_12->setObjectName(QString::fromUtf8("pushButton_Field_12"));
        sizePolicy1.setHeightForWidth(pushButton_Field_12->sizePolicy().hasHeightForWidth());
        pushButton_Field_12->setSizePolicy(sizePolicy1);
        pushButton_Field_12->setFlat(false);

        gridLayout_FieldControl->addWidget(pushButton_Field_12, 1, 1, 1, 1);

        pushButton_Field_22 = new QPushButton(groupBox_FieldControl);
        pushButton_Field_22->setObjectName(QString::fromUtf8("pushButton_Field_22"));
        sizePolicy1.setHeightForWidth(pushButton_Field_22->sizePolicy().hasHeightForWidth());
        pushButton_Field_22->setSizePolicy(sizePolicy1);
        pushButton_Field_22->setFlat(false);

        gridLayout_FieldControl->addWidget(pushButton_Field_22, 1, 2, 1, 1);

        pushButton_Field_32 = new QPushButton(groupBox_FieldControl);
        pushButton_Field_32->setObjectName(QString::fromUtf8("pushButton_Field_32"));
        sizePolicy1.setHeightForWidth(pushButton_Field_32->sizePolicy().hasHeightForWidth());
        pushButton_Field_32->setSizePolicy(sizePolicy1);
        pushButton_Field_32->setFlat(false);

        gridLayout_FieldControl->addWidget(pushButton_Field_32, 1, 3, 1, 1);

        pushButton_Field_11 = new QPushButton(groupBox_FieldControl);
        pushButton_Field_11->setObjectName(QString::fromUtf8("pushButton_Field_11"));
        sizePolicy1.setHeightForWidth(pushButton_Field_11->sizePolicy().hasHeightForWidth());
        pushButton_Field_11->setSizePolicy(sizePolicy1);
        pushButton_Field_11->setFlat(false);

        gridLayout_FieldControl->addWidget(pushButton_Field_11, 2, 1, 1, 1);

        pushButton_Field_21 = new QPushButton(groupBox_FieldControl);
        pushButton_Field_21->setObjectName(QString::fromUtf8("pushButton_Field_21"));
        sizePolicy1.setHeightForWidth(pushButton_Field_21->sizePolicy().hasHeightForWidth());
        pushButton_Field_21->setSizePolicy(sizePolicy1);
        pushButton_Field_21->setFlat(false);

        gridLayout_FieldControl->addWidget(pushButton_Field_21, 2, 2, 1, 1);

        pushButton_Field_31 = new QPushButton(groupBox_FieldControl);
        pushButton_Field_31->setObjectName(QString::fromUtf8("pushButton_Field_31"));
        sizePolicy1.setHeightForWidth(pushButton_Field_31->sizePolicy().hasHeightForWidth());
        pushButton_Field_31->setSizePolicy(sizePolicy1);
        pushButton_Field_31->setFlat(false);

        gridLayout_FieldControl->addWidget(pushButton_Field_31, 2, 3, 1, 1);

        pushButton_Field_10 = new QPushButton(groupBox_FieldControl);
        pushButton_Field_10->setObjectName(QString::fromUtf8("pushButton_Field_10"));
        sizePolicy1.setHeightForWidth(pushButton_Field_10->sizePolicy().hasHeightForWidth());
        pushButton_Field_10->setSizePolicy(sizePolicy1);
        pushButton_Field_10->setFlat(false);

        gridLayout_FieldControl->addWidget(pushButton_Field_10, 3, 1, 1, 1);

        pushButton_Field_20 = new QPushButton(groupBox_FieldControl);
        pushButton_Field_20->setObjectName(QString::fromUtf8("pushButton_Field_20"));
        sizePolicy1.setHeightForWidth(pushButton_Field_20->sizePolicy().hasHeightForWidth());
        pushButton_Field_20->setSizePolicy(sizePolicy1);
        pushButton_Field_20->setFlat(false);

        gridLayout_FieldControl->addWidget(pushButton_Field_20, 3, 2, 1, 1);

        pushButton_Field_30 = new QPushButton(groupBox_FieldControl);
        pushButton_Field_30->setObjectName(QString::fromUtf8("pushButton_Field_30"));
        sizePolicy1.setHeightForWidth(pushButton_Field_30->sizePolicy().hasHeightForWidth());
        pushButton_Field_30->setSizePolicy(sizePolicy1);
        pushButton_Field_30->setFlat(false);

        gridLayout_FieldControl->addWidget(pushButton_Field_30, 3, 3, 1, 1);


        gridLayout_2->addLayout(gridLayout_FieldControl, 3, 3, 1, 1);


        gridLayout->addWidget(groupBox_FieldControl, 0, 0, 1, 1);

        plainTextEdit_Output = new QPlainTextEdit(centralwidget);
        plainTextEdit_Output->setObjectName(QString::fromUtf8("plainTextEdit_Output"));

        gridLayout->addWidget(plainTextEdit_Output, 2, 0, 1, 2);

        FW_MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(FW_MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 536, 21));
        FW_MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(FW_MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        FW_MainWindow->setStatusBar(statusbar);

        retranslateUi(FW_MainWindow);

        QMetaObject::connectSlotsByName(FW_MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *FW_MainWindow)
    {
        FW_MainWindow->setWindowTitle(QCoreApplication::translate("FW_MainWindow", "FW_MainWindow", nullptr));
        groupBox_BotSettings->setTitle(QCoreApplication::translate("FW_MainWindow", "Settings", nullptr));
        label->setText(QCoreApplication::translate("FW_MainWindow", "Bot mode:", nullptr));
        pushButton_Restart->setText(QCoreApplication::translate("FW_MainWindow", "Restart game", nullptr));
        pushButton_ClearConsole->setText(QCoreApplication::translate("FW_MainWindow", "Clear console", nullptr));
        checkBox_TrippleDefend->setText(QCoreApplication::translate("FW_MainWindow", "Defend obvious tripples", nullptr));
        spinBox_Bot_Param->setPrefix(QCoreApplication::translate("FW_MainWindow", "depth=", nullptr));
        checkBox_TrippleAttack->setText(QCoreApplication::translate("FW_MainWindow", "Finish obvious tripples", nullptr));
        groupBox_FieldControl->setTitle(QCoreApplication::translate("FW_MainWindow", "Field control", nullptr));
        pushButton_Field_01->setText(QCoreApplication::translate("FW_MainWindow", "0 / 1", nullptr));
        pushButton_Field_23->setText(QCoreApplication::translate("FW_MainWindow", "2 / 3", nullptr));
        pushButton_Field_33->setText(QCoreApplication::translate("FW_MainWindow", "3 / 3", nullptr));
        pushButton_Field_03->setText(QCoreApplication::translate("FW_MainWindow", "0 / 3", nullptr));
        pushButton_Field_13->setText(QCoreApplication::translate("FW_MainWindow", "1 / 3", nullptr));
        pushButton_Field_02->setText(QCoreApplication::translate("FW_MainWindow", "0 / 2", nullptr));
        pushButton_Field_00->setText(QCoreApplication::translate("FW_MainWindow", "0 / 0", nullptr));
        pushButton_Field_12->setText(QCoreApplication::translate("FW_MainWindow", "1 / 2", nullptr));
        pushButton_Field_22->setText(QCoreApplication::translate("FW_MainWindow", "2 / 2", nullptr));
        pushButton_Field_32->setText(QCoreApplication::translate("FW_MainWindow", "3 / 2", nullptr));
        pushButton_Field_11->setText(QCoreApplication::translate("FW_MainWindow", "1 / 1", nullptr));
        pushButton_Field_21->setText(QCoreApplication::translate("FW_MainWindow", "2 / 1", nullptr));
        pushButton_Field_31->setText(QCoreApplication::translate("FW_MainWindow", "3 / 1", nullptr));
        pushButton_Field_10->setText(QCoreApplication::translate("FW_MainWindow", "1 / 0", nullptr));
        pushButton_Field_20->setText(QCoreApplication::translate("FW_MainWindow", "2 / 0", nullptr));
        pushButton_Field_30->setText(QCoreApplication::translate("FW_MainWindow", "3 / 0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FW_MainWindow: public Ui_FW_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FW_MAINWINDOW_H
