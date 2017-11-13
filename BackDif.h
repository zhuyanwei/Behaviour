//get the foreground,use backgound diff
#ifndef BACKDIF_H
#define BACKDIF_H

#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "COMDEF.h"

using namespace cv;

class BackDif
{
public:
    BackDif();
    void backgroundAvrg(Mat inMat);
    void backgroundGass();
    Mat getBack(Mat inMat);
    Mat calcuDiff(Mat inMat);

    Mat backTemp;
    Mat backAccumulate;
    Mat backOut;
};

#endif // BACKDIF_H
