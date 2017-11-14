#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //initial paras
    isFinish = true;
        //background diff
    backgroundN = BACKGROUND_AVRG_N;

    //timer
    timer = new QTimer(this);
    timer->setInterval(100);
    connect(timer, SIGNAL(timeout()), this, SLOT(timePart()));
    //buttons
    connect(ui->B_OK,SIGNAL(clicked()),this,SLOT(on_B_OK()));
    connect(ui->B_Pause,SIGNAL(clicked()),this,SLOT(on_B_Pause()));
    //self slots
    connect(this,SIGNAL(getFrame()),this,SLOT(updateWindow()));

    qDebug("widget instruct done");
    //temp test
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
void Widget::on_B_Pause()
{
    funVideo();
//    isFinish = false;
}

void Widget::timePart()
{
    //get this frame(not pre processed)
    cg.readFrame();
    if (cg.frame.empty()) return;
    //origin from camera,pre process
    preProcess.preGet(cg.frame);
    frame = preProcess.preAll();
    showPic(frame,1);
    //calculate accumulation
    if(backgroundN)
    {
        backDif.backgroundAvrg(frame);
        backgroundN--;
    }
    showPic(backDif.backAccumulate,2);
    if(backgroundN == 0)
    {
        backDif.getBack(backDif.backAccumulate);
        showPic(backDif.backOut,3);
        showPic(backDif.calcuDiff(frame),4);
    }
    return;
    //process this frame
//    CV_8UC1
    Sobel(frameGray,frameX,CV_8U,1,0);
    Sobel(frameGray,frameY,CV_8U,0,1);
    frameNor = abs(frameX) + abs(frameY);
    qimg = mat2QImage(frameNor);
    ui->L_Proc0->setPixmap(QPixmap::fromImage(qimg));

    //restore the exact frame
    if(isFinish == false)
    {
        imwrite("../Behaviour/FilPics/add2.jpg",frameNor);
        isFinish = true;
        qDebug("restore done");
    }
}

void Widget::funSobel()
{
    Mat src = imread("../Behaviour/SrcPics/misaka.jpg");
    Mat dst,dstX,dstY,sol,dstbi;

//    Sobel(src,dstX,CV_8U,1,0,3,0.4,128);
//    imwrite("../Behaviour/FilPics/misaka_sobel8ux128.jpg",dstX);
//    Sobel(src,dstY,CV_8U,1,0);
//    imwrite("../Behaviour/FilPics/misaka_sobel8ux.jpg",dstY);
    Sobel(src,dstX,CV_8U,1,0);
    imwrite("../Behaviour/FilPics/misaka_sobel8ux.jpg",dstX);
    Sobel(src,dstY,CV_8U,0,1);
    imwrite("../Behaviour/FilPics/misaka_sobel8uy.jpg",dstY);
    sol = abs(dstX) + abs(dstY);
    imwrite("../Behaviour/FilPics/misaka_sobel8unor.jpg",sol);
//    double mi,ma;
//    minMaxLoc(sol,&mi,&ma);
//    sol.convertTo(dst,CV_8U,-255./ma,255);
////    threshold(sol,dstbi,threshold,255,THRESH_BINARY);
//    imwrite("../Behaviour/FilPics/misaka_sobel16sall.jpg",dst);
////    imwrite("../Behaviour/FilPics/misaka_sobel16sallbi.jpg",dstbi);


    qDebug()<<"depth---src"<<src.depth()<<"dst"<<dstX.depth();
    qDebug()<<"channel---src"<<src.channels()<<"dst"<<dstX.channels();
}

void Widget::funVideo()
{
    Mat m1;
    m1 = imread("../Behaviour/SrcPics/lena.jpg");
//    namedWindow("sss",CV_GUI_EXPANDED);
    waitKey(30);
//    findContours
    imshow("sss",m1);
    waitKey(30);

//    VideoCapture cap;
//    cap.open("../Behaviour/SrcPics/Curtain.avi");
//    if(!cap.isOpened())
//    {
//        qDebug("open video fail");
//        return;
//    }
//    double rate = cap.get(CV_CAP_PROP_FPS);
//    bool stop = false;
//    int i = 0;
//    while(!stop)
//    {
//        cap.read(frame);
//        if(!frame.empty())
//        {
////            qimg = mat2QImage(frame);
////            ui->L_Src->setPixmap(QPixmap::fromImage(qimg));
////            timer = new QTimer(this);
////            timer->setInterval(1000/rate);
////            connect(timer, SIGNAL(timeout()), this, SLOT(timePart()));
////            timer->start();
//            waitKey(10000);
////            cvWaitKey(100000000);
//            DB<<"12";
//        }
//        else
//            break;
//    }
//    cap.release();
//    DB<<"finish video,rate:"<<rate;
}

//**********************************GUI
void Widget::updateWindow()
{
    qimg = QImage((const uchar*)(frame.data),frame.cols, frame.rows, QImage::Format_RGB888).rgbSwapped();
    ui->L_Src->setPixmap(QPixmap::fromImage(qimg));
}

QImage Widget::mat2QImage(Mat cvImg)
{
    QImage qImg;
    Mat matTemp;
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
        if(cvImg.type() == CV_8UC1)
            qImg =QImage((const unsigned char*)(cvImg.data),
                        cvImg.cols,cvImg.rows,
                        cvImg.cols * cvImg.channels(),
                        QImage::Format_Indexed8);
        else if(cvImg.type() == CV_32FC1)
        {
            cvImg.convertTo(matTemp,CV_8UC1);
            qImg =QImage((const unsigned char*)(matTemp.data),
                        matTemp.cols,matTemp.rows,
                        matTemp.cols * matTemp.channels(),
                        QImage::Format_Indexed8);
        }
    }
    else
    {
        qImg =QImage((const unsigned char*)(cvImg.data),
                    cvImg.cols,cvImg.rows,
                    cvImg.cols * cvImg.channels(),
                    QImage::Format_RGB888);
    }
    qImg.bits();
    return qImg;
}

void Widget::showPic(Mat inFrame,int part)
{
    QImage showImage;
    showImage = mat2QImage(inFrame);
    switch (part)
    {
        case 1:
            ui->L_Src->setPixmap(QPixmap::fromImage(showImage));
            break;
        case 2:
            ui->L_Proc0->setPixmap(QPixmap::fromImage(showImage));
            break;
        case 3:
            ui->L_ProcX->setPixmap(QPixmap::fromImage(showImage));
            break;
        case 4:
            ui->L_ProcY->setPixmap(QPixmap::fromImage(showImage));
            break;
        default:
            break;
    }
}

//***********************************Scripts
void Widget::scptFrameDif()
{
    Mat frameTemp;
    //get this frame(not pre processed)
    cg.readFrame();
    if (cg.frame.empty()) return;
    //get the pre frame(pre processed)
    frameBefo = frame;
    //origin from camera,pre process
    preProcess.preGet(cg.frame);
    frame = preProcess.preAll();
    if (frameBefo.empty()) return;

    showPic(frame,1);

    frameDif.classGet(frame,frameBefo);
    frameTemp = frameDif.frameDifAll();
    showPic(frameDif.diffMat,2);
    showPic(frameDif.diffHist,3);
    showPic(frameTemp,4);
//    qDebug()<<"frame depth---before"<<frame.depth()<<"after"<<frameTemp.depth();
    //restore the exact frame
    if(isFinish == false)
    {
        imwrite("../Behaviour/FilPics/add2.jpg",frameNor);
        imwrite("../Behaviour/FilPics/add2_weight100.jpg",frameTemp);
        isFinish = true;
        qDebug("restore done");
    }
}

void Widget::scptBackDif()
{

}

