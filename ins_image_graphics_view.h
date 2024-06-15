#pragma once

#include <QGraphicsView>

class QGraphicsScene;
class QGraphicsPixmapItem;
class QPixmap;

class InsImageGraphicsView : public QGraphicsView
{
    Q_OBJECT

public:
    explicit InsImageGraphicsView(QWidget *parent = nullptr);
    ~InsImageGraphicsView();

protected:
    void wheelEvent(QWheelEvent *event) override;

private:

};