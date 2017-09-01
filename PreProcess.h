//after the raw camera image
//include bgr2gray,gassian blur
#ifndef PREPROCESS_H
#define PREPROCESS_H

#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "COMDEF.h"

using namespace cv;

class PreProcess
{
public:
    PreProcess();
    int preGet(Mat inMat);
    Mat preAll();
private:
    Mat comvertSpace(Mat inMat);
    Mat gassianFil(Mat inMat);
    Mat cvt32f(Mat inMat);

    Mat frame;
};

#endif // PREPROCESS_H
