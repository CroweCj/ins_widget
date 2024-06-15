#pragma once

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>


class InsImageGraphicsItem;
class InsImageGraphicsView;

class ImageViewWidget : public QWidget
{
	Q_OBJECT
public:
	ImageViewWidget(QWidget* _parent = nullptr);
	~ImageViewWidget();

	void setImage(const QImage& _image);

signals:

public slots:

protected:
	void paintEvent(QPaintEvent* _event) override;
	void resizeEvent(QResizeEvent* _event) override;
private:
	InsImageGraphicsView* mpGraphicsView;
	QGraphicsScene* mpGraphicsScene;
	InsImageGraphicsItem* mpImageItem;
};
