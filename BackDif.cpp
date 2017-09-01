#include "BackDif.h"

BackDif::BackDif()
{

}

void BackDif::backgroundAvrg(Mat inMat)
{
    //everytime use division
    backTemp = inMat / BACKGROUND_AVRG_N;
    addWeighted(backTemp,1,backAccumulate,1,0,backAccumulate);
}

void BackDif::backgroundGass()
{

}
