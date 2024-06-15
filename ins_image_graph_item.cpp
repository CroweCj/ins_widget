#include "ins_image_graph_item.h"
#include <QGraphicsSceneWheelEvent>
#include <QGraphicsSceneHoverEvent>
#include <QPainter>
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsView>

#define ZOOM_IN_STEP 1.1
#define ZOOM_OUT_STEP 0.9

InsImageGraphicsItem::InsImageGraphicsItem()
{
	this->setAcceptHoverEvents(true);
	mScaleValue = 1.0;
	mScaleDefaultValue = 1.0;
	mImageCentorPosX = 0;
	mImageCentorPosY = 0;
	this->setPos(mImageCentorPosX, mImageCentorPosY);
	this->setScale(mScaleValue);
}

InsImageGraphicsItem::~InsImageGraphicsItem()
{

}

QRectF InsImageGraphicsItem::boundingRect() const
{
	return QRectF(-(mImage.width() / 2),
				  -(mImage.height() / 2),
		          mImage.width(),
		          mImage.height());
}

void InsImageGraphicsItem::update_image(const QImage& _image)
{
	mImage = _image;
}

void InsImageGraphicsItem::wheelEvent(QGraphicsSceneWheelEvent* event)
{
	int delta = event->delta();
	if (delta > 0
		&& mScaleValue > 75)
		return;
	if (delta < 0
		&& mScaleValue < 0.5)
		return;
	qreal curScaleValue = mScaleValue;

	if (delta > 0) {
		mScaleValue = curScaleValue * ZOOM_IN_STEP;
		//更新中心位置
		mImageCentorPosX += event->pos().x() * curScaleValue * 0.1;
		mImageCentorPosY += event->pos().y() * curScaleValue * 0.1;
	}else {
		mScaleValue = curScaleValue * ZOOM_OUT_STEP;
		//更新中心位置
		mImageCentorPosX -= event->pos().x() * curScaleValue * 0.1;
		mImageCentorPosY -= event->pos().y() * curScaleValue * 0.1;
	}

	this->setScale(mScaleValue);
	this->setPos(mImageCentorPosX, mImageCentorPosY);


	QGraphicsItem::wheelEvent(event);
}

void InsImageGraphicsItem::hoverMoveEvent(QGraphicsSceneHoverEvent* event)
{
	QPointF pos = event->pos();
	QPointF realPos(pos.x() + (mImage.width() / 2),
				  pos.y() + (mImage.height() / 2));
	emit sig_hover_pos_update(realPos.x(), realPos.y(), mImage.pixel(realPos.x(), realPos.y()));
	QGraphicsItem::hoverMoveEvent(event);
}

void InsImageGraphicsItem::mousePressEvent(QGraphicsSceneMouseEvent* event)
{

	QGraphicsItem::mousePressEvent(event);
}


void InsImageGraphicsItem::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
	QGraphicsItem::mouseMoveEvent(event);
}

void InsImageGraphicsItem::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
	QGraphicsItem::mouseReleaseEvent(event);
}

void InsImageGraphicsItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	 if (mImage.isNull()){
		return;
	 }

	const QPointF drawPosition(-(mImage.width() / 2),
				  -(mImage.height() / 2));


	if (!painter->isActive()) {
		return;
	}

	painter->drawImage(drawPosition, mImage);
}

void InsImageGraphicsItem::setItemPos(const QPointF&  _pos)
{
	QPointF scennePos = this->mapToScene(_pos);
	this->setPos(scennePos);
}
