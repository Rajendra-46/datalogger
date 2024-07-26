/********************************************************************************
** Form generated from reading UI file 'datarecord.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATARECORD_H
#define UI_DATARECORD_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DataRecord
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_16;
    QToolButton *toolButton;
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *comboBox_Records;
    QPushButton *pushButton_show;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QProgressBar *progressBar;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QWidget *DataRecord)
    {
        if (DataRecord->objectName().isEmpty())
            DataRecord->setObjectName(QString::fromUtf8("DataRecord"));
        DataRecord->resize(1043, 432);
        DataRecord->setStyleSheet(QString::fromUtf8("font: 12pt \"MS Shell Dlg 2\";"));
        verticalLayout_2 = new QVBoxLayout(DataRecord);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(4, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        toolButton = new QToolButton(DataRecord);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"border:none;\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/C_logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon);
        toolButton->setIconSize(QSize(16, 16));

        horizontalLayout_16->addWidget(toolButton);

        label = new QLabel(DataRecord);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setStyleSheet(QString::fromUtf8("color: rgb(204, 0, 0);"));

        horizontalLayout_16->addWidget(label);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer);

        pushButton = new QPushButton(DataRecord);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(85, 27));
        pushButton->setMaximumSize(QSize(85, 27));
        QFont font;
        font.setFamily(QString::fromUtf8("Open Sans"));
        font.setPointSize(10);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        pushButton->setFont(font);
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

        tableWidget = new QTableWidget(DataRecord);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setRowCount(0);
        tableWidget->setColumnCount(4);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget->horizontalHeader()->setMinimumSectionSize(50);
        tableWidget->horizontalHeader()->setDefaultSectionSize(300);

        verticalLayout->addWidget(tableWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(20);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 4, -1, 4);
        comboBox_Records = new QComboBox(DataRecord);
        comboBox_Records->setObjectName(QString::fromUtf8("comboBox_Records"));
        comboBox_Records->setMinimumSize(QSize(250, 30));

        horizontalLayout_2->addWidget(comboBox_Records);

        pushButton_show = new QPushButton(DataRecord);
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

        horizontalLayout_2->addWidget(pushButton_show);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(3, 0, 0, -1);
        label_2 = new QLabel(DataRecord);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        progressBar = new QProgressBar(DataRecord);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setMinimumSize(QSize(344, 30));
        progressBar->setMaximum(100);
        progressBar->setValue(0);

        horizontalLayout->addWidget(progressBar);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        horizontalLayout_2->addLayout(horizontalLayout);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(DataRecord);

        QMetaObject::connectSlotsByName(DataRecord);
    } // setupUi

    void retranslateUi(QWidget *DataRecord)
    {
        DataRecord->setWindowTitle(QCoreApplication::translate("DataRecord", "Form", nullptr));
        toolButton->setText(QCoreApplication::translate("DataRecord", "...", nullptr));
        label->setText(QCoreApplication::translate("DataRecord", "KONECRANES", nullptr));
        pushButton->setText(QCoreApplication::translate("DataRecord", "Close", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("DataRecord", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("DataRecord", "Count", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("DataRecord", "First Record", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("DataRecord", "Last Record", nullptr));
        pushButton_show->setText(QCoreApplication::translate("DataRecord", "Show", nullptr));
        label_2->setText(QCoreApplication::translate("DataRecord", "Status :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DataRecord: public Ui_DataRecord {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATARECORD_H
