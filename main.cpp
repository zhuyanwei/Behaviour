#include "widget.h"
#include <QApplication>

//#include <opencv2/opencv.hpp>
//#include <opencv2/highgui/highgui.hpp>
//using namespace cv;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    return a.exec();
//    //**********************************some other
//    VideoCapture capture("../Behaviour/SrcPics/goout.flv");
//    if(!capture.isOpened())
//        return 3;
//    double rate = capture.get(CV_CAP_PROP_FPS);
//    bool stop(false);
//    Mat frame;
////    namedWindow("Ext");
//    int delay = 1000/rate;
//    while(!stop)
//    {
//        if(!capture.read(frame))
//            break;
//        imshow("Ext",frame);
//        if(waitKey(delay) >= 0)
//            stop = true;
//    }
//    capture.release();
}
