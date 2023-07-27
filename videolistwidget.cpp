#include "videolistwidget.h"
#include "ui_videolistwidget.h"

VideoListWidget::VideoListWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VideoListWidget)
{
    ui->setupUi(this);
}

VideoListWidget::~VideoListWidget()
{
    delete ui;
}
