#ifndef CAMERAGET_H
#define CAMERAGET_H

#include <QObject>
#include <QDebug>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "COMDEF.h"

using namespace cv;

class CameraGet : public QObject
{
public:
    CameraGet();
    ~CameraGet();
    int openCamera();
    int readFrame();
    int closeCamera();

    VideoCapture capture;
    Mat frame;

signals:

public slots:
};

#endif // CAMERAGET_H
