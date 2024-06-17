#pragma once

#include <QGraphicsItem>
#include <QObject>

class InsImageGraphicsItem : public QObject, QGraphicsItem
{
	Q_OBJECT
public:
	InsImageGraphicsItem();
	virtual ~InsImageGraphicsItem();
	QRectF boundingRect() const;
	void update_image(const QImage& _image);
protected:
	virtual void wheelEvent(QGraphicsSceneWheelEvent* _event);
	virtual void hoverMoveEvent(QGraphicsSceneHoverEvent* event);
	virtual void mousePressEvent(QGraphicsSceneMouseEvent* event);
	virtual void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
	virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr) override;
private:
	void setItemPos(const QPointF&  _pos);
	void resetItemPos();
signals:
	void sig_hover_pos_update(qreal _x, qreal _y, QRgb _color);
private:
	qreal mScaleValue;
	qreal mImageCentorPosX;
	qreal mImageCentorPosY;
	qreal mScaleDefaultValue;
	QImage mImage;

	bool mMove;
	QPointF mMoveStartPos;
	QPointF mMoveEndPos;

};

