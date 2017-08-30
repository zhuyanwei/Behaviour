#include "PreProcess.h"

PreProcess::PreProcess()
{

}

int PreProcess::preGet(Mat inMat)
{
    frame = inMat;
    return 1;
}

Mat PreProcess::comvertSpace(Mat inMat)
{
    Mat frameGray;
    cvtColor(inMat, frameGray, CV_BGR2GRAY);
    return frameGray;
}

Mat PreProcess::gassianFil(Mat inMat)
{
    Mat frameGassian;
    GaussianBlur(inMat,frameGassian,Size(GASSIANBLUR1,GASSIANBLUR1),0,0);
    return frameGassian;
}

Mat PreProcess::preAll()
{
    Mat temp;
    temp = comvertSpace(frame);
//    temp = gassianFil(temp);
    return temp;
}
