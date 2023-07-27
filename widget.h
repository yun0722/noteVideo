#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QFileInfo>
#include <QFileDialog>
#include <QTimer>
#include "videoslider.h"
#include<QMouseEvent>
#include "videowidget.h"
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void initVideoWidget();

    void initVideoPlayer();

    qint64 getDuration();

    void keyPressEvent(QKeyEvent *event);

    void mousePressEvent(QMouseEvent *event);

    void mouseMoveEvent(QMouseEvent *event);

    void mouseReleaseEvent(QMouseEvent *event);

private slots:
    void on_addButton_clicked();

    void on_playButton_clicked();

    void on_pauseButton_clicked();

    void slotPostionChanged(qint64 postion);

    void slotSliderChanged();

    void slotPlayerChanged(int postion);

    void slotSliderClicked();

    void on_allScreamButton_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Widget *ui;
    QMediaPlayer *videoPlayer;
    QVideoWidget *videoWidget;
    QString filePath;
    QTimer *timer;
    int hour;
    int minute;
    int second;
    bool state=false;
    int width;
    int height;
    QPoint startPoint;
    QPoint windowPoint;
    VideoWidget *videowidget;
};
#endif // WIDGET_H
