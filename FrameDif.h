//get the foreground,use diffs between frames
#ifndef FRAMEDIF_H
#define FRAMEDIF_H

#include <QDebug>

#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;

class FrameDif
{
public:
    FrameDif();
    Mat matDif(Mat inMat, Mat inMatBefo);
    void getValue(Mat &inMat);

    Mat histOut;
};

#endif // FRAMEDIF_H
