#ifndef VIDEOWIDGET_H
#define VIDEOWIDGET_H

#include <QObject>
#include <QListWidget>
#include <QMenu>
#include <QAction>
#include <QContextMenuEvent>
#include <QMouseEvent>

class VideoWidget:public  QListWidget
{
    Q_OBJECT
public:
    VideoWidget(QWidget *parent);
    ~VideoWidget();
protected:
    void mousePressEvent(QMouseEvent *event);
private:
    QMenu *m_menu;
    QAction *m_addAction;
    QAction *m_delAction;
};

#endif // VIDEOWIDGET_H
