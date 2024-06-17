#pragma once

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>


class InsImageGraphicsItem;
class InsImageGraphicsView;
class CollapsibleWidget;

class ImageViewWidget : public QWidget
{
	Q_OBJECT
public:
	ImageViewWidget(QWidget* _parent = nullptr);
	~ImageViewWidget();

	void setImage(const QImage& _image);

signals:
	void sig_hover_pos_update(qreal _x, qreal _y, QRgb _color);
public slots:

protected:
	void paintEvent(QPaintEvent* _event) override;
	void resizeEvent(QResizeEvent* _event) override;
private:
	InsImageGraphicsView* mpGraphicsView;
	QGraphicsScene* mpGraphicsScene;
	InsImageGraphicsItem* mpImageItem;
	CollapsibleWidget* mpHistWidget;
};
