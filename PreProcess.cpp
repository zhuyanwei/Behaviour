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

Mat PreProcess::cvt32f(Mat inMat)
{
    Mat mat32f;
    inMat.convertTo(mat32f,CV_32FC1);
    return mat32f;
}

Mat PreProcess::preAll()
{
    Mat temp;
    temp = comvertSpace(frame);
    temp = cvt32f(temp);
//    temp = gassianFil(temp);
    return temp;
}
