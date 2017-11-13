#include "BackDif.h"

BackDif::BackDif()
{
    backAccumulate = Mat(HEIGHT,WIDTH,CV_32FC1,Scalar(0.0));
}

void BackDif::backgroundAvrg(Mat inMat)
{
    //**********method1,BACKGROUND_AVRG_N
    //everytime use division
    addWeighted(inMat,1 / BACKGROUND_AVRG_N,backAccumulate,1 ,0,backAccumulate);
    //*************method2
    //accumulateWeighted background update
//    accumulateWeighted(inMat,backAccumulate,0.003);
}

Mat BackDif::getBack(Mat inMat)
{
    backOut = inMat.clone();
    return backOut;
}

Mat BackDif::calcuDiff(Mat inMat)
{
    Mat temp;
    addWeighted(inMat,1,backOut,-1,0,temp);
    return temp;
}

void BackDif::backgroundGass()
{

}
