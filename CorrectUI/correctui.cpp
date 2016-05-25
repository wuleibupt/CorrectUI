#include "correctui.h"
#include <QTimer>
#include <QThread>
#include <QDebug>
#include <QImage>
#include <Windows.h>
#include <QTimer>
#include <correct.h>

CorrectUI::CorrectUI(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	QObject::connect(ui.loadImageButton,SIGNAL(clicked()),this,SLOT(loadImage_SLOT()));
	QObject::connect(this,SIGNAL(imageNameList_SIGNAL()),this,SLOT(imageNameList_SLOT()));
	QObject::connect(ui.loadParameterButton,SIGNAL(clicked()),this,SLOT(loadParameter_SLOT()));
	QObject::connect(this,SIGNAL(parameterName_SIGNAL()),this,SLOT(parameterName_SLOT()));
	QObject::connect(ui.clearButtom,SIGNAL(clicked()),this,SLOT(clearALL_SLOT()));
	QObject::connect(ui.imageNameList,SIGNAL(itemSelectionChanged()),this,SLOT(imageShow_SLOT()));
	QObject::connect(ui.correctButton,SIGNAL(clicked()),this,SLOT(correct_SLOT()));
	i=0;
}

CorrectUI::~CorrectUI()
{

}

void CorrectUI::loadImage_SLOT(){
	fileNames=QFileDialog::getOpenFileNames(this,"open images","/","Images(*.jpg *.bmp)");
	if (fileNames.length()!=0)
	{
		correct.path=QFileInfo(fileNames.at(0)).absolutePath().toStdString();
		for (int i=0;i<fileNames.size();i++)
		{
			correct.fileNameList.push_back(QFileInfo(fileNames.at(i)).fileName().toStdString());
			correct.newfileNameLsit.push_back(QFileInfo(fileNames.at(i)).fileName().toStdString());
		}

		emit imageNameList_SIGNAL();
	}
}

void CorrectUI::imageNameList_SLOT(){
	list<string>::iterator it=correct.fileNameList.begin();
	for (;it!=correct.fileNameList.end();it++)
	{	
		QListWidgetItem* listName=new QListWidgetItem(QString::fromStdString(*it));
		ui.imageNameList->addItem(listName);
	}
}

void CorrectUI::loadParameter_SLOT(){
	paramterName=QFileDialog::getOpenFileName(this,"parmeter txt","/","Text files(*.txt)");
	if (paramterName.length()!=0)
	{
		emit parameterName_SIGNAL();
	}
}

void CorrectUI::parameterName_SLOT(){
	correct.parmlist.clear();
	correct.readdata1(paramterName.toStdString());
	ui.pathEdit->setText(paramterName);
	correct.it2=correct.parmlist.begin();
	qDebug()<<QString::fromStdString(*correct.it2);
}

void CorrectUI::clearALL_SLOT(){
	ui.imageNameList->clear();
	ui.showImageLabel->clear();
	ui.showImageLabel1->clear();
	correct.fileNameList.clear();
	correct.newfileNameLsit.clear();
}

void CorrectUI::imageShow_SLOT(){
	int row=ui.imageNameList->currentRow();
	correct.it=correct.fileNameList.begin();
	advance(correct.it,row);
	QPixmap pix=QPixmap(QString::fromStdString(correct.path+"/"+*(correct.it)));
	ui.showImageLabel->setPixmap(pix.scaled(ui.showImageLabel1->size(),Qt::KeepAspectRatio));
	if(correct.flag){
		correct.it1=correct.newfileNameLsit.begin();
		advance(correct.it1,row);
		ui.showImageLabel1->setPixmap(QPixmap(QString::fromStdString(*correct.it1)).scaled(ui.showImageLabel1->size(),Qt::KeepAspectRatio));
	}
}

void CorrectUI::correct_SLOT(){
	//i=0;
	correct.a=ui.parmEdit->text().toDouble();
	correct.newfileNameLsit.clear();
	correct.it=correct.fileNameList.begin();
	correct.it2=correct.parmlist.begin();
	startTimer(33);
	qDebug()<<"qidong";
}

void CorrectUI::timerEvent(QTimerEvent *event){
	qDebug()<<"jingru1";
	if (i<correct.fileNameList.size()){
		qDebug()<<"jingru2";
		correct.flag=true;
		qDebug()<<i;
		newFile=correct.correct((correct.path+"/"+*correct.it),*correct.it2,i++);
		correct.newfileNameLsit.push_back(newFile);
		ui.showImageLabel->setPixmap(QPixmap(QString::fromStdString(correct.path+"/"+*(correct.it))).scaled(ui.showImageLabel1->size(),Qt::KeepAspectRatio));
		ui.showImageLabel1->setPixmap(QPixmap(QString::fromStdString(newFile)).scaled(ui.showImageLabel1->size(),Qt::KeepAspectRatio));
		correct.it++;
		correct.it2++;
	}
	if(i==correct.fileNameList.size()){
		killTimer(event->timerId());
		i=0;
	}
}
