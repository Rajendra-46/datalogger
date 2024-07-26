/********************************************************************************
** Form generated from reading UI file 'about.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_about
{
public:
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QTabWidget *tabWidget;
    QWidget *About;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *m_PshBtn_DBMatrics;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *m_PshBtn_FetchDayWiseCont;
    QWidget *Versions;
    QVBoxLayout *verticalLayout_4;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QLabel *m_csLnScoutparameters;
    QHBoxLayout *m_HLayoutDetectionDis_3;
    QLabel *m_csLnDetectionDistce_3;
    QLabel *pc_Vnum;
    QHBoxLayout *m_HLayoutSpacingFactor_3;
    QLabel *m_csLnSpacingFactor_3;
    QLabel *pc_Date;
    QHBoxLayout *m_HLayoutNoofsonobuys_3;
    QLabel *m_csLnNoofsonobuys_3;
    QTextEdit *pc_Rnote;
    QLabel *m_csLnSensorParameters;
    QHBoxLayout *m_HLayoutDetectionDis;
    QLabel *m_csLnDetectionDistce;
    QLabel *adc_Vnum;
    QHBoxLayout *m_HLayoutSpacingFactor;
    QLabel *m_csLnSpacingFactor;
    QLabel *adc_Date;
    QHBoxLayout *m_HLayoutNoofsonobuys;
    QLabel *m_csLnNoofsonobuys;
    QTextEdit *adc_Rnote;
    QLabel *m_csLnDatumParameters;
    QHBoxLayout *m_HLayoutDetectionDis_4;
    QLabel *m_csLnDetectionDistce_4;
    QLabel *s_Vnum;
    QHBoxLayout *m_HLayoutSpacingFactor_4;
    QLabel *m_csLnSpacingFactor_4;
    QLabel *s_Date;
    QHBoxLayout *m_HLayoutNoofsonobuys_4;
    QLabel *m_csLnNoofsonobuys_4;
    QTextEdit *s_Rnote;
    QLabel *m_csLnDatumParameters_2;
    QHBoxLayout *m_HLayoutDetectionDis_5;
    QLabel *m_csLnDetectionDistce_5;
    QLabel *kpi_Vnum;
    QHBoxLayout *m_HLayoutSpacingFactor_5;
    QLabel *m_csLnSpacingFactor_5;
    QLabel *kpi_Date;
    QHBoxLayout *m_HLayoutNoofsonobuys_5;
    QLabel *m_csLnNoofsonobuys_5;
    QTextEdit *kpi_Rnote;
    QLabel *m_csLnDatumParameters_3;
    QHBoxLayout *m_HLayoutDetectionDis_6;
    QLabel *m_csLnDetectionDistce_6;
    QLabel *kpicron_Vnum;
    QHBoxLayout *m_HLayoutSpacingFactor_6;
    QLabel *m_csLnSpacingFactor_6;
    QLabel *kpicron_Date;
    QHBoxLayout *m_HLayoutNoofsonobuys_6;
    QLabel *m_csLnNoofsonobuys_6;
    QTextEdit *kpicron_Rnote;
    QLabel *m_csLnDatumParameters_4;
    QHBoxLayout *m_HLayoutDetectionDis_7;
    QLabel *m_csLnDetectionDistce_7;
    QLabel *cs_Vnum;
    QHBoxLayout *m_HLayoutSpacingFactor_7;
    QLabel *m_csLnSpacingFactor_7;
    QLabel *cs_Date;
    QHBoxLayout *m_HLayoutNoofsonobuys_7;
    QLabel *m_csLnNoofsonobuys_7;
    QTextEdit *cs_Rnote;
    QWidget *QuickGuide;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *m_PshBtn_quickGuide;
    QSpacerItem *horizontalSpacer_2;
    QTextEdit *textEdit_2;

    void setupUi(QWidget *about)
    {
        if (about->objectName().isEmpty())
            about->setObjectName(QString::fromUtf8("about"));
        about->resize(425, 692);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(about->sizePolicy().hasHeightForWidth());
        about->setSizePolicy(sizePolicy);
        about->setMinimumSize(QSize(425, 692));
        about->setMaximumSize(QSize(425, 693));
        about->setStyleSheet(QString::fromUtf8("\n"
"QWidget\n"
"{\n"
"	font: 11pt ;\n"
"   background-color: rgb(212, 212, 212);\n"
"}"));
        verticalLayout_5 = new QVBoxLayout(about);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(4, -1, -1, -1);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(about);
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
"QPushButton:disabled {\n"
"background-color:rgb(211, 215, 207);\n"
"}\n"
""));

        horizontalLayout->addWidget(pushButton);


        verticalLayout_3->addLayout(horizontalLayout);

        tabWidget = new QTabWidget(about);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setMinimumSize(QSize(414, 0));
        tabWidget->setStyleSheet(QString::fromUtf8("font: 11pt ;"));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        About = new QWidget();
        About->setObjectName(QString::fromUtf8("About"));
        verticalLayout_6 = new QVBoxLayout(About);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        textEdit = new QTextEdit(About);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setReadOnly(true);

        verticalLayout->addWidget(textEdit);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        m_PshBtn_DBMatrics = new QPushButton(About);
        m_PshBtn_DBMatrics->setObjectName(QString::fromUtf8("m_PshBtn_DBMatrics"));
        m_PshBtn_DBMatrics->setMinimumSize(QSize(150, 30));
        m_PshBtn_DBMatrics->setMaximumSize(QSize(150, 30));
        m_PshBtn_DBMatrics->setStyleSheet(QString::fromUtf8("QPushButton\n"
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
"QPushButton:disabled {\n"
"background-color:rgb(211, 215, 207);\n"
"}\n"
""));

        horizontalLayout_2->addWidget(m_PshBtn_DBMatrics);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        m_PshBtn_FetchDayWiseCont = new QPushButton(About);
        m_PshBtn_FetchDayWiseCont->setObjectName(QString::fromUtf8("m_PshBtn_FetchDayWiseCont"));
        m_PshBtn_FetchDayWiseCont->setMinimumSize(QSize(180, 30));
        m_PshBtn_FetchDayWiseCont->setMaximumSize(QSize(180, 30));
        m_PshBtn_FetchDayWiseCont->setStyleSheet(QString::fromUtf8("QPushButton\n"
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
"QPushButton:disabled {\n"
"background-color:rgb(211, 215, 207);\n"
"}\n"
""));

        horizontalLayout_2->addWidget(m_PshBtn_FetchDayWiseCont);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_6->addLayout(verticalLayout);

        tabWidget->addTab(About, QString());
        Versions = new QWidget();
        Versions->setObjectName(QString::fromUtf8("Versions"));
        Versions->setStyleSheet(QString::fromUtf8("font: 11pt ;"));
        verticalLayout_4 = new QVBoxLayout(Versions);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        scrollArea = new QScrollArea(Versions);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setMinimumSize(QSize(401, 0));
        scrollArea->setMaximumSize(QSize(400, 16777215));
        scrollArea->setStyleSheet(QString::fromUtf8("/*QScrollArea{\n"
"background:transparent;\n"
"border:none;\n"
"}\n"
"*/"));
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 380, 1018));
        scrollAreaWidgetContents->setMinimumSize(QSize(380, 0));
        scrollAreaWidgetContents->setMaximumSize(QSize(380, 16777215));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setSpacing(5);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(10, 0, 0, 9);
        m_csLnScoutparameters = new QLabel(scrollAreaWidgetContents);
        m_csLnScoutparameters->setObjectName(QString::fromUtf8("m_csLnScoutparameters"));
        m_csLnScoutparameters->setMinimumSize(QSize(150, 24));
        m_csLnScoutparameters->setMaximumSize(QSize(150, 24));
        QFont font;
        font.setFamily(QString::fromUtf8("Open Sans"));
        font.setPointSize(11);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        m_csLnScoutparameters->setFont(font);
        m_csLnScoutparameters->setStyleSheet(QString::fromUtf8("/*\n"
"color: rgb(93, 226, 255);*/\n"
"\n"
""));
        m_csLnScoutparameters->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_2->addWidget(m_csLnScoutparameters);

        m_HLayoutDetectionDis_3 = new QHBoxLayout();
        m_HLayoutDetectionDis_3->setSpacing(20);
        m_HLayoutDetectionDis_3->setObjectName(QString::fromUtf8("m_HLayoutDetectionDis_3"));
        m_csLnDetectionDistce_3 = new QLabel(scrollAreaWidgetContents);
        m_csLnDetectionDistce_3->setObjectName(QString::fromUtf8("m_csLnDetectionDistce_3"));
        m_csLnDetectionDistce_3->setMinimumSize(QSize(140, 24));
        m_csLnDetectionDistce_3->setFont(font);
        m_csLnDetectionDistce_3->setStyleSheet(QString::fromUtf8(""));
        m_csLnDetectionDistce_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        m_HLayoutDetectionDis_3->addWidget(m_csLnDetectionDistce_3);

        pc_Vnum = new QLabel(scrollAreaWidgetContents);
        pc_Vnum->setObjectName(QString::fromUtf8("pc_Vnum"));
        pc_Vnum->setMinimumSize(QSize(200, 24));
        pc_Vnum->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        m_HLayoutDetectionDis_3->addWidget(pc_Vnum);


        verticalLayout_2->addLayout(m_HLayoutDetectionDis_3);

        m_HLayoutSpacingFactor_3 = new QHBoxLayout();
        m_HLayoutSpacingFactor_3->setSpacing(20);
        m_HLayoutSpacingFactor_3->setObjectName(QString::fromUtf8("m_HLayoutSpacingFactor_3"));
        m_csLnSpacingFactor_3 = new QLabel(scrollAreaWidgetContents);
        m_csLnSpacingFactor_3->setObjectName(QString::fromUtf8("m_csLnSpacingFactor_3"));
        m_csLnSpacingFactor_3->setMinimumSize(QSize(140, 24));
        m_csLnSpacingFactor_3->setFont(font);
        m_csLnSpacingFactor_3->setStyleSheet(QString::fromUtf8(""));
        m_csLnSpacingFactor_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        m_HLayoutSpacingFactor_3->addWidget(m_csLnSpacingFactor_3);

        pc_Date = new QLabel(scrollAreaWidgetContents);
        pc_Date->setObjectName(QString::fromUtf8("pc_Date"));
        pc_Date->setMinimumSize(QSize(200, 24));
        pc_Date->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        m_HLayoutSpacingFactor_3->addWidget(pc_Date);


        verticalLayout_2->addLayout(m_HLayoutSpacingFactor_3);

        m_HLayoutNoofsonobuys_3 = new QHBoxLayout();
        m_HLayoutNoofsonobuys_3->setSpacing(20);
        m_HLayoutNoofsonobuys_3->setObjectName(QString::fromUtf8("m_HLayoutNoofsonobuys_3"));
        m_csLnNoofsonobuys_3 = new QLabel(scrollAreaWidgetContents);
        m_csLnNoofsonobuys_3->setObjectName(QString::fromUtf8("m_csLnNoofsonobuys_3"));
        m_csLnNoofsonobuys_3->setMinimumSize(QSize(140, 24));
        m_csLnNoofsonobuys_3->setFont(font);
        m_csLnNoofsonobuys_3->setStyleSheet(QString::fromUtf8(""));
        m_csLnNoofsonobuys_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        m_HLayoutNoofsonobuys_3->addWidget(m_csLnNoofsonobuys_3);

        pc_Rnote = new QTextEdit(scrollAreaWidgetContents);
        pc_Rnote->setObjectName(QString::fromUtf8("pc_Rnote"));
        pc_Rnote->setMinimumSize(QSize(200, 71));
        pc_Rnote->setMaximumSize(QSize(200, 71));
        pc_Rnote->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pc_Rnote->setReadOnly(true);

        m_HLayoutNoofsonobuys_3->addWidget(pc_Rnote);


        verticalLayout_2->addLayout(m_HLayoutNoofsonobuys_3);

        m_csLnSensorParameters = new QLabel(scrollAreaWidgetContents);
        m_csLnSensorParameters->setObjectName(QString::fromUtf8("m_csLnSensorParameters"));
        m_csLnSensorParameters->setMinimumSize(QSize(170, 24));
        m_csLnSensorParameters->setMaximumSize(QSize(170, 24));
        m_csLnSensorParameters->setFont(font);
        m_csLnSensorParameters->setStyleSheet(QString::fromUtf8("/*\n"
"color: rgb(93, 226, 255);*/\n"
"\n"
""));
        m_csLnSensorParameters->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_2->addWidget(m_csLnSensorParameters);

        m_HLayoutDetectionDis = new QHBoxLayout();
        m_HLayoutDetectionDis->setSpacing(20);
        m_HLayoutDetectionDis->setObjectName(QString::fromUtf8("m_HLayoutDetectionDis"));
        m_csLnDetectionDistce = new QLabel(scrollAreaWidgetContents);
        m_csLnDetectionDistce->setObjectName(QString::fromUtf8("m_csLnDetectionDistce"));
        m_csLnDetectionDistce->setMinimumSize(QSize(140, 24));
        m_csLnDetectionDistce->setFont(font);
        m_csLnDetectionDistce->setStyleSheet(QString::fromUtf8(""));
        m_csLnDetectionDistce->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        m_HLayoutDetectionDis->addWidget(m_csLnDetectionDistce);

        adc_Vnum = new QLabel(scrollAreaWidgetContents);
        adc_Vnum->setObjectName(QString::fromUtf8("adc_Vnum"));
        adc_Vnum->setMinimumSize(QSize(200, 24));
        adc_Vnum->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        m_HLayoutDetectionDis->addWidget(adc_Vnum);


        verticalLayout_2->addLayout(m_HLayoutDetectionDis);

        m_HLayoutSpacingFactor = new QHBoxLayout();
        m_HLayoutSpacingFactor->setSpacing(20);
        m_HLayoutSpacingFactor->setObjectName(QString::fromUtf8("m_HLayoutSpacingFactor"));
        m_csLnSpacingFactor = new QLabel(scrollAreaWidgetContents);
        m_csLnSpacingFactor->setObjectName(QString::fromUtf8("m_csLnSpacingFactor"));
        m_csLnSpacingFactor->setMinimumSize(QSize(140, 24));
        m_csLnSpacingFactor->setFont(font);
        m_csLnSpacingFactor->setStyleSheet(QString::fromUtf8(""));
        m_csLnSpacingFactor->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        m_HLayoutSpacingFactor->addWidget(m_csLnSpacingFactor);

        adc_Date = new QLabel(scrollAreaWidgetContents);
        adc_Date->setObjectName(QString::fromUtf8("adc_Date"));
        adc_Date->setMinimumSize(QSize(200, 24));
        adc_Date->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        m_HLayoutSpacingFactor->addWidget(adc_Date);


        verticalLayout_2->addLayout(m_HLayoutSpacingFactor);

        m_HLayoutNoofsonobuys = new QHBoxLayout();
        m_HLayoutNoofsonobuys->setSpacing(20);
        m_HLayoutNoofsonobuys->setObjectName(QString::fromUtf8("m_HLayoutNoofsonobuys"));
        m_csLnNoofsonobuys = new QLabel(scrollAreaWidgetContents);
        m_csLnNoofsonobuys->setObjectName(QString::fromUtf8("m_csLnNoofsonobuys"));
        m_csLnNoofsonobuys->setMinimumSize(QSize(140, 24));
        m_csLnNoofsonobuys->setFont(font);
        m_csLnNoofsonobuys->setStyleSheet(QString::fromUtf8(""));
        m_csLnNoofsonobuys->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        m_HLayoutNoofsonobuys->addWidget(m_csLnNoofsonobuys);

        adc_Rnote = new QTextEdit(scrollAreaWidgetContents);
        adc_Rnote->setObjectName(QString::fromUtf8("adc_Rnote"));
        adc_Rnote->setMinimumSize(QSize(200, 71));
        adc_Rnote->setMaximumSize(QSize(200, 71));
        adc_Rnote->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        adc_Rnote->setReadOnly(true);

        m_HLayoutNoofsonobuys->addWidget(adc_Rnote);


        verticalLayout_2->addLayout(m_HLayoutNoofsonobuys);

        m_csLnDatumParameters = new QLabel(scrollAreaWidgetContents);
        m_csLnDatumParameters->setObjectName(QString::fromUtf8("m_csLnDatumParameters"));
        m_csLnDatumParameters->setMinimumSize(QSize(150, 24));
        m_csLnDatumParameters->setMaximumSize(QSize(150, 24));
        m_csLnDatumParameters->setFont(font);
        m_csLnDatumParameters->setStyleSheet(QString::fromUtf8("/*\n"
"color: rgb(93, 226, 255);*/\n"
"\n"
""));
        m_csLnDatumParameters->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_2->addWidget(m_csLnDatumParameters);

        m_HLayoutDetectionDis_4 = new QHBoxLayout();
        m_HLayoutDetectionDis_4->setSpacing(20);
        m_HLayoutDetectionDis_4->setObjectName(QString::fromUtf8("m_HLayoutDetectionDis_4"));
        m_csLnDetectionDistce_4 = new QLabel(scrollAreaWidgetContents);
        m_csLnDetectionDistce_4->setObjectName(QString::fromUtf8("m_csLnDetectionDistce_4"));
        m_csLnDetectionDistce_4->setMinimumSize(QSize(140, 24));
        m_csLnDetectionDistce_4->setFont(font);
        m_csLnDetectionDistce_4->setStyleSheet(QString::fromUtf8(""));
        m_csLnDetectionDistce_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        m_HLayoutDetectionDis_4->addWidget(m_csLnDetectionDistce_4);

        s_Vnum = new QLabel(scrollAreaWidgetContents);
        s_Vnum->setObjectName(QString::fromUtf8("s_Vnum"));
        s_Vnum->setMinimumSize(QSize(200, 24));
        s_Vnum->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        m_HLayoutDetectionDis_4->addWidget(s_Vnum);


        verticalLayout_2->addLayout(m_HLayoutDetectionDis_4);

        m_HLayoutSpacingFactor_4 = new QHBoxLayout();
        m_HLayoutSpacingFactor_4->setSpacing(20);
        m_HLayoutSpacingFactor_4->setObjectName(QString::fromUtf8("m_HLayoutSpacingFactor_4"));
        m_csLnSpacingFactor_4 = new QLabel(scrollAreaWidgetContents);
        m_csLnSpacingFactor_4->setObjectName(QString::fromUtf8("m_csLnSpacingFactor_4"));
        m_csLnSpacingFactor_4->setMinimumSize(QSize(140, 24));
        m_csLnSpacingFactor_4->setFont(font);
        m_csLnSpacingFactor_4->setStyleSheet(QString::fromUtf8(""));
        m_csLnSpacingFactor_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        m_HLayoutSpacingFactor_4->addWidget(m_csLnSpacingFactor_4);

        s_Date = new QLabel(scrollAreaWidgetContents);
        s_Date->setObjectName(QString::fromUtf8("s_Date"));
        s_Date->setMinimumSize(QSize(200, 24));
        s_Date->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        m_HLayoutSpacingFactor_4->addWidget(s_Date);


        verticalLayout_2->addLayout(m_HLayoutSpacingFactor_4);

        m_HLayoutNoofsonobuys_4 = new QHBoxLayout();
        m_HLayoutNoofsonobuys_4->setSpacing(20);
        m_HLayoutNoofsonobuys_4->setObjectName(QString::fromUtf8("m_HLayoutNoofsonobuys_4"));
        m_csLnNoofsonobuys_4 = new QLabel(scrollAreaWidgetContents);
        m_csLnNoofsonobuys_4->setObjectName(QString::fromUtf8("m_csLnNoofsonobuys_4"));
        m_csLnNoofsonobuys_4->setMinimumSize(QSize(140, 24));
        m_csLnNoofsonobuys_4->setFont(font);
        m_csLnNoofsonobuys_4->setStyleSheet(QString::fromUtf8(""));
        m_csLnNoofsonobuys_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        m_HLayoutNoofsonobuys_4->addWidget(m_csLnNoofsonobuys_4);

        s_Rnote = new QTextEdit(scrollAreaWidgetContents);
        s_Rnote->setObjectName(QString::fromUtf8("s_Rnote"));
        s_Rnote->setMinimumSize(QSize(200, 71));
        s_Rnote->setMaximumSize(QSize(200, 71));
        s_Rnote->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        s_Rnote->setReadOnly(true);

        m_HLayoutNoofsonobuys_4->addWidget(s_Rnote);


        verticalLayout_2->addLayout(m_HLayoutNoofsonobuys_4);

        m_csLnDatumParameters_2 = new QLabel(scrollAreaWidgetContents);
        m_csLnDatumParameters_2->setObjectName(QString::fromUtf8("m_csLnDatumParameters_2"));
        m_csLnDatumParameters_2->setMinimumSize(QSize(150, 24));
        m_csLnDatumParameters_2->setMaximumSize(QSize(150, 24));
        m_csLnDatumParameters_2->setFont(font);
        m_csLnDatumParameters_2->setStyleSheet(QString::fromUtf8("/*\n"
"color: rgb(93, 226, 255);*/\n"
"\n"
""));
        m_csLnDatumParameters_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_2->addWidget(m_csLnDatumParameters_2);

        m_HLayoutDetectionDis_5 = new QHBoxLayout();
        m_HLayoutDetectionDis_5->setSpacing(20);
        m_HLayoutDetectionDis_5->setObjectName(QString::fromUtf8("m_HLayoutDetectionDis_5"));
        m_csLnDetectionDistce_5 = new QLabel(scrollAreaWidgetContents);
        m_csLnDetectionDistce_5->setObjectName(QString::fromUtf8("m_csLnDetectionDistce_5"));
        m_csLnDetectionDistce_5->setMinimumSize(QSize(140, 24));
        m_csLnDetectionDistce_5->setFont(font);
        m_csLnDetectionDistce_5->setStyleSheet(QString::fromUtf8(""));
        m_csLnDetectionDistce_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        m_HLayoutDetectionDis_5->addWidget(m_csLnDetectionDistce_5);

        kpi_Vnum = new QLabel(scrollAreaWidgetContents);
        kpi_Vnum->setObjectName(QString::fromUtf8("kpi_Vnum"));
        kpi_Vnum->setMinimumSize(QSize(200, 24));
        kpi_Vnum->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        m_HLayoutDetectionDis_5->addWidget(kpi_Vnum);


        verticalLayout_2->addLayout(m_HLayoutDetectionDis_5);

        m_HLayoutSpacingFactor_5 = new QHBoxLayout();
        m_HLayoutSpacingFactor_5->setSpacing(20);
        m_HLayoutSpacingFactor_5->setObjectName(QString::fromUtf8("m_HLayoutSpacingFactor_5"));
        m_csLnSpacingFactor_5 = new QLabel(scrollAreaWidgetContents);
        m_csLnSpacingFactor_5->setObjectName(QString::fromUtf8("m_csLnSpacingFactor_5"));
        m_csLnSpacingFactor_5->setMinimumSize(QSize(140, 24));
        m_csLnSpacingFactor_5->setFont(font);
        m_csLnSpacingFactor_5->setStyleSheet(QString::fromUtf8(""));
        m_csLnSpacingFactor_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        m_HLayoutSpacingFactor_5->addWidget(m_csLnSpacingFactor_5);

        kpi_Date = new QLabel(scrollAreaWidgetContents);
        kpi_Date->setObjectName(QString::fromUtf8("kpi_Date"));
        kpi_Date->setMinimumSize(QSize(200, 24));
        kpi_Date->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        m_HLayoutSpacingFactor_5->addWidget(kpi_Date);


        verticalLayout_2->addLayout(m_HLayoutSpacingFactor_5);

        m_HLayoutNoofsonobuys_5 = new QHBoxLayout();
        m_HLayoutNoofsonobuys_5->setSpacing(20);
        m_HLayoutNoofsonobuys_5->setObjectName(QString::fromUtf8("m_HLayoutNoofsonobuys_5"));
        m_csLnNoofsonobuys_5 = new QLabel(scrollAreaWidgetContents);
        m_csLnNoofsonobuys_5->setObjectName(QString::fromUtf8("m_csLnNoofsonobuys_5"));
        m_csLnNoofsonobuys_5->setMinimumSize(QSize(140, 24));
        m_csLnNoofsonobuys_5->setFont(font);
        m_csLnNoofsonobuys_5->setStyleSheet(QString::fromUtf8(""));
        m_csLnNoofsonobuys_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        m_HLayoutNoofsonobuys_5->addWidget(m_csLnNoofsonobuys_5);

        kpi_Rnote = new QTextEdit(scrollAreaWidgetContents);
        kpi_Rnote->setObjectName(QString::fromUtf8("kpi_Rnote"));
        kpi_Rnote->setMinimumSize(QSize(200, 71));
        kpi_Rnote->setMaximumSize(QSize(200, 71));
        kpi_Rnote->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        kpi_Rnote->setReadOnly(true);

        m_HLayoutNoofsonobuys_5->addWidget(kpi_Rnote);


        verticalLayout_2->addLayout(m_HLayoutNoofsonobuys_5);

        m_csLnDatumParameters_3 = new QLabel(scrollAreaWidgetContents);
        m_csLnDatumParameters_3->setObjectName(QString::fromUtf8("m_csLnDatumParameters_3"));
        m_csLnDatumParameters_3->setMinimumSize(QSize(150, 24));
        m_csLnDatumParameters_3->setMaximumSize(QSize(200, 24));
        m_csLnDatumParameters_3->setFont(font);
        m_csLnDatumParameters_3->setStyleSheet(QString::fromUtf8("/*\n"
"color: rgb(93, 226, 255);*/\n"
"\n"
""));
        m_csLnDatumParameters_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_2->addWidget(m_csLnDatumParameters_3);

        m_HLayoutDetectionDis_6 = new QHBoxLayout();
        m_HLayoutDetectionDis_6->setSpacing(20);
        m_HLayoutDetectionDis_6->setObjectName(QString::fromUtf8("m_HLayoutDetectionDis_6"));
        m_csLnDetectionDistce_6 = new QLabel(scrollAreaWidgetContents);
        m_csLnDetectionDistce_6->setObjectName(QString::fromUtf8("m_csLnDetectionDistce_6"));
        m_csLnDetectionDistce_6->setMinimumSize(QSize(140, 24));
        m_csLnDetectionDistce_6->setFont(font);
        m_csLnDetectionDistce_6->setStyleSheet(QString::fromUtf8(""));
        m_csLnDetectionDistce_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        m_HLayoutDetectionDis_6->addWidget(m_csLnDetectionDistce_6);

        kpicron_Vnum = new QLabel(scrollAreaWidgetContents);
        kpicron_Vnum->setObjectName(QString::fromUtf8("kpicron_Vnum"));
        kpicron_Vnum->setMinimumSize(QSize(200, 24));
        kpicron_Vnum->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        m_HLayoutDetectionDis_6->addWidget(kpicron_Vnum);


        verticalLayout_2->addLayout(m_HLayoutDetectionDis_6);

        m_HLayoutSpacingFactor_6 = new QHBoxLayout();
        m_HLayoutSpacingFactor_6->setSpacing(20);
        m_HLayoutSpacingFactor_6->setObjectName(QString::fromUtf8("m_HLayoutSpacingFactor_6"));
        m_csLnSpacingFactor_6 = new QLabel(scrollAreaWidgetContents);
        m_csLnSpacingFactor_6->setObjectName(QString::fromUtf8("m_csLnSpacingFactor_6"));
        m_csLnSpacingFactor_6->setMinimumSize(QSize(140, 24));
        m_csLnSpacingFactor_6->setFont(font);
        m_csLnSpacingFactor_6->setStyleSheet(QString::fromUtf8(""));
        m_csLnSpacingFactor_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        m_HLayoutSpacingFactor_6->addWidget(m_csLnSpacingFactor_6);

        kpicron_Date = new QLabel(scrollAreaWidgetContents);
        kpicron_Date->setObjectName(QString::fromUtf8("kpicron_Date"));
        kpicron_Date->setMinimumSize(QSize(200, 24));
        kpicron_Date->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        m_HLayoutSpacingFactor_6->addWidget(kpicron_Date);


        verticalLayout_2->addLayout(m_HLayoutSpacingFactor_6);

        m_HLayoutNoofsonobuys_6 = new QHBoxLayout();
        m_HLayoutNoofsonobuys_6->setSpacing(20);
        m_HLayoutNoofsonobuys_6->setObjectName(QString::fromUtf8("m_HLayoutNoofsonobuys_6"));
        m_csLnNoofsonobuys_6 = new QLabel(scrollAreaWidgetContents);
        m_csLnNoofsonobuys_6->setObjectName(QString::fromUtf8("m_csLnNoofsonobuys_6"));
        m_csLnNoofsonobuys_6->setMinimumSize(QSize(140, 24));
        m_csLnNoofsonobuys_6->setFont(font);
        m_csLnNoofsonobuys_6->setStyleSheet(QString::fromUtf8(""));
        m_csLnNoofsonobuys_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        m_HLayoutNoofsonobuys_6->addWidget(m_csLnNoofsonobuys_6);

        kpicron_Rnote = new QTextEdit(scrollAreaWidgetContents);
        kpicron_Rnote->setObjectName(QString::fromUtf8("kpicron_Rnote"));
        kpicron_Rnote->setMinimumSize(QSize(200, 71));
        kpicron_Rnote->setMaximumSize(QSize(200, 71));
        kpicron_Rnote->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        kpicron_Rnote->setReadOnly(true);

        m_HLayoutNoofsonobuys_6->addWidget(kpicron_Rnote);


        verticalLayout_2->addLayout(m_HLayoutNoofsonobuys_6);

        m_csLnDatumParameters_4 = new QLabel(scrollAreaWidgetContents);
        m_csLnDatumParameters_4->setObjectName(QString::fromUtf8("m_csLnDatumParameters_4"));
        m_csLnDatumParameters_4->setMinimumSize(QSize(150, 24));
        m_csLnDatumParameters_4->setMaximumSize(QSize(195, 24));
        m_csLnDatumParameters_4->setFont(font);
        m_csLnDatumParameters_4->setStyleSheet(QString::fromUtf8("/*\n"
"color: rgb(93, 226, 255);*/\n"
"\n"
""));
        m_csLnDatumParameters_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_2->addWidget(m_csLnDatumParameters_4);

        m_HLayoutDetectionDis_7 = new QHBoxLayout();
        m_HLayoutDetectionDis_7->setSpacing(20);
        m_HLayoutDetectionDis_7->setObjectName(QString::fromUtf8("m_HLayoutDetectionDis_7"));
        m_csLnDetectionDistce_7 = new QLabel(scrollAreaWidgetContents);
        m_csLnDetectionDistce_7->setObjectName(QString::fromUtf8("m_csLnDetectionDistce_7"));
        m_csLnDetectionDistce_7->setMinimumSize(QSize(140, 24));
        m_csLnDetectionDistce_7->setFont(font);
        m_csLnDetectionDistce_7->setStyleSheet(QString::fromUtf8(""));
        m_csLnDetectionDistce_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        m_HLayoutDetectionDis_7->addWidget(m_csLnDetectionDistce_7);

        cs_Vnum = new QLabel(scrollAreaWidgetContents);
        cs_Vnum->setObjectName(QString::fromUtf8("cs_Vnum"));
        cs_Vnum->setMinimumSize(QSize(200, 24));
        cs_Vnum->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        m_HLayoutDetectionDis_7->addWidget(cs_Vnum);


        verticalLayout_2->addLayout(m_HLayoutDetectionDis_7);

        m_HLayoutSpacingFactor_7 = new QHBoxLayout();
        m_HLayoutSpacingFactor_7->setSpacing(20);
        m_HLayoutSpacingFactor_7->setObjectName(QString::fromUtf8("m_HLayoutSpacingFactor_7"));
        m_csLnSpacingFactor_7 = new QLabel(scrollAreaWidgetContents);
        m_csLnSpacingFactor_7->setObjectName(QString::fromUtf8("m_csLnSpacingFactor_7"));
        m_csLnSpacingFactor_7->setMinimumSize(QSize(140, 24));
        m_csLnSpacingFactor_7->setFont(font);
        m_csLnSpacingFactor_7->setStyleSheet(QString::fromUtf8(""));
        m_csLnSpacingFactor_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        m_HLayoutSpacingFactor_7->addWidget(m_csLnSpacingFactor_7);

        cs_Date = new QLabel(scrollAreaWidgetContents);
        cs_Date->setObjectName(QString::fromUtf8("cs_Date"));
        cs_Date->setMinimumSize(QSize(200, 24));
        cs_Date->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        m_HLayoutSpacingFactor_7->addWidget(cs_Date);


        verticalLayout_2->addLayout(m_HLayoutSpacingFactor_7);

        m_HLayoutNoofsonobuys_7 = new QHBoxLayout();
        m_HLayoutNoofsonobuys_7->setSpacing(20);
        m_HLayoutNoofsonobuys_7->setObjectName(QString::fromUtf8("m_HLayoutNoofsonobuys_7"));
        m_csLnNoofsonobuys_7 = new QLabel(scrollAreaWidgetContents);
        m_csLnNoofsonobuys_7->setObjectName(QString::fromUtf8("m_csLnNoofsonobuys_7"));
        m_csLnNoofsonobuys_7->setMinimumSize(QSize(140, 24));
        m_csLnNoofsonobuys_7->setFont(font);
        m_csLnNoofsonobuys_7->setStyleSheet(QString::fromUtf8(""));
        m_csLnNoofsonobuys_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        m_HLayoutNoofsonobuys_7->addWidget(m_csLnNoofsonobuys_7);

        cs_Rnote = new QTextEdit(scrollAreaWidgetContents);
        cs_Rnote->setObjectName(QString::fromUtf8("cs_Rnote"));
        cs_Rnote->setMinimumSize(QSize(200, 71));
        cs_Rnote->setMaximumSize(QSize(200, 71));
        cs_Rnote->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        cs_Rnote->setReadOnly(true);

        m_HLayoutNoofsonobuys_7->addWidget(cs_Rnote);


        verticalLayout_2->addLayout(m_HLayoutNoofsonobuys_7);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_4->addWidget(scrollArea);

        tabWidget->addTab(Versions, QString());
        QuickGuide = new QWidget();
        QuickGuide->setObjectName(QString::fromUtf8("QuickGuide"));
        layoutWidget = new QWidget(QuickGuide);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(2, 3, 411, 121));
        verticalLayout_7 = new QVBoxLayout(layoutWidget);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        m_PshBtn_quickGuide = new QPushButton(layoutWidget);
        m_PshBtn_quickGuide->setObjectName(QString::fromUtf8("m_PshBtn_quickGuide"));
        m_PshBtn_quickGuide->setMinimumSize(QSize(130, 35));
        m_PshBtn_quickGuide->setMaximumSize(QSize(16777215, 35));
        m_PshBtn_quickGuide->setStyleSheet(QString::fromUtf8("QPushButton\n"
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
"QPushButton:disabled {\n"
"background-color:rgb(211, 215, 207);\n"
"}\n"
""));

        horizontalLayout_3->addWidget(m_PshBtn_quickGuide);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_7->addLayout(horizontalLayout_3);

        textEdit_2 = new QTextEdit(layoutWidget);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setMinimumSize(QSize(0, 70));
        textEdit_2->setMaximumSize(QSize(16777215, 70));
        textEdit_2->setReadOnly(true);

        verticalLayout_7->addWidget(textEdit_2);

        tabWidget->addTab(QuickGuide, QString());

        verticalLayout_3->addWidget(tabWidget);


        verticalLayout_5->addLayout(verticalLayout_3);


        retranslateUi(about);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(about);
    } // setupUi

    void retranslateUi(QWidget *about)
    {
        about->setWindowTitle(QCoreApplication::translate("about", "About", nullptr));
        pushButton->setText(QCoreApplication::translate("about", "Close", nullptr));
        textEdit->setHtml(QCoreApplication::translate("about", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Jsoncpp:</p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">The JsonCpp library's source code, including accompanying documentation,</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;"
                        "\">tests and demonstration applications, are licensed under the following</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">conditions...</p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Baptiste Lepilleur and The JsonCpp Authors explicitly disclaim copyright in all</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">jurisdictions which recognize such a disclaimer. In such jurisdictions,</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">this software is r"
                        "eleased into the Public Domain.</p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">In jurisdictions which do not recognize Public Domain property (e.g. Germany as of</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">2010), this software is Copyright (c) 2007-2010 by Baptiste Lepilleur and</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">The JsonCpp Authors, and is released under the terms of the MIT License (see below).</p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px"
                        "; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">In jurisdictions which recognize Public Domain property, the user of this</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">software may choose to accept it either as 1) Public Domain, 2) under the</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">conditions of the MIT License (see below), or 3) under the terms of dual</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Public Domain/MIT License conditions described here, as they choose.</p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; m"
                        "argin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">The MIT License is about as close to Public Domain as a license can get, and is</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">described in clear, concise terms at:</p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">   http://en.wikipedia.org/wiki/MIT_License</p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-inden"
                        "t:0px;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">The full text of the MIT License follows:</p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">========================================================================</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Copyright (c) 2007-2010 Baptiste Lepilleur and The JsonCpp Authors</p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"justify\""
                        " style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Permission is hereby granted, free of charge, to any person</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">obtaining a copy of this software and associated documentation</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">files (the &quot;Software&quot;), to deal in the Software without</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">restriction, including without limitation the rights to use, copy,</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">modify, merge, publish, distribute, sublicense, and/or sell co"
                        "pies</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">of the Software, and to permit persons to whom the Software is</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">furnished to do so, subject to the following conditions:</p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">The above copyright notice and this permission notice shall be</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">included in all copies or substantial portions of the Software.</p>\n"
""
                        "<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">THE SOFTWARE IS PROVIDED &quot;AS IS&quot;, WITHOUT WARRANTY OF ANY KIND,</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS</p>"
                        "\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">SOFTWARE.</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">========================================================================</p>\n"
"<p a"
                        "lign=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">(END LICENSE TEXT)</p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">The MIT license is compatible with both the GPL and commercial</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">software, affording one all of the rights of Public Domain with the</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">minor nuisance of being required to keep the above copyright notice</p>\n"
"<p align=\"justify\" style=\" margin-top:0px"
                        "; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">and license text in the source code. Note also that by accepting the</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Public Domain &quot;license&quot; you can re-license your copy using whatever</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">license you like.</p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">libpqxx:</p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt"
                        "-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">The source code for libpqxx is available under the BSD license, so you're free to download it, pass it on to others, change it, sell it, include it in your own code, and share your changes with anyone you choose. No charge, no catch. Also, no guarantees. :-)</p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">postgres-apache:</p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; "
                        "margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">                             Apache License</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">                           Version 2.0, January 2004</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">                        http://www.apache.org/licenses/</p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">   TERMS AND CONDITIONS FOR USE, REPRODUCTION, AND DISTRIBUTION</p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0p"
                        "x; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">   1. Definitions.</p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      &quot;License&quot; shall mean the terms and conditions for use, reproduction,</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      and distribution as defined by Sections 1 through 9 of this document.</p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-bloc"
                        "k-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      &quot;Licensor&quot; shall mean the copyright owner or entity authorized by</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      the copyright owner that is granting the License.</p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      &quot;Legal Entity&quot; shall mean the union of the acting entity and all</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"> "
                        "     other entities that control, are controlled by, or are under common</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      control with that entity. For the purposes of this definition,</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      &quot;control&quot; means (i) the power, direct or indirect, to cause the</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      direction or management of such entity, whether by contract or</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      otherwise, or (ii) ownership of fifty percent (50%) or more of the</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; "
                        "margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      outstanding shares, or (iii) beneficial ownership of such entity.</p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      &quot;You&quot; (or &quot;Your&quot;) shall mean an individual or Legal Entity</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      exercising permissions granted by this License.</p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px"
                        "; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      &quot;Source&quot; form shall mean the preferred form for making modifications,</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      including but not limited to software source code, documentation</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      source, and configuration files.</p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      &quot;Object&quot; form shall mean any form resulting from mechanical</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; m"
                        "argin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      transformation or translation of a Source form, including but</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      not limited to compiled object code, generated documentation,</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      and conversions to other media types.</p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      &quot;Work&quot; shall mean the work of authorship, whether in Source or</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; "
                        "margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      Object form, made available under the License, as indicated by a</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      copyright notice that is included in or attached to the work</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      (an example is provided in the Appendix below).</p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      &quot;Derivative Works&quot; shall mean any work, whether in Source or Object</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; m"
                        "argin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      form, that is based on (or derived from) the Work and for which the</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      editorial revisions, annotations, elaborations, or other modifications</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      represent, as a whole, an original work of authorship. For the purposes</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      of this License, Derivative Works shall not include works that remain</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      separable from, or merely link (or"
                        " bind by name) to the interfaces of,</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      the Work and Derivative Works thereof.</p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      &quot;Contribution&quot; shall mean any work of authorship, including</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      the original version of the Work and any modifications or additions</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      to that Work or Deri"
                        "vative Works thereof, that is intentionally</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      submitted to Licensor for inclusion in the Work by the copyright owner</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      or by an individual or Legal Entity authorized to submit on behalf of</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      the copyright owner. For the purposes of this definition, &quot;submitted&quot;</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      means any form of electronic, verbal, or written communication sent</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-"
                        "left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      to the Licensor or its representatives, including but not limited to</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      communication on electronic mailing lists, source code control systems,</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      and issue tracking systems that are managed by, or on behalf of, the</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      Licensor for the purpose of discussing and improving the Work, but</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      excluding communication that is conspicuously marked or otherwi"
                        "se</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      designated in writing by the copyright owner as &quot;Not a Contribution.&quot;</p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      &quot;Contributor&quot; shall mean Licensor and any individual or Legal Entity</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      on behalf of whom a Contribution has been received by Licensor and</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      subse"
                        "quently incorporated within the Work.</p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">   2. Grant of Copyright License. Subject to the terms and conditions of</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      this License, each Contributor hereby grants to You a perpetual,</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      worldwide, non-exclusive, no-charge, royalty-free, irrevocable</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      c"
                        "opyright license to reproduce, prepare Derivative Works of,</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      publicly display, publicly perform, sublicense, and distribute the</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      Work and such Derivative Works in Source or Object form.</p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">   3. Grant of Patent License. Subject to the terms and conditions of</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent"
                        ":0px;\">      this License, each Contributor hereby grants to You a perpetual,</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      worldwide, non-exclusive, no-charge, royalty-free, irrevocable</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      (except as stated in this section) patent license to make, have made,</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      use, offer to sell, sell, import, and otherwise transfer the Work,</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      where such license applies only to those patent claims licensable</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:"
                        "0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      by such Contributor that are necessarily infringed by their</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      Contribution(s) alone or by combination of their Contribution(s)</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      with the Work to which such Contribution(s) was submitted. If You</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      institute patent litigation against any entity (including a</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      cross-claim or counterclaim in a lawsuit) alleging that the Work</p>\n"
"<p a"
                        "lign=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      or a Contribution incorporated within the Work constitutes direct</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      or contributory patent infringement, then any patent licenses</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      granted to You under this License for that Work shall terminate</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      as of the date such litigation is filed.</p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p al"
                        "ign=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">   4. Redistribution. You may reproduce and distribute copies of the</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      Work or Derivative Works thereof in any medium, with or without</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      modifications, and in Source or Object form, provided that You</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      meet the following conditions:</p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"justify"
                        "\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      (a) You must give any other recipients of the Work or</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">          Derivative Works a copy of this License; and</p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      (b) You must cause any modified files to carry prominent notices</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">          stating that You changed the files; and</p>\n"
"<p align=\"justify\" style=\"-qt-paragra"
                        "ph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      (c) You must retain, in the Source form of any Derivative Works</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">          that You distribute, all copyright, patent, trademark, and</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">          attribution notices from the Source form of the Work,</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">          excluding those notices that do not pertain to any part of</p>\n"
"<p align=\"justify\" style"
                        "=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">          the Derivative Works; and</p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      (d) If the Work includes a &quot;NOTICE&quot; text file as part of its</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">          distribution, then any Derivative Works that You distribute must</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">          include a readable copy of the attribution notices contained</p>\n"
"<p align=\"justify\" styl"
                        "e=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">          within such NOTICE file, excluding those notices that do not</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">          pertain to any part of the Derivative Works, in at least one</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">          of the following places: within a NOTICE text file distributed</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">          as part of the Derivative Works; within the Source form or</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">          documentation, if provided al"
                        "ong with the Derivative Works; or,</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">          within a display generated by the Derivative Works, if and</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">          wherever such third-party notices normally appear. The contents</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">          of the NOTICE file are for informational purposes only and</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">          do not modify the License. You may add Your own attribution</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-in"
                        "dent:0; text-indent:0px;\">          notices within Derivative Works that You distribute, alongside</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">          or as an addendum to the NOTICE text from the Work, provided</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">          that such additional attribution notices cannot be construed</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">          as modifying the License.</p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0;"
                        " text-indent:0px;\">      You may add Your own copyright statement to Your modifications and</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      may provide additional or different license terms and conditions</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      for use, reproduction, or distribution of Your modifications, or</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      for any such Derivative Works as a whole, provided Your use,</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      reproduction, and distribution of the Work otherwise complies with</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-b"
                        "ottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      the conditions stated in this License.</p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">   5. Submission of Contributions. Unless You explicitly state otherwise,</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      any Contribution intentionally submitted for inclusion in the Work</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      by You to the Licensor shall be under the terms and conditions of</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; ma"
                        "rgin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      this License, without any additional terms or conditions.</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      Notwithstanding the above, nothing herein shall supersede or modify</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      the terms of any separate license agreement you may have executed</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      with Licensor regarding such Contributions.</p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; "
                        "margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">   6. Trademarks. This License does not grant permission to use the trade</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      names, trademarks, service marks, or product names of the Licensor,</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      except as required for reasonable and customary use in describing the</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      origin of the Work and reproducing the content of the NOTICE file.</p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p alig"
                        "n=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">   7. Disclaimer of Warranty. Unless required by applicable law or</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      agreed to in writing, Licensor provides the Work (and each</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      Contributor provides its Contributions) on an &quot;AS IS&quot; BASIS,</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      implied, including, "
                        "without limitation, any warranties or conditions</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      of TITLE, NON-INFRINGEMENT, MERCHANTABILITY, or FITNESS FOR A</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      PARTICULAR PURPOSE. You are solely responsible for determining the</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      appropriateness of using or redistributing the Work and assume any</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      risks associated with Your exercise of permissions under this License.</p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px;"
                        " margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">   8. Limitation of Liability. In no event and under no legal theory,</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      whether in tort (including negligence), contract, or otherwise,</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      unless required by applicable law (such as deliberate and grossly</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      negligent acts) or agreed to in writing, shall any Contributor be</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px"
                        "; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      liable to You for damages, including any direct, indirect, special,</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      incidental, or consequential damages of any character arising as a</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      result of this License or out of the use or inability to use the</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      Work (including but not limited to damages for loss of goodwill,</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      work stoppage, computer failure or malfunction, or any and all</p>"
                        "\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      other commercial damages or losses), even if such Contributor</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      has been advised of the possibility of such damages.</p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">   9. Accepting Warranty or Additional Liability. While redistributing</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      the Work or Derivative Works thereof, You may choose to o"
                        "ffer,</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      and charge a fee for, acceptance of support, warranty, indemnity,</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      or other liability obligations and/or rights consistent with this</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      License. However, in accepting such obligations, You may act only</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      on Your own behalf and on Your sole responsibility, not on behalf</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px"
                        ";\">      of any other Contributor, and only if You agree to indemnify,</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      defend, and hold each Contributor harmless for any liability</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      incurred by, or claims asserted against, such Contributor by reason</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      of your accepting any such warranty or additional liability.</p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:"
                        "0; text-indent:0px;\">   END OF TERMS AND CONDITIONS</p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">postgresql:</p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">PostgreSQL is released under the PostgreSQL License, a liberal Open Source license, similar to the BSD or MIT licenses.</p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<"
                        "p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">PostgreSQL Database Management System</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">(formerly known as Postgres, then as Postgres95)</p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Portions Copyright \302\251 1996-2021, The PostgreSQL Global Development Group</p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0"
                        "px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Portions Copyright \302\251 1994, The Regents of the University of California</p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Permission to use, copy, modify, and distribute this software and its documentation for any purpose, without fee, and without a written agreement is hereby granted, provided that the above copyright notice and this paragraph and the following two paragraphs appear in all copies.</p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left"
                        ":0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">IN NO EVENT SHALL THE UNIVERSITY OF CALIFORNIA BE LIABLE TO ANY PARTY FOR DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES, INCLUDING LOST PROFITS, ARISING OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN IF THE UNIVERSITY OF CALIFORNIA HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.</p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">THE UNIVERSITY OF CALIFORNIA SPECIFICALLY DISCLAIMS ANY WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. THE SOFTWARE PROVIDED HEREUNDER IS ON AN &quot;AS IS&quot; BASIS, AND THE UNIVERSITY OF CALIFORNIA HAS NO OBLIGATIONS TO PROVIDE MAINTENANCE, "
                        "SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.</p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Will PostgreSQL ever be released under a different license?</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">The PostgreSQL Global Development Group remains committed to making PostgreSQL available as free and open source software in perpetuity. There are no plans to change the PostgreSQL License or release PostgreSQL under a different license.</p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"justif"
                        "y\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">If you would like to read more about this topic, then please take a look at the mailing list archives at one of the many discussions on this subject.</p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">QTLicense:</p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; marg"
                        "in-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Qt is available under different licensing options designed to accommodate the needs of our various users:</p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Qt licensed under commercial licenses is appropriate for development of proprietary/commercial software where you do not want to share any source code with third parties or otherwise cannot comply with the terms of the GNU LGPL version 3.</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Qt licensed under the GNU Lesser General Public License (LGPL) version 3 is appropriate for the development of Qt appl"
                        "ications provided you can comply with the terms and conditions of the GNU LGPL version 3 (or GNU GPL version 3).</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Qt components licensed under the Qt Marketplace License Agreement are appropriate for the development of Qt applications commonly with Qt software components licensed under the commercial or GNU LGPL version 3 (or GNU GPL version 3) terms and conditions.</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Qt contains also third-party code that is licensed under specific open-source licenses from the original authors.</p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0p"
                        "x; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Note: For open-source licensed Qt, some specific parts (modules) are not available under the GNU LGPL version 3, but under the GNU General Public License (GPL) instead. See the list of Qt modules for details. For commercial licensees, all modules are available under a single, commercial Qt license.</p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Qt documentation is available under commercial licenses from The Qt Company, and under the terms of the GNU Free Documentation License (FDL) version 1.3, as published by the Free Software Foundation.</p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-"
                        "right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Qt examples are available under commercial licenses from The Qt Company, and under a BSD-3-clause license.</p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">See http://qt.io/licensing/ for an overview of Qt licensing.</p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">T"
                        "imescale:</p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Source code in this repository is variously licensed under the Apache License</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Version 2.0, an Apache compatible license, or the Timescale License.</p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">All source code should have information at the beginning of its respe"
                        "ctive file</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">which specifies its licensing information.</p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">* Outside of the &quot;tsl&quot; directory, source code in a given file is licensed</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">  under the Apache License Version 2.0, unless otherwise noted (e.g., an</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">  Apache-compatible license).</p>\n"
"<p align="
                        "\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">* Within the &quot;tsl&quot; folder, source code in a given file is licensed under the</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">  Timescale License, unless otherwise noted.</p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">When built, separate shared object files are generated for the Apache-licensed</p>\n"
"<p align=\"justify\" sty"
                        "le=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">source code and the Timescale-licensed source code. The shared object binaries</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">that contain `-tsl` in their name are licensed under the Timescale License.</p></body></html>", nullptr));
        m_PshBtn_DBMatrics->setText(QCoreApplication::translate("about", "DB Metrics", nullptr));
        m_PshBtn_FetchDayWiseCont->setText(QCoreApplication::translate("about", " Fetch Day Wise Count ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(About), QCoreApplication::translate("about", "About App", nullptr));
        m_csLnScoutparameters->setText(QCoreApplication::translate("about", "<html><head/><body><p>plcdatacollector</p></body></html>", nullptr));
        m_csLnDetectionDistce_3->setText(QCoreApplication::translate("about", "Version Number", nullptr));
        pc_Vnum->setText(QString());
        m_csLnSpacingFactor_3->setText(QCoreApplication::translate("about", "Date", nullptr));
        pc_Date->setText(QString());
        m_csLnNoofsonobuys_3->setText(QCoreApplication::translate("about", "Release Note", nullptr));
        m_csLnSensorParameters->setText(QCoreApplication::translate("about", "<html><head/><body><p>alarmdatacollector</p></body></html>", nullptr));
        m_csLnDetectionDistce->setText(QCoreApplication::translate("about", "Version Number", nullptr));
        adc_Vnum->setText(QString());
        m_csLnSpacingFactor->setText(QCoreApplication::translate("about", "Date", nullptr));
        adc_Date->setText(QString());
        m_csLnNoofsonobuys->setText(QCoreApplication::translate("about", "Release Note", nullptr));
        m_csLnDatumParameters->setText(QCoreApplication::translate("about", "<html><head/><body><p>dataloggerapi</p></body></html>", nullptr));
        m_csLnDetectionDistce_4->setText(QCoreApplication::translate("about", "Version Number", nullptr));
        s_Vnum->setText(QString());
        m_csLnSpacingFactor_4->setText(QCoreApplication::translate("about", "Date", nullptr));
        s_Date->setText(QString());
        m_csLnNoofsonobuys_4->setText(QCoreApplication::translate("about", "Release Note", nullptr));
        m_csLnDatumParameters_2->setText(QCoreApplication::translate("about", "<html><head/><body><p>kpiloggerapi</p></body></html>", nullptr));
        m_csLnDetectionDistce_5->setText(QCoreApplication::translate("about", "Version Number", nullptr));
        kpi_Vnum->setText(QString());
        m_csLnSpacingFactor_5->setText(QCoreApplication::translate("about", "Date", nullptr));
        kpi_Date->setText(QString());
        m_csLnNoofsonobuys_5->setText(QCoreApplication::translate("about", "Release Note", nullptr));
        m_csLnDatumParameters_3->setText(QCoreApplication::translate("about", "<html><head/><body><p>kpidatacollectioncron</p></body></html>", nullptr));
        m_csLnDetectionDistce_6->setText(QCoreApplication::translate("about", "Version Number", nullptr));
        kpicron_Vnum->setText(QString());
        m_csLnSpacingFactor_6->setText(QCoreApplication::translate("about", "Date", nullptr));
        kpicron_Date->setText(QString());
        m_csLnNoofsonobuys_6->setText(QCoreApplication::translate("about", "Release Note", nullptr));
        m_csLnDatumParameters_4->setText(QCoreApplication::translate("about", "<html><head/><body><p>commissioning-server</p></body></html>", nullptr));
        m_csLnDetectionDistce_7->setText(QCoreApplication::translate("about", "Version Number", nullptr));
        cs_Vnum->setText(QString());
        m_csLnSpacingFactor_7->setText(QCoreApplication::translate("about", "Date", nullptr));
        cs_Date->setText(QString());
        m_csLnNoofsonobuys_7->setText(QCoreApplication::translate("about", "Release Note", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Versions), QCoreApplication::translate("about", "Get Versions", nullptr));
        m_PshBtn_quickGuide->setText(QCoreApplication::translate("about", "Open Quick guide", nullptr));
        textEdit_2->setHtml(QCoreApplication::translate("about", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">Clicking this will open a browser window. You may need permissions to open this document.</span></p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(QuickGuide), QCoreApplication::translate("about", "Quick Guide", nullptr));
    } // retranslateUi

};

namespace Ui {
    class about: public Ui_about {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
