#include "ins_image_graphics_view.h"

#include <QPainter>
#include <QWheelEvent>
#include <QGraphicsItem>
#include <QScrollBar>

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

void InsImageGraphicsView::centerOnItem(QGraphicsItem* item)
{
    if (!item) return;

    // 获取目标item的场景位置和边界矩形
    QRectF boundingRect = item->boundingRect();
    QPointF itemScenePos = item->scenePos();

    // 获取视图的大小
    QSize viewSize = viewport()->size();
    QPointF viewCenter = mapToScene(viewSize.width() / 2, viewSize.height() / 2);

    // 计算使item在视图中心的偏移量
    QPointF scrollOffset = viewCenter - itemScenePos - boundingRect.center();

    // 将滚动条滚动到合适的位置
    horizontalScrollBar()->setValue(horizontalScrollBar()->value() + scrollOffset.x());
    verticalScrollBar()->setValue(verticalScrollBar()->value() + scrollOffset.y());
}

void InsImageGraphicsView::wheelEvent(QWheelEvent *event)
{
    //this->centerOn(event->pos());
    this->centerOn(this->items().first());
    QGraphicsView::wheelEvent(event);
}
