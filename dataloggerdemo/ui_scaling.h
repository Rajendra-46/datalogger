/********************************************************************************
** Form generated from reading UI file 'scaling.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCALING_H
#define UI_SCALING_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Scaling
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_16;
    QToolButton *toolButton;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QCheckBox *chbx_All_saved_group;
    QPushButton *pushButton;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_NewGroup;
    QComboBox *comboBox_saveGroups;
    QPushButton *pushButton_show;
    QPushButton *pushButton_update;
    QPushButton *pushButton_Delete;
    QPushButton *pushButton_ClearValue;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *m_PshBtn_Save;

    void setupUi(QWidget *Scaling)
    {
        if (Scaling->objectName().isEmpty())
            Scaling->setObjectName(QString::fromUtf8("Scaling"));
        Scaling->resize(1141, 534);
        Scaling->setStyleSheet(QString::fromUtf8("font: 11pt \"MS Shell Dlg 2\";"));
        verticalLayout_2 = new QVBoxLayout(Scaling);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        toolButton = new QToolButton(Scaling);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"border:none;\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/C_logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon);
        toolButton->setIconSize(QSize(16, 16));

        horizontalLayout_16->addWidget(toolButton);

        label = new QLabel(Scaling);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setStyleSheet(QString::fromUtf8("color: rgb(204, 0, 0);"));

        horizontalLayout_16->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer);

        chbx_All_saved_group = new QCheckBox(Scaling);
        chbx_All_saved_group->setObjectName(QString::fromUtf8("chbx_All_saved_group"));
        chbx_All_saved_group->setStyleSheet(QString::fromUtf8("QCheckBox:indicator\n"
"{\n"
"	width  : 20px;\n"
"	height :20px;\n"
"}\n"
"QCheckBox::indicator:unchecked\n"
"{\n"
"	image:url(:/images/unchecked-20x20.png);\n"
"}\n"
"QCheckBox::indicator:checked\n"
"{\n"
"	image:url(:/images/checked-20x20.png);\n"
"}"));

        horizontalLayout_16->addWidget(chbx_All_saved_group);

        pushButton = new QPushButton(Scaling);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(85, 27));
        pushButton->setMaximumSize(QSize(85, 27));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"border: 2px solid red;\n"
"border-width : 2px;\n"
"border-color: rgba(2,169,170,255);\n"
"	color: rgb(255, 255, 255);\n"
"background-color: rgba(2,169,170,255);\n"
"font: 10pt \"Open Sans\";\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	border:1px solid red;\n"
"}\n"
" QPushButton:hover \n"
"{\n"
"     background-color:rgb(255, 255, 255);\n"
"	color: rgb(0, 0, 0);\n"
" }\n"
"QToolTip\n"
"{\n"
"	background-color: rgb(255, 255, 127);\n"
"	color:rgb(0,0,0);\n"
"}\n"
""));

        horizontalLayout_16->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout_16);

        tableWidget = new QTableWidget(Scaling);
        if (tableWidget->columnCount() < 10)
            tableWidget->setColumnCount(10);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setRowCount(0);
        tableWidget->setColumnCount(10);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget->horizontalHeader()->setMinimumSectionSize(50);
        tableWidget->horizontalHeader()->setDefaultSectionSize(153);

        verticalLayout->addWidget(tableWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_NewGroup = new QPushButton(Scaling);
        pushButton_NewGroup->setObjectName(QString::fromUtf8("pushButton_NewGroup"));
        pushButton_NewGroup->setMinimumSize(QSize(120, 30));
        pushButton_NewGroup->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"border: 2px solid red;\n"
"border-width : 2px;\n"
"border-color: rgba(2,169,170,255);\n"
"	color: rgb(255, 255, 255);\n"
"background-color: rgba(2,169,170,255);\n"
"font: 10pt \"Open Sans\";\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	border:1px solid red;\n"
"}\n"
" QPushButton:hover \n"
"{\n"
"     background-color:rgb(255, 255, 255);\n"
"	color: rgb(0, 0, 0);\n"
" }\n"
"QToolTip\n"
"{\n"
"	background-color: rgb(255, 255, 127);\n"
"	color:rgb(0,0,0);\n"
"}\n"
""));

        horizontalLayout->addWidget(pushButton_NewGroup);

        comboBox_saveGroups = new QComboBox(Scaling);
        comboBox_saveGroups->setObjectName(QString::fromUtf8("comboBox_saveGroups"));
        comboBox_saveGroups->setMinimumSize(QSize(167, 30));

        horizontalLayout->addWidget(comboBox_saveGroups);

        pushButton_show = new QPushButton(Scaling);
        pushButton_show->setObjectName(QString::fromUtf8("pushButton_show"));
        pushButton_show->setMinimumSize(QSize(120, 30));
        pushButton_show->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"border: 2px solid red;\n"
"border-width : 2px;\n"
"border-color: rgba(2,169,170,255);\n"
"	color: rgb(255, 255, 255);\n"
"background-color: rgba(2,169,170,255);\n"
"font: 10pt \"Open Sans\";\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	border:1px solid red;\n"
"}\n"
" QPushButton:hover \n"
"{\n"
"     background-color:rgb(255, 255, 255);\n"
"	color: rgb(0, 0, 0);\n"
" }\n"
"QToolTip\n"
"{\n"
"	background-color: rgb(255, 255, 127);\n"
"	color:rgb(0,0,0);\n"
"}\n"
""));

        horizontalLayout->addWidget(pushButton_show);

        pushButton_update = new QPushButton(Scaling);
        pushButton_update->setObjectName(QString::fromUtf8("pushButton_update"));
        pushButton_update->setMinimumSize(QSize(120, 30));
        pushButton_update->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"border: 2px solid red;\n"
"border-width : 2px;\n"
"border-color: rgba(2,169,170,255);\n"
"	color: rgb(255, 255, 255);\n"
"background-color: rgba(2,169,170,255);\n"
"font: 10pt \"Open Sans\";\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	border:1px solid red;\n"
"}\n"
" QPushButton:hover \n"
"{\n"
"     background-color:rgb(255, 255, 255);\n"
"	color: rgb(0, 0, 0);\n"
" }\n"
"QToolTip\n"
"{\n"
"	background-color: rgb(255, 255, 127);\n"
"	color:rgb(0,0,0);\n"
"}\n"
""));

        horizontalLayout->addWidget(pushButton_update);

        pushButton_Delete = new QPushButton(Scaling);
        pushButton_Delete->setObjectName(QString::fromUtf8("pushButton_Delete"));
        pushButton_Delete->setMinimumSize(QSize(120, 30));
        pushButton_Delete->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"border: 2px solid red;\n"
"border-width : 2px;\n"
"border-color: rgba(2,169,170,255);\n"
"	color: rgb(255, 255, 255);\n"
"background-color: rgba(2,169,170,255);\n"
"font: 10pt \"Open Sans\";\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	border:1px solid red;\n"
"}\n"
" QPushButton:hover \n"
"{\n"
"     background-color:rgb(255, 255, 255);\n"
"	color: rgb(0, 0, 0);\n"
" }\n"
"QToolTip\n"
"{\n"
"	background-color: rgb(255, 255, 127);\n"
"	color:rgb(0,0,0);\n"
"}\n"
""));

        horizontalLayout->addWidget(pushButton_Delete);

        pushButton_ClearValue = new QPushButton(Scaling);
        pushButton_ClearValue->setObjectName(QString::fromUtf8("pushButton_ClearValue"));
        pushButton_ClearValue->setMinimumSize(QSize(120, 30));
        pushButton_ClearValue->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"border: 2px solid red;\n"
"border-width : 2px;\n"
"border-color: rgba(2,169,170,255);\n"
"	color: rgb(255, 255, 255);\n"
"background-color: rgba(2,169,170,255);\n"
"font: 10pt \"Open Sans\";\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	border:1px solid red;\n"
"}\n"
" QPushButton:hover \n"
"{\n"
"     background-color:rgb(255, 255, 255);\n"
"	color: rgb(0, 0, 0);\n"
" }\n"
"QToolTip\n"
"{\n"
"	background-color: rgb(255, 255, 127);\n"
"	color:rgb(0,0,0);\n"
"}\n"
""));

        horizontalLayout->addWidget(pushButton_ClearValue);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        m_PshBtn_Save = new QPushButton(Scaling);
        m_PshBtn_Save->setObjectName(QString::fromUtf8("m_PshBtn_Save"));
        m_PshBtn_Save->setMinimumSize(QSize(120, 30));
        m_PshBtn_Save->setMaximumSize(QSize(100, 30));
        m_PshBtn_Save->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"border: 2px solid red;\n"
"border-width : 2px;\n"
"border-color: rgba(2,169,170,255);\n"
"	color: rgb(255, 255, 255);\n"
"background-color: rgba(2,169,170,255);\n"
"font: 10pt \"Open Sans\";\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	border:1px solid red;\n"
"}\n"
" QPushButton:hover \n"
"{\n"
"     background-color:rgb(255, 255, 255);\n"
"	color: rgb(0, 0, 0);\n"
" }\n"
"QToolTip\n"
"{\n"
"	background-color: rgb(255, 255, 127);\n"
"	color:rgb(0,0,0);\n"
"}\n"
""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/save-local.png"), QSize(), QIcon::Normal, QIcon::Off);
        m_PshBtn_Save->setIcon(icon1);

        horizontalLayout->addWidget(m_PshBtn_Save);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(Scaling);

        QMetaObject::connectSlotsByName(Scaling);
    } // setupUi

    void retranslateUi(QWidget *Scaling)
    {
        Scaling->setWindowTitle(QCoreApplication::translate("Scaling", "Form", nullptr));
        toolButton->setText(QCoreApplication::translate("Scaling", "...", nullptr));
        label->setText(QCoreApplication::translate("Scaling", "KONECRANES", nullptr));
        chbx_All_saved_group->setText(QCoreApplication::translate("Scaling", "Show selected", nullptr));
        pushButton->setText(QCoreApplication::translate("Scaling", "Close", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Scaling", "Parameter_name", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Scaling", "Parameter_data_type", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Scaling", "Comment", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("Scaling", "Default Scaling", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("Scaling", "Custom Scaling", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("Scaling", "Default Offset", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("Scaling", "Custom Offset", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("Scaling", "Clear Scaling", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("Scaling", "Clear Offset", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("Scaling", "Select Parameter", nullptr));
        pushButton_NewGroup->setText(QCoreApplication::translate("Scaling", "New Group", nullptr));
        pushButton_show->setText(QCoreApplication::translate("Scaling", "Show", nullptr));
        pushButton_update->setText(QCoreApplication::translate("Scaling", "Update", nullptr));
        pushButton_Delete->setText(QCoreApplication::translate("Scaling", "Delete", nullptr));
        pushButton_ClearValue->setText(QCoreApplication::translate("Scaling", "Reset-All", nullptr));
#if QT_CONFIG(tooltip)
        m_PshBtn_Save->setToolTip(QCoreApplication::translate("Scaling", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Open Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:600;\">Click to Go</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        m_PshBtn_Save->setText(QCoreApplication::translate("Scaling", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Scaling: public Ui_Scaling {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCALING_H
