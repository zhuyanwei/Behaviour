#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>
#include <QTimer>
#include <QImage>
#include <unistd.h>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include "CameraGet.h"

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

    QTimer *timer;
    QImage qimg;
    Mat frame;
    VideoCapture cap;
    CameraGet cg;

    void funSobel();
    void funVideo();
    QImage mat2QImage(Mat cvImg);

signals:
    getFrame();

private slots:
    void on_B_OK();
    void timePart();
    void updateWindow();

};

#endif // WIDGET_H
