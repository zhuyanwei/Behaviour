#include "ClassHistogram.h"

ClassHistogram::ClassHistogram()
{
    histSize[0] = 256;
    hranges[0] = 0.0;
    hranges[1] = 255.0;
    ranges[0] = hranges;
    channels[0] = 0;
}

void ClassHistogram::classGet(Mat inMat)
{
    thisMat = inMat;
}

MatND ClassHistogram::getHist(const Mat &inMat)
{
    MatND hist;
    calcHist(&inMat,1,channels,Mat(),hist,1,histSize,ranges,true,false);
    //show number
//    for(int i = 0;i < 256;i++)
//    {
//        qDebug()<<"value"<<i<<"="<<hist.at<float>(i);
//    }
    return hist;
}

Mat ClassHistogram::getHistImage(MatND inHist)
{
    double maxVal = 0;
    double minVal = 0;
    minMaxLoc(inHist,&minVal,&maxVal,0,0);
    Mat histImg(histSize[0],histSize[0],CV_8U,Scalar(255));
    int hpt = static_cast<int>(0.9 * histSize[0]);
    for(int h = 0;h < histSize[0];h++)
    {
        float binVal = inHist.at<float>(h);
        int intensity = static_cast<int>(binVal * hpt / maxVal);
        line(histImg,Point(h,histSize[0]),Point(h,histSize[0] - intensity),Scalar::all(0));
    }
    return histImg;
}

void ClassHistogram::histAll()
{
    MatND temp1;
    Mat temp2;
    temp1 = getHist(thisMat);
    temp2 = getHistImage(temp1);
    outMat = temp2;
}
