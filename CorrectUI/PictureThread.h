#include "QThread"
class PictureThread :public QThread
{
public:
	PictureThread();
	~PictureThread();

protected:
	void run();
};