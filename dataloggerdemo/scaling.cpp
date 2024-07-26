/*
FileName	:plot
Purpose     :This Files is used to setup the scaling.
Authour     :Gururaj B M / Kasturi Rangan.
*/

#include "scaling.h"
#include "ui_scaling.h"
#include <qdebug.h>
#include <QMessageBox>
#define SCALING "scaling"
#define OFFSET "offset"

Scaling::Scaling(const QStringList &list_parms, const QStringList &list_cmt,
                 const QStringList &list_parmsType, const QStringList &list_scalingFactor,
                 const QStringList &list_offSet,const QString &IPAddress, const QString &Port,const QString &Db,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Scaling)
{
    ui->setupUi(this);
    this->setWindowTitle("Scaling");

    Str_IPAddress = IPAddress;
    Str_port = Port;
    Str_DbName = Db;

    groupWidget = new QWidget();
    groupWidget->setGeometry(250,250,400,150);
    groupWidget->setFixedSize(400,150);
    groupWidget->setWindowTitle("Save group name as...");
    groupWidget->setStyleSheet("QWidget{font: 12pt;font-family:MS Shell Dlg 2;};");

    QLabel *lb = new QLabel("Enter group name");
    lEdt = new QLineEdit();
    QString str_Validator = "[0-9A-Za-z_-]{0,30}";
    lEdt->setValidator(new QRegExpValidator(QRegExp(str_Validator)));
    //lEdt->setFixedSize(150,30);

    QHBoxLayout *HLayout = new QHBoxLayout();
    HLayout->addWidget(lb);
    HLayout->addWidget(lEdt);

    QPushButton *okBtn = new QPushButton("Ok");
    connect(okBtn, SIGNAL(clicked()), this, SLOT(saveGroupWidget()));
    QPushButton *cancelBtn = new QPushButton("Cancel");
    connect(cancelBtn, SIGNAL(clicked()), this, SLOT(closeGroupWidget()));

    QHBoxLayout *H1Layout = new QHBoxLayout();
    H1Layout->addWidget(okBtn);
    H1Layout->addWidget(cancelBtn);

    QVBoxLayout *VLayout = new QVBoxLayout();
    VLayout->addLayout(HLayout);
    VLayout->addLayout(H1Layout);

    groupWidget->setLayout(VLayout);
    //============================================
    strList_ParameterName = list_parms;
    strList_cmt = list_cmt;
    strList_ParameterType = list_parmsType;
    strList_ScallingFactor = list_scalingFactor;
    strList_offSet = list_offSet;
    QString strName, strComment, strType, strscalingFactor,stroffset;
    int i = 0;
    for(i=0; i< strList_ParameterName.size(); i++)
    {

        strName = strList_ParameterName.at(i);
        strComment = strList_cmt.at(i);
        strType = strList_ParameterType.at(i);
        strscalingFactor = strList_ScallingFactor.at(i);
        stroffset = strList_offSet.at(i);

        if(strType != "BOOL")
        {
            //strEntry = strName +" (" + strComment + ")";
            strList_ntParameterName << strName;
            strList_ntcmt << strComment;
            strList_ntParameterType << strType;
            strList_ntScallingFactor << strscalingFactor;
            strList_ntoffSet << stroffset;
        }
    }

    FillDataToTable();
    ReloadLocalCustomScaleValues();
    SavedGroupNames();
}

Scaling::~Scaling()
{
    delete ui;
}
/**************************************************************************************************
    Function Name       : FillDataToTable
    Brief Description   : This function is used to Fill Data To Table.
    Input               : ---
    Return value        : void
**************************************************************************************************/
void Scaling::FillDataToTable()
{
    ui->tableWidget->setRowCount(0);
    int i=0;
    while(i < strList_ntParameterName.length())
    {
        ui->tableWidget->insertRow(i);

        QTableWidgetItem *item;
        // ui->tableWidget->insertColumn(i);
        QString parameter_name = strList_ntParameterName.at(i);
        QString parameter_data_type = strList_ntParameterType.at(i);
        QString comment = strList_ntcmt.at(i);
        QString scaling_factor = strList_ntScallingFactor.at(i);
        QString Default_offset = strList_ntoffSet.at(i);


        item = new QTableWidgetItem(parameter_name);
        item->setFlags(item->flags() & ~Qt::ItemIsEditable); // non editable
        ui->tableWidget->setItem(i,0,item);

        item = new QTableWidgetItem(parameter_data_type);
        item->setFlags(item->flags() & ~Qt::ItemIsEditable); // non editable
        ui->tableWidget->setItem(i,1,item);

        item = new QTableWidgetItem(comment);
        item->setFlags(item->flags() & ~Qt::ItemIsEditable); // non editable
        ui->tableWidget->setItem(i,2,item);

        item = new QTableWidgetItem(scaling_factor);
        item->setFlags(item->flags() & ~Qt::ItemIsEditable); // non editable
        item->setTextAlignment(Qt::AlignRight);
        ui->tableWidget->setItem(i,3,item);

        edit=new QLineEdit();
        edit->setText(strList_ntScallingFactor.at(i));
        edit->setAlignment(Qt::AlignRight);
        QRegExp rx("^(-?[0]|-?[1-9][0-9]{0,5})(?:\\.\\d{1,4})?$|(^\\t?$)");
        QRegExpValidator *pReg = new QRegExpValidator(rx, this);
        edit->setValidator(pReg);
        ui->tableWidget->setCellWidget(i,4,edit);
        connect(edit,SIGNAL(editingFinished()),this,SLOT(editedvalue()));

        item = new QTableWidgetItem(Default_offset);
        item->setFlags(item->flags() & ~Qt::ItemIsEditable); // non editable
        item->setTextAlignment(Qt::AlignRight);
        ui->tableWidget->setItem(i,5,item);

        edit_offset=new QLineEdit();  //custom offset
        edit_offset->setText(strList_ntoffSet.at(i));
        edit_offset->setAlignment(Qt::AlignRight);
        QRegExp rx_offset("^(-?[0]|-?[1-9][0-9]{0,5})(?:\\.\\d{1,4})?$|(^\\t?$)");
        QRegExpValidator *pReg_offset = new QRegExpValidator(rx_offset, this);
        edit_offset->setValidator(pReg_offset);
        ui->tableWidget->setCellWidget(i,6,edit_offset);
        connect(edit_offset,SIGNAL(editingFinished()),this,SLOT(editedvalue()));

        m_pushbtn = new QPushButton(); // clear custom scalling
        m_pushbtn->setText("clear scale value");
        // m_pushbtn->setStyleSheet("background-color: red");
        ui->tableWidget->setCellWidget(i,7,m_pushbtn);
        connect(m_pushbtn,SIGNAL(clicked()),this,SLOT(PushBtnClicked()));

        m_pushbtn_offset = new QPushButton(); // clear custom offset
        m_pushbtn_offset->setText("clear offset value");
        // m_pushbtn_offset->setStyleSheet("background-color: red");
        ui->tableWidget->setCellWidget(i,8,m_pushbtn_offset);
        connect(m_pushbtn_offset,SIGNAL(clicked()),this,SLOT(PushBtnClicked_Offset()));

        QWidget *pWidget = new QWidget();
        m_chckBox = new QCheckBox();
        QHBoxLayout *pLayout = new QHBoxLayout(pWidget);
        pLayout->addWidget(m_chckBox);
        pLayout->setAlignment(Qt::AlignCenter);
        pLayout->setContentsMargins(0,0,0,0);
        pWidget->setLayout(pLayout);
        ui->tableWidget->setCellWidget(i,9,pWidget);
        i++;
    }
}
/**************************************************************************************************
    Function Name       : PushBtnClicked
    Brief Description   : This function is used to clear the custom scaled values.
    Input               : ---
    Return value        : void
**************************************************************************************************/
void Scaling::PushBtnClicked()
{
    QWidget *w = qobject_cast<QWidget *>(sender());
    if(w)
    {
        row1 = ui->tableWidget->indexAt(w->pos()).row();
        col1 = ui->tableWidget->indexAt(w->pos()).column();

        QString parameter_name = ui->tableWidget->item(row1,0)->text();
        ((QLineEdit*)(ui->tableWidget->cellWidget(row1,4)))->setText("1");

        QSettings settings("Finecho_Scaling","Scaling_Details");
        settings.beginGroup(SCALING);
        foreach (const QString &key, settings.childKeys())
        {
            if(parameter_name.simplified() == key.simplified() )
            {
                settings.remove(key);
                ((QLineEdit*)(ui->tableWidget->cellWidget(row1,4)))->setText("1");
            }
        }
        settings.endGroup();

    }
}
/**************************************************************************************************
    Function Name       : PushBtnClicked_Offset
    Brief Description   : This function is used to clear the custom offset values.
    Input               : ---
    Return value        : void
**************************************************************************************************/
void Scaling::PushBtnClicked_Offset()
{
    QWidget *w = qobject_cast<QWidget *>(sender());
    if(w)
    {
        row1 = ui->tableWidget->indexAt(w->pos()).row();
        col1 = ui->tableWidget->indexAt(w->pos()).column();

        QString parameter_name = ui->tableWidget->item(row1,0)->text();
        ((QLineEdit*)(ui->tableWidget->cellWidget(row1,6)))->setText("0");

        QSettings settings_offset("Finecho_offset","offset_Details");
        settings_offset.beginGroup(OFFSET);
        foreach (const QString &key, settings_offset.childKeys())
        {
            if(parameter_name.simplified() == key.simplified() )
            {
                settings_offset.remove(key);
                ((QLineEdit*)(ui->tableWidget->cellWidget(row1,6)))->setText("0");
            }
        }
        settings_offset.endGroup();
    }
}

/**************************************************************************************************
    Function Name       : editedvalue
    Brief Description   : This function is used to grab the edited values.
    Input               : ---
    Return value        : void
**************************************************************************************************/
void Scaling::editedvalue()
{
    QWidget *w = qobject_cast<QWidget *>(sender());
    if(w)
    {
        row = ui->tableWidget->indexAt(w->pos()).row();
        col = ui->tableWidget->indexAt(w->pos()).column();
        str = ((QLineEdit*)(ui->tableWidget->cellWidget(row,col)))->text();

        QString parameter_value = ui->tableWidget->item(row,0)->text();

    }
}
/**************************************************************************************************
    Function Name       : ReloadLocalCustomScaleValues
    Brief Description   : This function is used to Reload the Local Custom Scale Values.
    Input               : ---
    Return value        : void
**************************************************************************************************/
void Scaling::ReloadLocalCustomScaleValues()
{
    QSettings settings("Finecho_Scaling","Scaling_Details");
    settings.beginGroup(SCALING);
    foreach (const QString &key, settings.childKeys())
    {
        QString k_val = key;
        QString value = settings.value(key).toString();
        ScaleRevalmap.insert(k_val,value);
    }
    settings.endGroup();
    for (QMap<QString, QString>::const_iterator it = ScaleRevalmap.cbegin(), end = ScaleRevalmap.cend(); it != end; ++it)
    {
        QString searchtext = it.key().simplified();
        for (int i=0; i< ui->tableWidget->rowCount(); ++i)
        {
            QString searchtext1 = ui->tableWidget->item(i, 0)->text();
            if(ui->tableWidget->item(i, 0)->text() == searchtext)
            {
                ((QLineEdit*)(ui->tableWidget->cellWidget(i,4)))->setText(*it);
            }
        }
    }
    //===============offset======================================

    QSettings settings_offset("Finecho_offset","offset_Details");
    settings_offset.beginGroup(OFFSET);
    foreach (const QString &key, settings_offset.childKeys())
    {
        QString k_val = key;
        QString value = settings_offset.value(key).toString();
        ScaleOffsetmap.insert(k_val,value);
    }
    settings_offset.endGroup();
    for (QMap<QString, QString>::const_iterator it = ScaleOffsetmap.cbegin(), end = ScaleOffsetmap.cend(); it != end; ++it)
    {
        QString searchtext = it.key().simplified();
        for (int i=0; i< ui->tableWidget->rowCount(); ++i)
        {
            QString searchtext1 = ui->tableWidget->item(i, 0)->text();
            if(ui->tableWidget->item(i, 0)->text() == searchtext)
            {
                ((QLineEdit*)(ui->tableWidget->cellWidget(i,6)))->setText(*it);
            }
        }
    }
}

/**************************************************************************************************
    Function Name       : on_m_PshBtn_Save_clicked
    Brief Description   : This function is used to save Custom Scale Values.
    Input               : ---
    Return value        : void
**************************************************************************************************/
void Scaling::on_m_PshBtn_Save_clicked()
{
    int nCreateFlag = 0;
    QMessageBox qmsgMessageBox;
    nCreateFlag = qmsgMessageBox.warning(this,"SAVE...","Do You Want to Save the values",QMessageBox::Yes, QMessageBox::No);
    if(nCreateFlag == QMessageBox::Yes)
    {
        strlstparm.clear();
        strlstval.clear();
        strlstparm_offset.clear();
        strlstval_offset.clear();

        for (int i=0; i< ui->tableWidget->rowCount(); ++i)
        {
            QString searchtextDefault = ui->tableWidget->item(i, 3)->text();
            QString searchtextCustom = ((QLineEdit*)(ui->tableWidget->cellWidget(i,4)))->text();
            QString searchtextDefault_offset = ui->tableWidget->item(i, 5)->text();
            QString searchtextCustom_offset = ((QLineEdit*)(ui->tableWidget->cellWidget(i,6)))->text();
            //direct==================
            QString paramname = ui->tableWidget->item(i, 0)->text();
            QString CustomVal = ((QLineEdit*)(ui->tableWidget->cellWidget(i,4)))->text();
            strlstparm << paramname;
            strlstval << CustomVal;

            QString paramname_offset = ui->tableWidget->item(i, 0)->text();
            QString CustomVal_offset = ((QLineEdit*)(ui->tableWidget->cellWidget(i,6)))->text();
            strlstparm_offset << paramname_offset;
            strlstval_offset << CustomVal_offset;
        }
        QSettings settings("Finecho_Scaling","Scaling_Details");
        settings.beginGroup(SCALING);
        for(int i=0;i<strlstparm.length();i++)
        {
            settings.setValue(strlstparm.at(i), strlstval.at(i));
        }
        settings.endGroup();

        QSettings settings_offset("Finecho_offset","offset_Details");
        settings_offset.beginGroup(OFFSET);
        for(int i=0;i<strlstparm_offset.length();i++)
        {
            settings_offset.setValue(strlstparm_offset.at(i), strlstval_offset.at(i));
        }
        settings_offset.endGroup();
    }

}
void Scaling::on_pushButton_NewGroup_clicked()
{
    lEdt->clear();
    groupWidget->show();
    groupWidget->activateWindow();
}
void Scaling::saveGroupWidget()
{
    strList_saveGroup_param.clear();
    strList_saveGroup_scaling.clear();
    strList_saveGroup_offset.clear();
    QString GroupName= lEdt->text();
    if(GroupName == ""){
        QMessageBox msgBox;
        msgBox.setText("Please enter the group name");
        msgBox.exec();
        return;
    }

    for (int i = 0; i <ui->tableWidget->rowCount(); i++)
    {
        QWidget *pWidget = ui->tableWidget->cellWidget(i, 9);
        QCheckBox *checkbox = pWidget->findChild<QCheckBox *>();
        if (checkbox && checkbox->isChecked())
        {
            QString param_name = ui->tableWidget->item(i, 0)->text();
            QString searchtextCustom_Scaling = ((QLineEdit*)(ui->tableWidget->cellWidget(i,4)))->text();
            QString searchtextCustom_offset = ((QLineEdit*)(ui->tableWidget->cellWidget(i,6)))->text();
            strList_saveGroup_param << param_name;
            strList_saveGroup_scaling << searchtextCustom_Scaling;
            strList_saveGroup_offset << searchtextCustom_offset;
            //  qDebug() << "row=====" << i;
        }
    }
    if(strList_saveGroup_param.length() <= 0)
    {
        QMessageBox msgBox;
        msgBox.setText("Select atlest one parameter to Save the group");
        closeGroupWidget();
        msgBox.exec();
        return;
    }
    QString filename = qApp->applicationDirPath()+"/"+Str_IPAddress+"-"+Str_DbName+".txt";
    qDebug() << "filename===" << filename;
    QFile file(filename);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
    {
        QTextStream stream(&file);
        stream << GroupName.append(':');
        for (int i=0;i<strList_saveGroup_param.length();i++)
        {
            stream << strList_saveGroup_param.at(i) << "," << strList_saveGroup_scaling.at(i) << "," << strList_saveGroup_offset.at(i) << ";";
        }
        stream << "|" << endl;
    }
    //file.flush();
    file.close();
    // ui->comboBox_saveGroups->addItem(GroupName);
    QMessageBox msgBox;
    msgBox.setText("Group name saved sucessfully");
    msgBox.exec();
    groupWidget->close();

    QFile file_open(qApp->applicationDirPath()+"/"+Str_IPAddress+"-"+Str_DbName+".txt");
    if(!file_open.open(QFile::ReadOnly |
                       QFile::Text))
    {
        qDebug() << " Could not open the file for reading";
        return;
    }
    QTextStream in(&file_open);
    QString myText1 = in.readAll();
    QString myText2 = myText1.trimmed();
    QString myText = myText2.simplified();
    file_open.close();
    ui->comboBox_saveGroups->clear();
    QStringList str_lst = myText.split('|');
    for (int i=0;i < str_lst.length()-1;i++)
    {
        QStringList val = str_lst.at(i).split(':');
        ui->comboBox_saveGroups->addItem(val.at(0).simplified());
    }
    emit addGroupName(lEdt->text().trimmed());
    //clear selected checkboxs==============
    //    for (int i=0; i< ui->tableWidget->rowCount(); ++i)
    //    {
    //        QWidget *pWidget = ui->tableWidget->cellWidget(i, 9);
    //        QCheckBox *checkbox = pWidget->findChild<QCheckBox *>();
    //        if (checkbox && checkbox->isChecked())
    //        {
    //            checkbox->setChecked(false);
    //        }
    //    }
    on_pushButton_ClearValue_clicked();
    lEdt->clear();
}
void Scaling::SavedGroupNames()
{
    QFile file(qApp->applicationDirPath()+"/"+Str_IPAddress+"-"+Str_DbName+".txt");
    qDebug() << "file" << file.fileName();
    if(!file.open(QFile::ReadOnly |
                  QFile::Text))
    {
        qDebug() << " Could not open the file for reading";
        return;
    }
    QTextStream in(&file);
    QString myText1 = in.readAll();
    QString myText2 = myText1.trimmed();
    QString myText = myText2.simplified();
    file.close();

    QString savedGroup = ui->comboBox_saveGroups->currentText();
    QStringList str_lst = myText.split('|');
    for (int i=0;i < str_lst.length()-1;i++)
    {
        QStringList val = str_lst.at(i).split(':');
        ui->comboBox_saveGroups->addItem(val.at(0).simplified());
    }
}
void Scaling::closeGroupWidget()
{
    groupWidget->close();
}

void Scaling::on_comboBox_saveGroups_currentIndexChanged(const QString &arg1)
{

}
void Scaling::on_pushButton_show_clicked()
{
    QFile file(qApp->applicationDirPath()+"/"+Str_IPAddress+"-"+Str_DbName+".txt");
    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug() << " Could not open the file for reading";
        return;
    }
    QTextStream in(&file);
    QString myText1 = in.readAll();
    QString myText2 = myText1.trimmed();
    QString myText = myText2.simplified();

    file.close();
    params.clear();
    scale.clear();
    offset.clear();
    QString savedGroup = ui->comboBox_saveGroups->currentText();
    if(savedGroup == ""){
        QMessageBox msgBox;
        msgBox.setText("Please select the group name");
        msgBox.exec();
        return;
    }

    QStringList str_lst = myText.split('|');

    for (int i=0;i < str_lst.length()-1;i++)
    {
        QStringList val = str_lst.at(i).split(':');
        if(val.at(0).simplified() == savedGroup)
        {
            QStringList strlstfnl = val.at(1).split(';');
            for (int i=0;i < strlstfnl.length()-1;i++)
            {
                QStringList strlstfnlval = strlstfnl.at(i).split(',');
                params << strlstfnlval.at(0);
                scale  << strlstfnlval.at(1);
                offset << strlstfnlval.at(2);
            }
        }
    }
    on_pushButton_ClearValue_clicked();
    for (int i=0;i < params.length();i++)
    {
        for (int j = 0; j <ui->tableWidget->rowCount(); j++)
        {
            QString param_name = ui->tableWidget->item(j, 0)->text();
            if(param_name == params.at(i))
            {
                ((QLineEdit*)(ui->tableWidget->cellWidget(j,4)))->setText(scale.at(i));
                ((QLineEdit*)(ui->tableWidget->cellWidget(j,6)))->setText(offset.at(i));

                QWidget *pWidget = ui->tableWidget->cellWidget(j, 9);
                QCheckBox *checkbox = pWidget->findChild<QCheckBox *>();
                checkbox->setChecked(true);
            }
        }
    }

    //    saveWidget = new QWidget();
    //    saveWidget->setGeometry(250,250,340,300);
    //    saveWidget->setFixedSize(340,300);
    //    saveWidget->setWindowTitle("Saved groups");

    //    QTableWidget *filesTable = new QTableWidget(0, 3);
    //    QStringList labels;
    //    labels << tr("Parameter Name") << tr("Custom scaling")  << tr("offset scaling");
    //    filesTable->setHorizontalHeaderLabels(labels);
    //    //    filesTable->horizontalHeader()->setResizeMode(0, QHeaderView::Stretch);
    //    //    filesTable->verticalHeader()->hide();
    //    filesTable->setShowGrid(true);
    //    //===================================================
    //    filesTable->clearContents();
    //    int i=0;
    //    while(i < params.length())
    //    {
    //        filesTable->insertRow(i);

    //        QTableWidgetItem *item;

    //        item = new QTableWidgetItem(params.at(i));
    //        item->setFlags(item->flags() & ~Qt::ItemIsEditable); // non editable
    //        filesTable->setItem(i,0,item);

    //        item = new QTableWidgetItem(scale.at(i));
    //        item->setFlags(item->flags() & ~Qt::ItemIsEditable); // non editable
    //        filesTable->setItem(i,1,item);

    //        item = new QTableWidgetItem(offset.at(i));
    //        item->setFlags(item->flags() & ~Qt::ItemIsEditable); // non editable
    //        filesTable->setItem(i,2,item);

    //        i++;
    //    }
    //    QVBoxLayout *VLayout = new QVBoxLayout();
    //    VLayout->addWidget(filesTable);
    //    saveWidget->setLayout(VLayout);
    //    saveWidget->show();
}

void Scaling::on_pushButton_Delete_clicked()
{
    QString savedGroup = ui->comboBox_saveGroups->currentText();
    if(savedGroup == ""){
        QMessageBox msgBox;
        msgBox.setText("Please select the group name");
        msgBox.exec();
        return;
    }
    int nCreateFlag = 0;
    QMessageBox qmsgMessageBox;
    nCreateFlag = qmsgMessageBox.warning(this,"DELETE!","Do You Want to delete group name:" + savedGroup,QMessageBox::Yes, QMessageBox::No);
    if(nCreateFlag == QMessageBox::Yes)
    {
        QFile file(qApp->applicationDirPath()+"/"+Str_IPAddress+"-"+Str_DbName+".txt");
        if(!file.open(QFile::ReadOnly |
                      QFile::Text))
        {
            qDebug() << " Could not open the file for reading";
            return;
        }
        QTextStream in(&file);
        QString myText1 = in.readAll();
        QString myText2 = myText1.trimmed();
        QString myText = myText2.simplified();
        file.close();
        QString str_deleted;

        int n = savedGroup.length();
        QStringList str_lst = myText.split('|');
        for (int i=0;i < str_lst.length()-1;i++)
        {
            QString str = str_lst.at(i).trimmed();
            QString strV = str.mid(0,n);
            if(strV == savedGroup)
            {

            }
            else
            {
                str_deleted.append(str_lst.at(i).trimmed());
                str_deleted.append('|');
            }
        }

        QString filename = qApp->applicationDirPath()+"/"+Str_IPAddress+"-"+Str_DbName+".txt";
        QFile file_del(filename);
        if (file_del.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QTextStream stream(&file_del);
            stream << str_deleted;
        }
        file_del.close();
        ui->comboBox_saveGroups->removeItem(ui->comboBox_saveGroups->currentIndex());
        emit deleteGroupName(savedGroup.trimmed());
        //clear selected checkboxs==============
        for (int i=0; i< ui->tableWidget->rowCount(); ++i)
        {
            QWidget *pWidget = ui->tableWidget->cellWidget(i, 9);
            QCheckBox *checkbox = pWidget->findChild<QCheckBox *>();
            if (checkbox && checkbox->isChecked())
            {
                checkbox->setChecked(false);
            }
        }
    }
}

void Scaling::on_pushButton_ClearValue_clicked()
{
    for (int i=0; i< ui->tableWidget->rowCount(); ++i)
    {
        QWidget *pWidget = ui->tableWidget->cellWidget(i, 9);
        QCheckBox *checkbox = pWidget->findChild<QCheckBox *>();
        if (checkbox && checkbox->isChecked())
        {
            checkbox->setChecked(false);
        }
        ((QLineEdit*)(ui->tableWidget->cellWidget(i,4)))->setText("1");
        ((QLineEdit*)(ui->tableWidget->cellWidget(i,6)))->setText("0");
    }
    //    QSettings settings_offset("Finecho_offset","offset_Details");
    //    settings_offset.beginGroup(OFFSET);
    //    foreach (const QString &key, settings_offset.childKeys())
    //    {
    //       settings_offset.remove(key);
    //    }
    //    settings_offset.endGroup();

    //    QSettings settings("Finecho_Scaling","Scaling_Details");
    //    settings.beginGroup(SCALING);
    //    foreach (const QString &key, settings.childKeys())
    //    {
    //       settings.remove(key);
    //    }
    //    settings.endGroup();
}

void Scaling::on_pushButton_update_clicked()
{
    QString savedGroup = ui->comboBox_saveGroups->currentText();
    if(savedGroup == ""){
        QMessageBox msgBox;
        msgBox.setText("Please select the group name");
        msgBox.exec();
        return;
    }
    int nCreateFlag = 0;
    QMessageBox qmsgMessageBox;
    nCreateFlag = qmsgMessageBox.warning(this,"Update!","Do You Want to update group name:" + savedGroup,QMessageBox::Yes, QMessageBox::No);
    if(nCreateFlag == QMessageBox::Yes)
    {
        QFile file(qApp->applicationDirPath()+"/"+Str_IPAddress+"-"+Str_DbName+".txt");
        if(!file.open(QFile::ReadOnly |
                      QFile::Text))
        {
            qDebug() << " Could not open the file for reading";
            return;
        }
        QTextStream in(&file);
        QString myText1 = in.readAll();
        QString myText2 = myText1.trimmed();
        QString myText = myText2.simplified();
        file.close();
        QString str_deleted;

        int n = savedGroup.length();
        QStringList str_lst = myText.split('|');
        for (int i=0;i < str_lst.length()-1;i++)
        {
            QString str = str_lst.at(i).trimmed();
            QString strV = str.mid(0,n);
            if(strV == savedGroup)
            {

            }
            else
            {
                str_deleted.append(str_lst.at(i).trimmed());
                str_deleted.append('|');
            }
        }
        strList_saveGroup_param.clear();
        strList_saveGroup_scaling.clear();
        strList_saveGroup_offset.clear();

        for (int i = 0; i <ui->tableWidget->rowCount(); i++)
        {
            QWidget *pWidget = ui->tableWidget->cellWidget(i, 9);
            QCheckBox *checkbox = pWidget->findChild<QCheckBox *>();
            if (checkbox && checkbox->isChecked())
            {
                QString param_name = ui->tableWidget->item(i, 0)->text();
                QString searchtextCustom_Scaling = ((QLineEdit*)(ui->tableWidget->cellWidget(i,4)))->text();
                QString searchtextCustom_offset = ((QLineEdit*)(ui->tableWidget->cellWidget(i,6)))->text();
                strList_saveGroup_param << param_name;
                strList_saveGroup_scaling << searchtextCustom_Scaling;
                strList_saveGroup_offset << searchtextCustom_offset;

            }
        }

        QString filename = qApp->applicationDirPath()+"/"+Str_IPAddress+"-"+Str_DbName+".txt";
        QFile file_del(filename);
        if (file_del.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QTextStream stream(&file_del);
            stream << str_deleted;
            stream << savedGroup.append(':');
            for (int i=0;i<strList_saveGroup_param.length();i++)
            {
                stream << strList_saveGroup_param.at(i) << "," << strList_saveGroup_scaling.at(i) << "," << strList_saveGroup_offset.at(i) << ";";
            }
            stream << "|" << endl;
        }
        file_del.close();
        emit updateGroupName();
    }
    //clear selected checkboxs==============
    for (int i=0; i< ui->tableWidget->rowCount(); ++i)
    {
        QWidget *pWidget = ui->tableWidget->cellWidget(i, 9);
        QCheckBox *checkbox = pWidget->findChild<QCheckBox *>();
        if (checkbox && checkbox->isChecked())
        {
            checkbox->setChecked(false);
        }
        ((QLineEdit*)(ui->tableWidget->cellWidget(i,4)))->setText("1");
        ((QLineEdit*)(ui->tableWidget->cellWidget(i,6)))->setText("0");
    }
}

void Scaling::on_chbx_All_saved_group_clicked(bool checked)
{
    if(checked == true)
    {
        strList_saveGroup_param1.clear();
        strList_saveGroup_scaling1.clear();
        strList_saveGroup_offset1.clear();

        for (int i = 0; i <ui->tableWidget->rowCount(); i++)
        {
            QWidget *pWidget = ui->tableWidget->cellWidget(i, 9);
            QCheckBox *checkbox = pWidget->findChild<QCheckBox *>();
            if (checkbox && checkbox->isChecked())
            {
                QString param_name = ui->tableWidget->item(i, 0)->text();
                QString searchtextCustom_Scaling = ((QLineEdit*)(ui->tableWidget->cellWidget(i,4)))->text();
                QString searchtextCustom_offset = ((QLineEdit*)(ui->tableWidget->cellWidget(i,6)))->text();
                strList_saveGroup_param1 << param_name;
                strList_saveGroup_scaling1 << searchtextCustom_Scaling;
                strList_saveGroup_offset1 << searchtextCustom_offset;
            }
            else
            {
                ui->tableWidget->hideRow(i);
            }
        }
    }
    else
    {
        FillDataToTable();
        for (int i=0;i < strList_saveGroup_param1.length();i++)
        {
            for (int j = 0; j <strList_ntParameterName.length(); j++)
            {
                QString param_name = ui->tableWidget->item(j, 0)->text();
                if(param_name == strList_saveGroup_param1.at(i))
                {
                    ((QLineEdit*)(ui->tableWidget->cellWidget(j,4)))->setText(strList_saveGroup_scaling1.at(i));
                    ((QLineEdit*)(ui->tableWidget->cellWidget(j,6)))->setText(strList_saveGroup_offset1.at(i));

                    QWidget *pWidget = ui->tableWidget->cellWidget(j, 9);
                    QCheckBox *checkbox = pWidget->findChild<QCheckBox *>();
                    checkbox->setChecked(true);
                }
            }
        }
    }
}

void Scaling::on_pshBtn_close_clicked()
{
    this->close();
}

void Scaling::on_pushButton_clicked()
{
    this->close();
}
