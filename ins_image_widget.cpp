#include "ins_image_widget.h"
#include "ins_image_graph_item.h"
#include "ins_image_graphics_view.h"

#include <QVBoxLayout>

ImageViewWidget::ImageViewWidget(QWidget* _parent) 
	: QWidget(_parent)
	, mpGraphicsView(nullptr)
	, mpGraphicsScene(nullptr)
{
	QVBoxLayout *layout = new QVBoxLayout;

	mpGraphicsScene = new QGraphicsScene(this);

	mpGraphicsView = new InsImageGraphicsView(this);
	mpImageItem = new InsImageGraphicsItem();
	mpGraphicsScene->addItem((QGraphicsItem*)mpImageItem);

	mpGraphicsView->setScene(mpGraphicsScene);
	mpGraphicsView->setSceneRect(mpImageItem->boundingRect());
	mpGraphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    mpGraphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	layout->addWidget(mpGraphicsView);
	this->setLayout(layout);

	mpGraphicsView->centerOn((QGraphicsItem*)mpImageItem);
	mpGraphicsView->show();

	QObject::connect(mpImageItem, &InsImageGraphicsItem::sig_hover_pos_update, this, &ImageViewWidget::sig_hover_pos_update);
}

ImageViewWidget::~ImageViewWidget()
{
}

void ImageViewWidget::setImage(const QImage& _image)
{
	mpImageItem->update_image(_image);
	
}

void ImageViewWidget::paintEvent(QPaintEvent* _event)
{
	//TODO:

	QWidget::paintEvent(_event);
	return;
}

void ImageViewWidget::resizeEvent(QResizeEvent* _event)
{
	//TODO:

	QWidget::resizeEvent(_event);
	return;
}