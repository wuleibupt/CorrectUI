#ifndef CORRECTUI_H
#define CORRECTUI_H

#include <QtWidgets/QMainWindow>
#include "ui_correctui.h"
#include <QFileDialog>
#include <QDebug>
#include <iostream>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QFileInfo>
#include <QPixmap>
#include <string>
#include "correct.h"
#include <QMessageBox>
#include <QTimer>


using namespace std;

class CorrectUI : public QMainWindow
{
	Q_OBJECT

public:
	CorrectUI(QWidget *parent = 0);
	~CorrectUI();

private:
	QStringList QImgNameList;
	QUrl filePath;
	String newFile;
	QString	paramterName;
	QStringList	fileNames;
	Ui::CorrectUIClass ui;
	Correct correct;
	int i;


signals:
	void imageNameList_SIGNAL();
	void parameterName_SIGNAL();
	void newImage_SIGNAL();
	//void newImage1_SIGNAL();

protected:
	void timerEvent(QTimerEvent *event);

private slots:
	void loadImage_SLOT();
	void imageNameList_SLOT();
	void loadParameter_SLOT();
	void parameterName_SLOT();
	void clearALL_SLOT();
	void imageShow_SLOT();
	void correct_SLOT();
	//void imageShow1_SLOT();

};

#endif // CORRECTUI_H
