#include "CameraGet.h"

CameraGet::CameraGet()
{

}

CameraGet::~CameraGet()
{

}

int CameraGet::openCamera()
{
    if (capture.isOpened())
        capture.release();
    capture.open(0);
    double w = capture.get(CV_CAP_PROP_FRAME_WIDTH);
    double h = capture.get(CV_CAP_PROP_FRAME_HEIGHT);
    double f = capture.get(CV_CAP_PROP_FPS );
    qDebug()<<"camera info:";
    qDebug()<<"before---width"<<w<<"height"<<h<<"fps"<<f;

    capture.set(CV_CAP_PROP_FRAME_WIDTH,WIDTH);
    capture.set(CV_CAP_PROP_FRAME_HEIGHT,HEIGHT);
    w = capture.get(CV_CAP_PROP_FRAME_WIDTH);
    h = capture.get(CV_CAP_PROP_FRAME_HEIGHT);
    qDebug()<<"reset---width"<<w<<"height"<<h<<"fps"<<f;

    qDebug()<<"+++ Camera Opened";
    return 0;
}

int CameraGet::closeCamera()
{
    if (capture.isOpened())
        capture.release();

    qDebug()<<"Camera Closed";
    return 0;
}
int CameraGet::readFrame()
{
    if (capture.isOpened())
    {
        capture.read(frame);
    }
}
