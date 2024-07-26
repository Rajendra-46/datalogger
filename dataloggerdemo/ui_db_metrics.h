/********************************************************************************
** Form generated from reading UI file 'db_metrics.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DB_METRICS_H
#define UI_DB_METRICS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DB_Metrics
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *m_HLayoutDetectionDis_3;
    QLabel *m_csLnDetectionDistce_3;
    QLabel *label_tDiskSpace;
    QHBoxLayout *m_HLayoutDetectionDis_4;
    QLabel *m_csLnDetectionDistce_4;
    QLabel *label_tDiskSpacePer;
    QHBoxLayout *m_HLayoutDetectionDis_5;
    QLabel *m_csLnDetectionDistce_5;
    QLabel *label_OtrSpace;
    QHBoxLayout *m_HLayoutDetectionDis_6;
    QLabel *m_csLnDetectionDistce_6;
    QLabel *label_OtrSpacePer;
    QHBoxLayout *m_HLayoutDetectionDis_7;
    QLabel *m_csLnDetectionDistce_7;
    QLabel *label_ResSpace;
    QHBoxLayout *m_HLayoutDetectionDis_8;
    QLabel *m_csLnDetectionDistce_8;
    QLabel *label_ResSpacePer;
    QHBoxLayout *m_HLayoutDetectionDis_9;
    QLabel *m_csLnDetectionDistce_9;
    QLabel *label_USpace;
    QHBoxLayout *m_HLayoutDetectionDis_10;
    QLabel *m_csLnDetectionDistce_10;
    QLabel *label_USpacePer;
    QHBoxLayout *m_HLayoutDetectionDis_11;
    QLabel *m_csLnDetectionDistce_11;
    QLabel *label_dStoreInDataTable;
    QHBoxLayout *m_HLayoutDetectionDis_12;
    QLabel *m_csLnDetectionDistce_12;
    QLabel *label_ASpace;
    QHBoxLayout *m_HLayoutDetectionDis_13;
    QLabel *m_csLnDetectionDistce_13;
    QLabel *label_ASpacePer;

    void setupUi(QWidget *DB_Metrics)
    {
        if (DB_Metrics->objectName().isEmpty())
            DB_Metrics->setObjectName(QString::fromUtf8("DB_Metrics"));
        DB_Metrics->resize(534, 469);
        DB_Metrics->setMinimumSize(QSize(534, 469));
        DB_Metrics->setMaximumSize(QSize(540, 470));
        DB_Metrics->setStyleSheet(QString::fromUtf8("font: 12pt \"MS Shell Dlg 2\";"));
        verticalLayout_3 = new QVBoxLayout(DB_Metrics);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(DB_Metrics);
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

        horizontalLayout->addWidget(pushButton);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        m_HLayoutDetectionDis_3 = new QHBoxLayout();
        m_HLayoutDetectionDis_3->setSpacing(20);
        m_HLayoutDetectionDis_3->setObjectName(QString::fromUtf8("m_HLayoutDetectionDis_3"));
        m_csLnDetectionDistce_3 = new QLabel(DB_Metrics);
        m_csLnDetectionDistce_3->setObjectName(QString::fromUtf8("m_csLnDetectionDistce_3"));
        m_csLnDetectionDistce_3->setMinimumSize(QSize(140, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font.setPointSize(12);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        m_csLnDetectionDistce_3->setFont(font);
        m_csLnDetectionDistce_3->setStyleSheet(QString::fromUtf8(""));
        m_csLnDetectionDistce_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        m_HLayoutDetectionDis_3->addWidget(m_csLnDetectionDistce_3);

        label_tDiskSpace = new QLabel(DB_Metrics);
        label_tDiskSpace->setObjectName(QString::fromUtf8("label_tDiskSpace"));
        label_tDiskSpace->setMinimumSize(QSize(100, 30));
        label_tDiskSpace->setMaximumSize(QSize(100, 30));
        label_tDiskSpace->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        m_HLayoutDetectionDis_3->addWidget(label_tDiskSpace);


        verticalLayout->addLayout(m_HLayoutDetectionDis_3);

        m_HLayoutDetectionDis_4 = new QHBoxLayout();
        m_HLayoutDetectionDis_4->setSpacing(20);
        m_HLayoutDetectionDis_4->setObjectName(QString::fromUtf8("m_HLayoutDetectionDis_4"));
        m_csLnDetectionDistce_4 = new QLabel(DB_Metrics);
        m_csLnDetectionDistce_4->setObjectName(QString::fromUtf8("m_csLnDetectionDistce_4"));
        m_csLnDetectionDistce_4->setMinimumSize(QSize(140, 30));
        m_csLnDetectionDistce_4->setFont(font);
        m_csLnDetectionDistce_4->setStyleSheet(QString::fromUtf8(""));
        m_csLnDetectionDistce_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        m_HLayoutDetectionDis_4->addWidget(m_csLnDetectionDistce_4);

        label_tDiskSpacePer = new QLabel(DB_Metrics);
        label_tDiskSpacePer->setObjectName(QString::fromUtf8("label_tDiskSpacePer"));
        label_tDiskSpacePer->setMinimumSize(QSize(100, 30));
        label_tDiskSpacePer->setMaximumSize(QSize(100, 30));
        label_tDiskSpacePer->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        m_HLayoutDetectionDis_4->addWidget(label_tDiskSpacePer);


        verticalLayout->addLayout(m_HLayoutDetectionDis_4);

        m_HLayoutDetectionDis_5 = new QHBoxLayout();
        m_HLayoutDetectionDis_5->setSpacing(20);
        m_HLayoutDetectionDis_5->setObjectName(QString::fromUtf8("m_HLayoutDetectionDis_5"));
        m_csLnDetectionDistce_5 = new QLabel(DB_Metrics);
        m_csLnDetectionDistce_5->setObjectName(QString::fromUtf8("m_csLnDetectionDistce_5"));
        m_csLnDetectionDistce_5->setMinimumSize(QSize(140, 30));
        m_csLnDetectionDistce_5->setFont(font);
        m_csLnDetectionDistce_5->setStyleSheet(QString::fromUtf8(""));
        m_csLnDetectionDistce_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        m_HLayoutDetectionDis_5->addWidget(m_csLnDetectionDistce_5);

        label_OtrSpace = new QLabel(DB_Metrics);
        label_OtrSpace->setObjectName(QString::fromUtf8("label_OtrSpace"));
        label_OtrSpace->setMinimumSize(QSize(100, 30));
        label_OtrSpace->setMaximumSize(QSize(100, 30));
        label_OtrSpace->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        m_HLayoutDetectionDis_5->addWidget(label_OtrSpace);


        verticalLayout->addLayout(m_HLayoutDetectionDis_5);

        m_HLayoutDetectionDis_6 = new QHBoxLayout();
        m_HLayoutDetectionDis_6->setSpacing(20);
        m_HLayoutDetectionDis_6->setObjectName(QString::fromUtf8("m_HLayoutDetectionDis_6"));
        m_csLnDetectionDistce_6 = new QLabel(DB_Metrics);
        m_csLnDetectionDistce_6->setObjectName(QString::fromUtf8("m_csLnDetectionDistce_6"));
        m_csLnDetectionDistce_6->setMinimumSize(QSize(140, 30));
        m_csLnDetectionDistce_6->setFont(font);
        m_csLnDetectionDistce_6->setStyleSheet(QString::fromUtf8(""));
        m_csLnDetectionDistce_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        m_HLayoutDetectionDis_6->addWidget(m_csLnDetectionDistce_6);

        label_OtrSpacePer = new QLabel(DB_Metrics);
        label_OtrSpacePer->setObjectName(QString::fromUtf8("label_OtrSpacePer"));
        label_OtrSpacePer->setMinimumSize(QSize(100, 30));
        label_OtrSpacePer->setMaximumSize(QSize(100, 30));
        label_OtrSpacePer->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        m_HLayoutDetectionDis_6->addWidget(label_OtrSpacePer);


        verticalLayout->addLayout(m_HLayoutDetectionDis_6);

        m_HLayoutDetectionDis_7 = new QHBoxLayout();
        m_HLayoutDetectionDis_7->setSpacing(20);
        m_HLayoutDetectionDis_7->setObjectName(QString::fromUtf8("m_HLayoutDetectionDis_7"));
        m_csLnDetectionDistce_7 = new QLabel(DB_Metrics);
        m_csLnDetectionDistce_7->setObjectName(QString::fromUtf8("m_csLnDetectionDistce_7"));
        m_csLnDetectionDistce_7->setMinimumSize(QSize(140, 30));
        m_csLnDetectionDistce_7->setFont(font);
        m_csLnDetectionDistce_7->setStyleSheet(QString::fromUtf8(""));
        m_csLnDetectionDistce_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        m_HLayoutDetectionDis_7->addWidget(m_csLnDetectionDistce_7);

        label_ResSpace = new QLabel(DB_Metrics);
        label_ResSpace->setObjectName(QString::fromUtf8("label_ResSpace"));
        label_ResSpace->setMinimumSize(QSize(100, 30));
        label_ResSpace->setMaximumSize(QSize(100, 30));
        label_ResSpace->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        m_HLayoutDetectionDis_7->addWidget(label_ResSpace);


        verticalLayout->addLayout(m_HLayoutDetectionDis_7);

        m_HLayoutDetectionDis_8 = new QHBoxLayout();
        m_HLayoutDetectionDis_8->setSpacing(20);
        m_HLayoutDetectionDis_8->setObjectName(QString::fromUtf8("m_HLayoutDetectionDis_8"));
        m_csLnDetectionDistce_8 = new QLabel(DB_Metrics);
        m_csLnDetectionDistce_8->setObjectName(QString::fromUtf8("m_csLnDetectionDistce_8"));
        m_csLnDetectionDistce_8->setMinimumSize(QSize(140, 30));
        m_csLnDetectionDistce_8->setFont(font);
        m_csLnDetectionDistce_8->setStyleSheet(QString::fromUtf8(""));
        m_csLnDetectionDistce_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        m_HLayoutDetectionDis_8->addWidget(m_csLnDetectionDistce_8);

        label_ResSpacePer = new QLabel(DB_Metrics);
        label_ResSpacePer->setObjectName(QString::fromUtf8("label_ResSpacePer"));
        label_ResSpacePer->setMinimumSize(QSize(100, 30));
        label_ResSpacePer->setMaximumSize(QSize(100, 30));
        label_ResSpacePer->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        m_HLayoutDetectionDis_8->addWidget(label_ResSpacePer);


        verticalLayout->addLayout(m_HLayoutDetectionDis_8);

        m_HLayoutDetectionDis_9 = new QHBoxLayout();
        m_HLayoutDetectionDis_9->setSpacing(20);
        m_HLayoutDetectionDis_9->setObjectName(QString::fromUtf8("m_HLayoutDetectionDis_9"));
        m_csLnDetectionDistce_9 = new QLabel(DB_Metrics);
        m_csLnDetectionDistce_9->setObjectName(QString::fromUtf8("m_csLnDetectionDistce_9"));
        m_csLnDetectionDistce_9->setMinimumSize(QSize(140, 30));
        m_csLnDetectionDistce_9->setFont(font);
        m_csLnDetectionDistce_9->setStyleSheet(QString::fromUtf8(""));
        m_csLnDetectionDistce_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        m_HLayoutDetectionDis_9->addWidget(m_csLnDetectionDistce_9);

        label_USpace = new QLabel(DB_Metrics);
        label_USpace->setObjectName(QString::fromUtf8("label_USpace"));
        label_USpace->setMinimumSize(QSize(100, 30));
        label_USpace->setMaximumSize(QSize(100, 30));
        label_USpace->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        m_HLayoutDetectionDis_9->addWidget(label_USpace);


        verticalLayout->addLayout(m_HLayoutDetectionDis_9);

        m_HLayoutDetectionDis_10 = new QHBoxLayout();
        m_HLayoutDetectionDis_10->setSpacing(20);
        m_HLayoutDetectionDis_10->setObjectName(QString::fromUtf8("m_HLayoutDetectionDis_10"));
        m_csLnDetectionDistce_10 = new QLabel(DB_Metrics);
        m_csLnDetectionDistce_10->setObjectName(QString::fromUtf8("m_csLnDetectionDistce_10"));
        m_csLnDetectionDistce_10->setMinimumSize(QSize(140, 30));
        m_csLnDetectionDistce_10->setFont(font);
        m_csLnDetectionDistce_10->setStyleSheet(QString::fromUtf8(""));
        m_csLnDetectionDistce_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        m_HLayoutDetectionDis_10->addWidget(m_csLnDetectionDistce_10);

        label_USpacePer = new QLabel(DB_Metrics);
        label_USpacePer->setObjectName(QString::fromUtf8("label_USpacePer"));
        label_USpacePer->setMinimumSize(QSize(100, 30));
        label_USpacePer->setMaximumSize(QSize(100, 30));
        label_USpacePer->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        m_HLayoutDetectionDis_10->addWidget(label_USpacePer);


        verticalLayout->addLayout(m_HLayoutDetectionDis_10);

        m_HLayoutDetectionDis_11 = new QHBoxLayout();
        m_HLayoutDetectionDis_11->setSpacing(20);
        m_HLayoutDetectionDis_11->setObjectName(QString::fromUtf8("m_HLayoutDetectionDis_11"));
        m_csLnDetectionDistce_11 = new QLabel(DB_Metrics);
        m_csLnDetectionDistce_11->setObjectName(QString::fromUtf8("m_csLnDetectionDistce_11"));
        m_csLnDetectionDistce_11->setMinimumSize(QSize(140, 30));
        m_csLnDetectionDistce_11->setFont(font);
        m_csLnDetectionDistce_11->setStyleSheet(QString::fromUtf8(""));
        m_csLnDetectionDistce_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        m_HLayoutDetectionDis_11->addWidget(m_csLnDetectionDistce_11);

        label_dStoreInDataTable = new QLabel(DB_Metrics);
        label_dStoreInDataTable->setObjectName(QString::fromUtf8("label_dStoreInDataTable"));
        label_dStoreInDataTable->setMinimumSize(QSize(100, 30));
        label_dStoreInDataTable->setMaximumSize(QSize(100, 30));
        label_dStoreInDataTable->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        m_HLayoutDetectionDis_11->addWidget(label_dStoreInDataTable);


        verticalLayout->addLayout(m_HLayoutDetectionDis_11);

        m_HLayoutDetectionDis_12 = new QHBoxLayout();
        m_HLayoutDetectionDis_12->setSpacing(20);
        m_HLayoutDetectionDis_12->setObjectName(QString::fromUtf8("m_HLayoutDetectionDis_12"));
        m_csLnDetectionDistce_12 = new QLabel(DB_Metrics);
        m_csLnDetectionDistce_12->setObjectName(QString::fromUtf8("m_csLnDetectionDistce_12"));
        m_csLnDetectionDistce_12->setMinimumSize(QSize(140, 30));
        m_csLnDetectionDistce_12->setFont(font);
        m_csLnDetectionDistce_12->setStyleSheet(QString::fromUtf8(""));
        m_csLnDetectionDistce_12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        m_HLayoutDetectionDis_12->addWidget(m_csLnDetectionDistce_12);

        label_ASpace = new QLabel(DB_Metrics);
        label_ASpace->setObjectName(QString::fromUtf8("label_ASpace"));
        label_ASpace->setMinimumSize(QSize(100, 30));
        label_ASpace->setMaximumSize(QSize(100, 30));
        label_ASpace->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        m_HLayoutDetectionDis_12->addWidget(label_ASpace);


        verticalLayout->addLayout(m_HLayoutDetectionDis_12);

        m_HLayoutDetectionDis_13 = new QHBoxLayout();
        m_HLayoutDetectionDis_13->setSpacing(20);
        m_HLayoutDetectionDis_13->setObjectName(QString::fromUtf8("m_HLayoutDetectionDis_13"));
        m_csLnDetectionDistce_13 = new QLabel(DB_Metrics);
        m_csLnDetectionDistce_13->setObjectName(QString::fromUtf8("m_csLnDetectionDistce_13"));
        m_csLnDetectionDistce_13->setMinimumSize(QSize(140, 30));
        m_csLnDetectionDistce_13->setFont(font);
        m_csLnDetectionDistce_13->setStyleSheet(QString::fromUtf8(""));
        m_csLnDetectionDistce_13->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        m_HLayoutDetectionDis_13->addWidget(m_csLnDetectionDistce_13);

        label_ASpacePer = new QLabel(DB_Metrics);
        label_ASpacePer->setObjectName(QString::fromUtf8("label_ASpacePer"));
        label_ASpacePer->setMinimumSize(QSize(100, 30));
        label_ASpacePer->setMaximumSize(QSize(100, 30));
        label_ASpacePer->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        m_HLayoutDetectionDis_13->addWidget(label_ASpacePer);


        verticalLayout->addLayout(m_HLayoutDetectionDis_13);


        verticalLayout_2->addLayout(verticalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(DB_Metrics);

        QMetaObject::connectSlotsByName(DB_Metrics);
    } // setupUi

    void retranslateUi(QWidget *DB_Metrics)
    {
        DB_Metrics->setWindowTitle(QCoreApplication::translate("DB_Metrics", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("DB_Metrics", "Close", nullptr));
        m_csLnDetectionDistce_3->setText(QCoreApplication::translate("DB_Metrics", "Total disk space is:", nullptr));
        label_tDiskSpace->setText(QString());
        m_csLnDetectionDistce_4->setText(QCoreApplication::translate("DB_Metrics", "Total disk space percentage:", nullptr));
        label_tDiskSpacePer->setText(QString());
        m_csLnDetectionDistce_5->setText(QCoreApplication::translate("DB_Metrics", "Other space is:", nullptr));
        label_OtrSpace->setText(QString());
        m_csLnDetectionDistce_6->setText(QCoreApplication::translate("DB_Metrics", "Other space percentage is:", nullptr));
        label_OtrSpacePer->setText(QString());
        m_csLnDetectionDistce_7->setText(QCoreApplication::translate("DB_Metrics", "Reserved space is:", nullptr));
        label_ResSpace->setText(QString());
        m_csLnDetectionDistce_8->setText(QCoreApplication::translate("DB_Metrics", "Reserved space percentage is:", nullptr));
        label_ResSpacePer->setText(QString());
        m_csLnDetectionDistce_9->setText(QCoreApplication::translate("DB_Metrics", "Used space is:", nullptr));
        label_USpace->setText(QString());
        m_csLnDetectionDistce_10->setText(QCoreApplication::translate("DB_Metrics", "Used space percentage is:", nullptr));
        label_USpacePer->setText(QString());
        m_csLnDetectionDistce_11->setText(QCoreApplication::translate("DB_Metrics", "Number of days the data was stored in data_table:", nullptr));
        label_dStoreInDataTable->setText(QString());
        m_csLnDetectionDistce_12->setText(QCoreApplication::translate("DB_Metrics", "Available space is:", nullptr));
        label_ASpace->setText(QString());
        m_csLnDetectionDistce_13->setText(QCoreApplication::translate("DB_Metrics", "Available space percentage is:", nullptr));
        label_ASpacePer->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DB_Metrics: public Ui_DB_Metrics {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DB_METRICS_H
