#include "correctui.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{	
	
	QApplication a(argc, argv);
	CorrectUI w;
	//w.showMaximized();
	w.show();
	return a.exec();
}
