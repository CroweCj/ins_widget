#include "ins_image_widget.h"
#include "ins_image_graph_item.h"
#include "ins_image_graphics_view.h"
#include "collapsible_widget.h"
#include "histogram_widget.h"

#include <QVBoxLayout>
#include <QGraphicsProxyWidget>
QGraphicsProxyWidget* proxyWidget;

ImageViewWidget::ImageViewWidget(QWidget* _parent) 
	: QWidget(_parent)
	, mpGraphicsView(nullptr)
	, mpGraphicsScene(nullptr)
	, mpHistWidget(nullptr)
{
	QVBoxLayout *layout = new QVBoxLayout;
	mpHistWidget = new HistogramCollapsibleWidget();
	mpGraphicsScene = new QGraphicsScene(this);

	mpGraphicsView = new InsImageGraphicsView(this);
	mpImageItem = new InsImageGraphicsItem();
	mpGraphicsScene->addItem((QGraphicsItem*)mpImageItem);

	proxyWidget = mpGraphicsScene->addWidget(mpHistWidget);
	
	proxyWidget->setZValue(1);  // ȷ���ؼ������ϲ�
	proxyWidget->setFlag(QGraphicsItem::ItemIgnoresTransformations);

	mpGraphicsView->setScene(mpGraphicsScene);
	mpGraphicsView->setSceneRect(mpImageItem->boundingRect());
	mpGraphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    mpGraphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	layout->addWidget(mpGraphicsView);
	this->setLayout(layout);
	int nwidth = mpGraphicsView->width() * 3;
    int nheight = mpGraphicsView->height() * 3;
    mpGraphicsView->setSceneRect(QRectF(-(nwidth / 2), -(nheight / 2), nwidth, nheight));

	mpGraphicsView->centerOn((QGraphicsItem*)mpImageItem);
	mpGraphicsView->show();

	proxyWidget->setPos(mpGraphicsView->mapToScene(0, 0));

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
	proxyWidget->setPos(mpGraphicsView->mapToScene(0, 0));
	QWidget::resizeEvent(_event);
	return;
}