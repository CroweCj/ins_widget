#include "ins_image_graphics_view.h"

#include <QPainter>
#include <QWheelEvent>

InsImageGraphicsView::InsImageGraphicsView(QWidget *parent)
    : QGraphicsView(parent)
{
    // 设置背景颜色
    setBackgroundBrush(Qt::white);
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    setResizeAnchor(QGraphicsView::AnchorUnderMouse);
}

InsImageGraphicsView::~InsImageGraphicsView()
{
}

void InsImageGraphicsView::wheelEvent(QWheelEvent *event)
{
    //this->centerOn(event->pos());
    QGraphicsView::wheelEvent(event);
}
