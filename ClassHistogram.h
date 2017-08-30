//about pixel statis,1 channel 0-255
#ifndef CLASSHISTOGRAM_H
#define CLASSHISTOGRAM_H

#include <QDebug>

#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;

class ClassHistogram
{
public:
    ClassHistogram();
    void classGet(Mat inMat);
    void histAll();
    MatND getHist(const Mat &inMat);
    Mat getHistImage(MatND inHist);

    Mat outMat;

private:
    //histogram parameters
    int histSize[1];
    float hranges[2];
    const float *ranges[1];
    int channels[1];

    Mat thisMat;
};

#endif // CLASSHISTOGRAM_H
