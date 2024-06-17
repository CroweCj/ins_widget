#include "ins_image_widget.h"
#include "ins_image_graph_item.h"
#include "ins_image_graphics_view.h"
#include "collapsible_widget.h"

#include <QVBoxLayout>
#include <QGraphicsProxyWidget>

ImageViewWidget::ImageViewWidget(QWidget* _parent) 
	: QWidget(_parent)
	, mpGraphicsView(nullptr)
	, mpGraphicsScene(nullptr)
	, mpHistWidget(nullptr)
{
	QVBoxLayout *layout = new QVBoxLayout;
	mpHistWidget = new CollapsibleWidget();
	mpGraphicsScene = new QGraphicsScene(this);

	mpGraphicsView = new InsImageGraphicsView(this);
	mpImageItem = new InsImageGraphicsItem();
	mpGraphicsScene->addItem((QGraphicsItem*)mpImageItem);

	QGraphicsProxyWidget* proxyWidget = mpGraphicsScene->addWidget(mpHistWidget);
	proxyWidget->setPos(0, 0);
	proxyWidget->setZValue(1);  // 确保控件在最上层
	proxyWidget->setFlag(QGraphicsItem::ItemIgnoresTransformations);

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