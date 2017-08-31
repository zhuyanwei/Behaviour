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
    void backgroundAvrg();
    void backgroundGass();
};

#endif // BACKDIF_H
