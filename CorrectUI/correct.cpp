#include "correct.h"
#include <iostream>

vector<Point2f> corners(4);
vector<Point2f> corners_trans(4);

void Correct::split1(string temp){
	int i =0;
	stringstream temp1(temp);
	string p[6];
	while(temp1>>p[i++]);
	tx=atof(p[0].c_str());
	ty=atof(p[1].c_str());
	tz=atof(p[2].c_str());
	rx=atof(p[3].c_str());
	ry=atof(p[4].c_str());
	rz=atof(p[5].c_str());
}

/*void Correct::readdata(string path){
	int i=0;
	ifstream incin;
	incin.open(path);
	for(i=0;i<picnum;i++){
		getline(incin,temp[i]);
		cout<<temp[i]<<endl;
	}
}*/

void Correct::readdata1(string path){
	ifstream incin;
	incin.open(path);
	string temp;
	while (getline(incin,temp))
	{
		parmlist.push_back(temp);
	}
}

Point2f Correct::sMinMat(Point2f o1){
	o=Point2f(o1.x-320*a,o1.y-240*a);
	height=480*a;
	width=640*a;
	//cout<<o<<endl;
	return o;
}
void Correct::parm(){
	double ax=(rx)*M_PI/180;
	double ay=ry*M_PI/180;
	double az=rz*M_PI/180;
	float Rx[]={1,0,0,0,0,cos(ax),sin(ax),0,0,-sin(ax),cos(ax),0,0,0,0,1};
	float Ry[]={cos(ay),0,-sin(ay),0,0,1,0,0,sin(ay),0,cos(ay),0,0,0,0,1};
	float Rz[]={cos(az),sin(az),0,0,-sin(az),cos(az),0,0,0,0,1,0,0,0,0,1};
	Mat RX1=Mat(4,4,CV_32FC1,Rx);
	Mat RY1=Mat(4,4,CV_32FC1,Ry);
	Mat RZ1=Mat(4,4,CV_32FC1,Rz);
	Mat R1=Mat(4,4,CV_32FC1);
	gemm(RZ1,RX1,1,NULL,0,R1);
	gemm(R1,RY1,1,NULL,0,R1);

	ax=180*M_PI/180;
	ay=0;
	az=0;
	float ze1=ze;
	float T[]={1,0,0,0,0,1,0,0,0,0,1,0,-tx,-ty,-tz,1};
	float Rx2[] ={1,0,0,0,0,cos(ax),sin(ax),0,0,-sin(ax),cos(ax),0,0,0,0,1};
	float Ry2[]={cos(ay),0,-sin(ay),0,0,1,0,0,sin(ay),0,cos(ay),0,0,0,0,1};
	float Rz2[]={cos(az),sin(az),0,0,-sin(az),cos(az),0,0,0,0,1,0,0,0,0,1};
	float S[]={1,0,0,0,0,1,0,0,0,0,1,1.0/ze1,0,0,0,0};
	Mat T2=Mat(4,4,CV_32FC1,T);
	Mat  RX2=Mat(4,4,CV_32FC1,Rx2);
	Mat  RY2=Mat(4,4,CV_32FC1,Ry2);
	Mat  RZ2=Mat(4,4,CV_32FC1,Rz2);
	Mat S2=Mat(4,4,CV_32FC1,S);
	Mat R2=Mat(4,4,CV_32FC1);
	gemm(RZ2,RX2,1,NULL,0,R2);
	gemm(R2,RY2,1,NULL,0,R2);
	gemm(T2,R2,1,NULL,0,H2);
	gemm(H2,S2,1,NULL,0,H2);

	invert(	R1,R1);
	gemm(R1,R2,1,NULL,0,H);
	gemm(H,S2,1,NULL,0,H);
	cout<<H<<endl;
}
Point2f Correct::cornerTran(Mat point1){
	Point2f point;
	point.x=(point1.at<float>(0,0))/(point1.at<float>(0,3)*d);
	point.y=(point1.at<float>(0,1))/(point1.at<float>(0,3)*d);
	return point;
}
void Correct::point(){
	float O[]={0,0,0,1};
	float point0[]={-320*d,-240*d,ze,1};
	float point1[]={320*d,-240*d,ze,1};
	float point2[]={-320*d,240*d,ze,1};
	float point3[]={320*d,240*d,ze,1};
	Mat O2=Mat(1,4,CV_32FC1,O);
	Mat Point0=Mat(1,4,CV_32FC1,point0);
	Mat Point1=Mat(1,4,CV_32FC1,point1);
	Mat Point2=Mat(1,4,CV_32FC1,point2);
	Mat Point3=Mat(1,4,CV_32FC1,point3);
	gemm(Point0,H,1,NULL,0,Point0);
	gemm(Point1,H,1,NULL,0,Point1);
	gemm(Point2,H,1,NULL,0,Point2);
	gemm(Point3,H,1,NULL,0,Point3);
	gemm(O2,H2,1,NULL,0,O2);
	Point2f o=cornerTran(O2);
	Point2f o0=cornerTran(Point0);
	Point2f o1=cornerTran(Point1);
	Point2f o2=cornerTran(Point2);
	Point2f o3=cornerTran(Point3);
	o=sMinMat(o);
	corners_trans[0]=o0-o;
	corners_trans[1]=o1-o;
	corners_trans[2]=o2-o;
	corners_trans[3]=o3-o;
}

string Correct::correct(string imagename,string paramnum,int i){
	qDebug()<<"adfdsgsg";
	//readdata(parmpath);
	int index;
	corners[0]=Point2f(0,0);
	corners[1]=Point2f(640,0);
	corners[2]=Point2f(0,480);
	corners[3]=Point2f(640,480);
	string filename=imagename;
	src=imread(filename);
	split1(paramnum);
	parm();
	point();
	warp_mat=getPerspectiveTransform(corners,corners_trans);
	warpPerspective(src,dst,warp_mat,Size(width,height),INTER_LINEAR,BORDER_CONSTANT,Scalar(0,0,0));
	index=filename.find_last_of("/");
	filename=filename.substr(0,index+1)+"new_"+filename.substr(index+1,-1);
	imwrite(filename,dst);
	return filename;
}



