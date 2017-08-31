#include "FrameDif.h"

FrameDif::FrameDif()
{

}

void FrameDif::classGet(Mat inMat, Mat inMatBefo)
{
    frame = inMat;
    frameBefore = inMatBefo;
}

Mat FrameDif::calcuDif(Mat inMat,Mat inMatBefo)
{
    Mat temp;
    addWeighted(inMat,1,inMatBefo,-1,0,temp);
    return temp;
}

Mat FrameDif::frameDifAll()
{
    Mat temp;
    //calulate diff
    temp = calcuDif(frame,frameBefore);
    diffMat = temp.clone();
    //histogram analyze
    ch.classGet(temp);
    ch.histAll();
    diffHist = ch.outMat;
    //threshold binary
    threshold(temp,temp,THRES_FRAMEDIF,255,THRESH_BINARY);
    return temp;
}

