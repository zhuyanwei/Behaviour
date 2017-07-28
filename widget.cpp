#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //begin my code
    qDebug("fff");
    funSobel();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::funSobel()
{
    Mat src = imread("../Behaviour/SrcPics/misaka.jpg");
    Mat dst;

    Sobel(src,dst,src.depth(),2,2);
    imwrite("../Behaviour/FilPics/misaka_sobel2.jpg",dst);
}

