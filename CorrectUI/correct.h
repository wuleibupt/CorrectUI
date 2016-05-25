#ifndef CORRECT_H
#define CORRECT_H
#include <opencv2/opencv.hpp>
#include <vector>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <list>
#include <QDebug>
#include <QTextStream>
#define M_PI       3.14159265358979323846
#define picnum 30

using namespace std;
using namespace cv;
class Correct
{
private:
	double ze;
	double fx;
	double d;
	double tx,ty,tz,rx,ry,rz;
	Mat H;
	Mat H2;
	float kh,kw;
	int height;
	int width;
	Mat src;
	Mat dst;
	Mat warp_mat;
	string temp[picnum];
	Point2f o;

public:
	double a;
	bool flag;
	string path;
	list<String> fileNameList;
	list<String> newfileNameLsit;
	list<String> parmlist;
	list<String>::iterator it;
	list<String>::iterator it1;
	list<String>::iterator it2;

public:
	Correct(){
		ze=43.546;
		fx=45;
		d=ze*tan(fx*M_PI/180/2)/320;
		H=Mat(4,4,CV_32FC1);
		height=480;
		width=640;
		it=fileNameList.begin();
		it1=newfileNameLsit.begin();
		it1=newfileNameLsit.begin();
		flag=false;
	}
	void split1(string temp);
	void readdata(string path);
	void readdata1(string path);
	Point2f sMinMat(Point2f o1);
	void parm();
	Point2f cornerTran(Mat point1);
	void point();
	String  correct(string imagename,string parmpath,int i);

};



#endif