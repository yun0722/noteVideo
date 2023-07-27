#ifndef VIDEOSLIDER_H
#define VIDEOSLIDER_H
#include <QSlider>
#include <QWidget>
#include <QMouseEvent>
class videoSlider:public QSlider
{
    Q_OBJECT
public:
    videoSlider();
    explicit videoSlider(QWidget *parent=nullptr);
    void mousePressEvent(QMouseEvent *ev);
signals:
    void sigalSliderChanged();
};

#endif // VIDEOSLIDER_H
