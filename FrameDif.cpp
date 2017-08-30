#include "FrameDif.h"

FrameDif::FrameDif()
{

}

Mat FrameDif::matDif(Mat inMat,Mat inMatBefo)
{
    Mat temp;
    addWeighted(inMat,1,inMatBefo,-1,0,temp);
    return temp;
}

void FrameDif::getValue(Mat &inMat)
{
    int histSize[1];
    float hranges[2];
    const float *ranges[1];
    int channels[1];

    histSize[0] = 256;
    hranges[0] = 0.0;
    hranges[1] = 255.0;
    ranges[0] = hranges;
    channels[0] = 0;

    MatND hist;
    calcHist(&inMat,1,channels,Mat(),hist,1,histSize,ranges,true,false);
    //show number
    for(int i = 0;i < 256;i++)
    {
//        qDebug()<<"value"<<i<<"="<<hist.at<float>(i);
    }
    //show chart
//    double maxVal = 0;
//    double minVal = 0;
//    minMaxLoc(hist,&minVal,&maxVal,0,0);
//    Mat histImg(histSize[0],histSize[0],CV_8U,Scalar(255));
//    int hpt = static_cast<int>(0.9 * histSize[0]);
//    for(int h = 0;h < histSize[0];h++)
//    {
//        float binVal = hist.at<float>(h);
//        int intensity = static_cast<int>(binVal * hpt / maxVal);
//        line(histImg,Point(h,histSize[0]),Point(h,histSize[0] - intensity),Scalar::all(0));
//    }
//    histOut = histImg;
}

