#ifndef VIDEOLISTWIDGET_H
#define VIDEOLISTWIDGET_H

#include <QWidget>

namespace Ui {
class VideoListWidget;
}

class VideoListWidget : public QWidget
{
    Q_OBJECT

public:
    explicit VideoListWidget(QWidget *parent = nullptr);
    ~VideoListWidget();

private:
    Ui::VideoListWidget *ui;
};

#endif // VIDEOLISTWIDGET_H
