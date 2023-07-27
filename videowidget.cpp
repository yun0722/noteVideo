#include "videowidget.h"

VideoWidget::VideoWidget(QWidget *parent)
{
    m_menu=new QMenu;
    m_addAction=new QAction("add item",this);
    m_delAction=new QAction("del item",this);
    m_menu->addAction(m_addAction);
    m_menu->addAction(m_delAction);
}

VideoWidget::~VideoWidget()
{

}

void VideoWidget::mousePressEvent(QMouseEvent *event)
{
    //确保右键点击，然后跳出菜单.
    if (event->button() == Qt::RightButton)
    {
        m_menu->exec(event->globalPos());
    }
    //要继续保留QListWidget原有的点击事件.
    QListWidget::mousePressEvent(event);
}
