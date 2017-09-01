#include "BackDif.h"

BackDif::BackDif()
{

}

void BackDif::backgroundAvrg(Mat inMat)
{
    //**********method1
    //everytime use division
//    backTemp = inMat / BACKGROUND_AVRG_N;
//    addWeighted(backTemp,1,backAccumulate,1,0,backAccumulate);
//    addWeighted(inMat,1 / BACKGROUND_AVRG_N,backAccumulate,1,0,backAccumulate);
    //*************method2
    //accumulateWeighted background update
    accumulateWeighted(inMat,backAccumulate,0.003);
}

void BackDif::backgroundGass()
{

}
