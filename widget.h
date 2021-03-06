#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>
#include <QTimer>
#include <QImage>
#include <iostream>
#include <unistd.h>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include "CameraGet.h"
#include "PreProcess.h"
#include "FrameDif.h"
#include "ClassHistogram.h"
#include "BackDif.h"
#include "ForegroundExtraction.h"
#include "PBAS.h"

using namespace cv;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;

    PreProcess preProcess;
    FrameDif frameDif;
    ClassHistogram classHis1;

    QTimer *timer;
    QImage qimg;
    Mat frame;
    Mat frameGray,frameX,frameY,frameNor;
    VideoCapture cap;
    CameraGet cg;
    bool isFinish;

    void funSobel();
    void funVideo();
    QImage mat2QImage(Mat cvImg);
    void showPic(Mat inFrame, int part);

    //foreground extraction
    ForegroundExtraction fe;
    //frame diff
    Mat frameBefo;
    void scptFrameDif();
    //background diff
    BackDif backDif;
    int backgroundN;
    void scptBackDif();

signals:
    getFrame();

private slots:
    void on_B_OK();
    void on_B_Pause();
    void timePart();
    void updateWindow();

};

#endif // WIDGET_H
