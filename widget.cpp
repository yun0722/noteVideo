#if _MSC_VER >= 1600 // >=MSVC2010

#pragma execution_character_set("utf-8")

#endif
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    videoWidget=new QVideoWidget();
    videoPlayer=new QMediaPlayer();
    ui->videoLayout->addWidget(videoWidget);
    videoPlayer->setVideoOutput(videoWidget);
    videoWidget->setAutoFillBackground(true);
    qDebug()<<"中文";
    timer=new QTimer();
    timer->setInterval(1000);
    //this->setFocusPolicy(Qt::ClickFocus);
    width=ui->verticalLayoutWidget_2->width();
    height=ui->verticalLayoutWidget_2->height();
    this->setWindowFlags(Qt::FramelessWindowHint);
    connect(videoPlayer,SIGNAL(positionChanged(qint64)),this,SLOT(slotPostionChanged(qint64)));
    connect(timer,SIGNAL(timeout()),this,SLOT(slotSliderChanged()));
    connect(ui->horizontalSlider,SIGNAL(sliderMoved(int)),this,SLOT(slotPlayerChanged(int)));
    connect(ui->horizontalSlider,SIGNAL(sigalSliderChanged()),this,SLOT(slotSliderClicked()));
    ui->playButton->setMaximumSize(50,50);
    ui->playButton->setMinimumSize(50,50);
    videowidget=new VideoWidget(this);
    videowidget->show();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::initVideoWidget()
{

}

void Widget::initVideoPlayer()
{

}

qint64 Widget::getDuration()
{
    return videoPlayer->duration();
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    event->accept();
    if(event->key()==Qt::Key_Escape){
        videoWidget->setWindowFlags(Qt::SubWindow);
        videoWidget->showNormal();
        qDebug()<<"click";
    }
    //    parent()->event(event);
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    if(event->buttons()==Qt::LeftButton){
        startPoint=event->globalPos();
        windowPoint=this->frameGeometry().topLeft();
    }
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons()==Qt::LeftButton){
        QPoint pos=event->globalPos()-startPoint;
        this->move(windowPoint+pos);
    }
}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{


}


void Widget::on_addButton_clicked()
{
    QFileDialog *fileDialog=new QFileDialog(this);
    fileDialog->setWindowTitle(QStringLiteral("导入文件"));
    fileDialog->setDirectory("./");
    fileDialog->setNameFilter("File(*.mp4 *.wav *.mov *.avi)");
    fileDialog->setFileMode(QFileDialog::ExistingFiles);
    //
    fileDialog->setViewMode(QFileDialog::Detail);
    //��
    QStringList fileNames;
    if (fileDialog->exec()) {
        fileNames = fileDialog->selectedFiles();
        filePath=fileNames[0];
    }
    videoPlayer->setMedia(QUrl::fromLocalFile(filePath));
}


void Widget::on_playButton_clicked()
{
    if(videoPlayer->state()!=QMediaPlayer::PlayingState){
        videoPlayer->play();
        int time=getDuration();
        qDebug()<<time;
        hour=time/3600000;
        qDebug()<<"hour="<<hour;
        minute=time%3600000/60000;
        second=time%60000/1000;
        QString allTime=QString::number(hour)+":"+QString::number(minute)+":"+QString::number(second);
        //    ui->allTimeLabel->setText(allTime);
        ui->allTimeLabel->setText(allTime);
        ui->horizontalSlider->setMaximum(time);
        timer->start();
        ui->playButton->setStyleSheet("border-image: url(:/icon/resource/播放.png);");
    }else{
        videoPlayer->pause();
        ui->playButton->setStyleSheet("border-image: url(:/icon/resource/暂停.png);");
    }

}


void Widget::on_pauseButton_clicked()
{
    videoPlayer->pause();
}

void Widget::slotPostionChanged(qint64 postion)
{
    int time=postion;
    qDebug()<<time;
    hour=time/3600000;
    qDebug()<<"hour="<<hour;
    minute=time%3600000/60000;
    second=time%60000/1000;
    QString allTime=QString::number(hour)+":"+QString::number(minute)+":"+QString::number(second);
    qDebug()<<"中文";
    //    ui->allTimeLabel->setText(allTime);
    ui->timeLabel->setText(allTime);
}

void Widget::slotSliderChanged()
{
    ui->horizontalSlider->setValue(videoPlayer->position());
}

void Widget::slotPlayerChanged(int postion)
{
    videoPlayer->setPosition(postion);
}

void Widget::slotSliderClicked()
{
    int value=ui->horizontalSlider->value();
    videoPlayer->setPosition(value);
}


void Widget::on_allScreamButton_clicked()
{
    if(state==false){
        ui->verticalLayoutWidget_2->setWindowFlags(Qt::Window);
        ui->verticalLayoutWidget_2->showFullScreen();
        state=true;
    }
    else{
//        ui->verticalLayoutWidget_2->resize(width,height);
        ui->verticalLayoutWidget_2->setWindowFlags(Qt::SubWindow);
        ui->verticalLayoutWidget_2->showNormal();
        ui->verticalLayoutWidget_2->resize(width,height);
        state=false;
    }
}


void Widget::on_pushButton_clicked()
{
    this->close();
}


void Widget::on_pushButton_2_clicked()
{
    if(state==false){
        ui->verticalLayoutWidget_2->setWindowFlags(Qt::Window);
        ui->verticalLayoutWidget_2->showFullScreen();
        state=true;
    }
}


void Widget::on_pushButton_3_clicked()
{
    this->setWindowState(Qt::WindowMinimized);
}

