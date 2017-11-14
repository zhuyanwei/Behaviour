#ifndef FOREGROUNDEXTRACTION_H
#define FOREGROUNDEXTRACTION_H

#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <io.h>
#include <dirent.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/video/tracking.hpp>
#include <opencv2/video/background_segm.hpp>
#include <windef.h>
#include "bgfg_vibe.hpp"
#include "PBAS.h"
#include <stdio.h>
#include <opencv2/core/core.hpp>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

#define BUFFER_SIZE 30
#define OMITTED_FRAMES 0

class ForegroundExtraction
{
public:
    ForegroundExtraction();
    int mainly();
private:
    int countDir(const char* path);
    void drawOptFlowMap(const Mat& flow, Mat& cflowmap, int step,double, const Scalar& color);
    void calculateAverage(vector<Mat> in[3], vector<Mat> average);
    void calculateVariance(vector<Mat> in[3], vector<Mat> average, Mat tensor);
    static void onMouse( int event, int x, int y, int /*flags*/, void* /*param*/ );
    void calculateAddress(Vec3b ptr, ushort map[192][3], ushort address[36]);

    //some algorithms
    //Flux Tensor with Split Gaussian Models
    int FTSG(string path);
    int CwisarDH(string path);
    //Gaussian Mixture Model,MOG(Mixtore of Gaussian)
    int GMM(string path);
    //random background
    int ViBE(string path);
    int PBASfun(string path);

    Mat window;

    string absPath = "../Behaviour/SrcPics/input.avi";
};

#endif // FOREGROUNDEXTRACTION_H
