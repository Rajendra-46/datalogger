/********************************************************************************
** Form generated from reading UI file 'exportcsv.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPORTCSV_H
#define UI_EXPORTCSV_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_exportcsv
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_16;
    QToolButton *toolButton;
    QLabel *label;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QDateTimeEdit *TimeStamp_StartTime;
    QSpacerItem *horizontalSpacer_2;
    QTimeEdit *timeEdit_Start;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_6;
    QDateTimeEdit *TimeStamp_EndTime;
    QSpacerItem *horizontalSpacer_4;
    QTimeEdit *timeEdit_End;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout;
    QProgressBar *progressBar;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *m_PshBtn_GetData;
    QSpacerItem *horizontalSpacer_9;

    void setupUi(QWidget *exportcsv)
    {
        if (exportcsv->objectName().isEmpty())
            exportcsv->setObjectName(QString::fromUtf8("exportcsv"));
        exportcsv->resize(406, 235);
        QFont font;
        font.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font.setPointSize(11);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        exportcsv->setFont(font);
        exportcsv->setStyleSheet(QString::fromUtf8("font: 11pt \"MS Shell Dlg 2\";"));
        verticalLayout_3 = new QVBoxLayout(exportcsv);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        toolButton = new QToolButton(exportcsv);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"border:none;\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/C_logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon);
        toolButton->setIconSize(QSize(16, 16));

        horizontalLayout_16->addWidget(toolButton);

        label = new QLabel(exportcsv);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setStyleSheet(QString::fromUtf8("color: rgb(204, 0, 0);"));

        horizontalLayout_16->addWidget(label);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer_5);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer);

        pushButton = new QPushButton(exportcsv);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(85, 26));
        pushButton->setMaximumSize(QSize(85, 26));
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


        verticalLayout_2->addLayout(horizontalLayout_16);

        frame = new QFrame(exportcsv);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        frame->setStyleSheet(QString::fromUtf8(""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        TimeStamp_StartTime = new QDateTimeEdit(frame);
        TimeStamp_StartTime->setObjectName(QString::fromUtf8("TimeStamp_StartTime"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(TimeStamp_StartTime->sizePolicy().hasHeightForWidth());
        TimeStamp_StartTime->setSizePolicy(sizePolicy2);
        TimeStamp_StartTime->setMinimumSize(QSize(145, 35));
        TimeStamp_StartTime->setFont(font);
        TimeStamp_StartTime->setStyleSheet(QString::fromUtf8("background-color: rgb(212, 212, 212);\n"
"\n"
""));
        TimeStamp_StartTime->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        TimeStamp_StartTime->setCurrentSection(QDateTimeEdit::DaySection);
        TimeStamp_StartTime->setCalendarPopup(true);

        horizontalLayout_3->addWidget(TimeStamp_StartTime);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        timeEdit_Start = new QTimeEdit(frame);
        timeEdit_Start->setObjectName(QString::fromUtf8("timeEdit_Start"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(timeEdit_Start->sizePolicy().hasHeightForWidth());
        timeEdit_Start->setSizePolicy(sizePolicy3);
        timeEdit_Start->setMinimumSize(QSize(130, 35));
        timeEdit_Start->setMaximumSize(QSize(130, 16777215));
        timeEdit_Start->setFont(font);
        timeEdit_Start->setStyleSheet(QString::fromUtf8("background-color: rgb(212, 212, 212);\n"
"font: 11pt \"MS Shell Dlg 2\";\n"
"\n"
""));
        timeEdit_Start->setCalendarPopup(true);

        horizontalLayout_3->addWidget(timeEdit_Start);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(2);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_6 = new QLabel(frame);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_7->addWidget(label_6);

        TimeStamp_EndTime = new QDateTimeEdit(frame);
        TimeStamp_EndTime->setObjectName(QString::fromUtf8("TimeStamp_EndTime"));
        sizePolicy2.setHeightForWidth(TimeStamp_EndTime->sizePolicy().hasHeightForWidth());
        TimeStamp_EndTime->setSizePolicy(sizePolicy2);
        TimeStamp_EndTime->setMinimumSize(QSize(145, 35));
        TimeStamp_EndTime->setFont(font);
        TimeStamp_EndTime->setStyleSheet(QString::fromUtf8("background-color: rgb(212, 212, 212);\n"
"\n"
""));
        TimeStamp_EndTime->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        TimeStamp_EndTime->setCurrentSection(QDateTimeEdit::DaySection);
        TimeStamp_EndTime->setCalendarPopup(true);

        horizontalLayout_7->addWidget(TimeStamp_EndTime);

        horizontalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_4);

        timeEdit_End = new QTimeEdit(frame);
        timeEdit_End->setObjectName(QString::fromUtf8("timeEdit_End"));
        sizePolicy3.setHeightForWidth(timeEdit_End->sizePolicy().hasHeightForWidth());
        timeEdit_End->setSizePolicy(sizePolicy3);
        timeEdit_End->setMinimumSize(QSize(130, 35));
        timeEdit_End->setMaximumSize(QSize(130, 16777215));
        timeEdit_End->setFont(font);
        timeEdit_End->setStyleSheet(QString::fromUtf8("background-color: rgb(212, 212, 212);\n"
"font: 11pt \"MS Shell Dlg 2\";\n"
"\n"
""));
        timeEdit_End->setCalendarPopup(true);

        horizontalLayout_7->addWidget(timeEdit_End);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_7);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        progressBar = new QProgressBar(frame);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setMinimumSize(QSize(344, 35));
        progressBar->setMaximum(100);
        progressBar->setValue(0);

        horizontalLayout->addWidget(progressBar);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(5);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(199, -1, 0, -1);
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        m_PshBtn_GetData = new QPushButton(frame);
        m_PshBtn_GetData->setObjectName(QString::fromUtf8("m_PshBtn_GetData"));
        m_PshBtn_GetData->setMinimumSize(QSize(120, 30));
        m_PshBtn_GetData->setMaximumSize(QSize(100, 30));
        m_PshBtn_GetData->setStyleSheet(QString::fromUtf8("QPushButton\n"
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
        m_PshBtn_GetData->setIcon(icon1);

        horizontalLayout_4->addWidget(m_PshBtn_GetData);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_9);


        verticalLayout->addLayout(horizontalLayout_4);


        verticalLayout_2->addWidget(frame);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(exportcsv);

        QMetaObject::connectSlotsByName(exportcsv);
    } // setupUi

    void retranslateUi(QWidget *exportcsv)
    {
        exportcsv->setWindowTitle(QCoreApplication::translate("exportcsv", "Form", nullptr));
        toolButton->setText(QCoreApplication::translate("exportcsv", "...", nullptr));
        label->setText(QCoreApplication::translate("exportcsv", "KONECRANES", nullptr));
        pushButton->setText(QCoreApplication::translate("exportcsv", "Close", nullptr));
        label_4->setText(QCoreApplication::translate("exportcsv", "Start Time", nullptr));
        TimeStamp_StartTime->setDisplayFormat(QCoreApplication::translate("exportcsv", "dd MMM yy", nullptr));
        timeEdit_Start->setDisplayFormat(QCoreApplication::translate("exportcsv", "hh:mm:ss.zzz", nullptr));
        label_6->setText(QCoreApplication::translate("exportcsv", "End Time ", nullptr));
        TimeStamp_EndTime->setDisplayFormat(QCoreApplication::translate("exportcsv", "dd MMM yy", nullptr));
        timeEdit_End->setDisplayFormat(QCoreApplication::translate("exportcsv", "hh:mm:ss.zzz", nullptr));
        progressBar->setFormat(QCoreApplication::translate("exportcsv", "%p.00 %", nullptr));
#if QT_CONFIG(tooltip)
        m_PshBtn_GetData->setToolTip(QCoreApplication::translate("exportcsv", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Open Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:600;\">Click to Go</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        m_PshBtn_GetData->setText(QCoreApplication::translate("exportcsv", "Submit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class exportcsv: public Ui_exportcsv {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPORTCSV_H
