#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    timer = new QTimer(this);
    timer->setInterval(100);
    connect(timer, SIGNAL(timeout()), this, SLOT(timePart()));

    connect(ui->B_OK,SIGNAL(clicked()),this,SLOT(on_B_OK()));

    connect(this,SIGNAL(getFrame()),this,SLOT(updateWindow()));

    qDebug("widget instruct done");

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_B_OK()
{
    cg.openCamera();
    timer->start();
}

void Widget::timePart()
{
    cg.readFrame();
    frame = cg.frame;
    if (!frame.empty())
    {
        qimg = mat2QImage(frame);
        ui->L_Src->setPixmap(QPixmap::fromImage(qimg));
    }
}

void Widget::funSobel()
{
    Mat src = imread("../Behaviour/SrcPics/misaka.jpg");
    Mat dst;

    Sobel(src,dst,src.depth(),1,2);
    imwrite("../Behaviour/FilPics/misaka_sobel4.jpg",dst);
}

void Widget::funVideo()
{
    VideoCapture cap("../Behaviour/SrcPics/goout.flv");
    if(!cap.isOpened())
    {
        qDebug("open video fail");
        return;
    }
    double rate = cap.get(CV_CAP_PROP_FPS);
    bool stop(false);
    int i = 0;
    cap.read(frame);
    if (!frame.empty())
    {
        qimg = mat2QImage(frame);
        ui->L_Src->setPixmap(QPixmap::fromImage(qimg));
        timer = new QTimer(this);
        timer->setInterval(1000/rate);
        connect(timer, SIGNAL(timeout()), this, SLOT(timePart()));
        timer->start();
    }
//    cap.release();
    qDebug("finish funVideo");
}

void Widget::updateWindow()
{
    qimg = QImage((const uchar*)(frame.data),frame.cols, frame.rows, QImage::Format_RGB888).rgbSwapped();
    ui->L_Src->setPixmap(QPixmap::fromImage(qimg));
}

QImage Widget::mat2QImage(Mat cvImg)
{
    QImage qImg;
    if(cvImg.channels()==3)
    {
        cvtColor(cvImg,cvImg,CV_BGR2RGB);
        qImg = QImage((const unsigned char*)(cvImg.data),
                    cvImg.cols,cvImg.rows,
                    cvImg.cols * cvImg.channels(),
                    QImage::Format_RGB888);
    }
    else if(cvImg.channels()==1)
    {
        qImg =QImage((const unsigned char*)(cvImg.data),
                    cvImg.cols,cvImg.rows,
                    cvImg.cols * cvImg.channels(),
                    QImage::Format_Indexed8);
    }
    else
    {
        qImg =QImage((const unsigned char*)(cvImg.data),
                    cvImg.cols,cvImg.rows,
                    cvImg.cols * cvImg.channels(),
                    QImage::Format_RGB888);
    }
    return qImg;
}


