//get the foreground,use diffs between frames
#ifndef FRAMEDIF_H
#define FRAMEDIF_H

#include <QDebug>

#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include "ClassHistogram.h"
#include "COMDEF.h"

using namespace cv;

class FrameDif
{
public:
    FrameDif();
    void classGet(Mat inMat, Mat inMatBefo);
    Mat frameDifAll();
    Mat calcuDif(Mat inMat, Mat inMatBefo);

    Mat diffMat;
    Mat diffHist;
private:
    Mat frame;
    Mat frameBefore;

    ClassHistogram ch;
};

#endif // FRAMEDIF_H
