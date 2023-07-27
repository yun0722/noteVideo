#include "videoslider.h"

videoSlider::videoSlider()
{

}

videoSlider::videoSlider(QWidget *parent)
{

}

void videoSlider::mousePressEvent(QMouseEvent *ev)
{
    QSlider::mousePressEvent(ev);
    double pos=ev->pos().x()/double(width());
    setValue(pos*(maximum()-minimum()+minimum()));
    emit sigalSliderChanged();
}
