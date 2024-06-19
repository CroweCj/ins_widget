#include "collapsible_widget.h"
#include "histogram_widget.h"
#include <QPushButton>
#include <QDebug>



QVBoxLayout* contentLayout;

CollapsibleWidget::CollapsibleWidget(QWidget* _parent) 
	: QWidget(_parent)
	, mpCollapsibleBtn(nullptr)
	, mMainLayout(nullptr)
	, mpContentWidget(nullptr)
{
	mpCollapsibleBtn = new QPushButton(QString("Collapsible"), this);
	mpCollapsibleBtn->setFixedSize(400, 30);
	mMainLayout = new QVBoxLayout(this);

	mMainLayout->addWidget(mpCollapsibleBtn);

	QObject::connect(mpCollapsibleBtn, &QPushButton::clicked, this, &CollapsibleWidget::slot_collaps_widget);
}

CollapsibleWidget::~CollapsibleWidget()
{
}

void CollapsibleWidget::set_content_widget(QWidget* _content)
{

	mMainLayout->addWidget(_content);

	mpContentWidget = _content;
}

void CollapsibleWidget::set_image(const QImage& _image)
{
	//TODO:
}

void CollapsibleWidget::slot_collaps_widget()
{
	if (mpContentWidget->isVisible())
	{
		mpContentWidget->hide();
		mpCollapsibleBtn->setText(QString("Collapsible"));
	}
	else
	{
		mpContentWidget->show();
		mpCollapsibleBtn->setText(QString("Hide"));
	}

	this->adjustSize();
}

HistogramCollapsibleWidget::HistogramCollapsibleWidget(QWidget* _parent)
	: CollapsibleWidget(_parent)
{
	mpHistogramWidget = new HistogramWidget(this);
	set_content_widget(mpHistogramWidget);
}

HistogramCollapsibleWidget::~HistogramCollapsibleWidget()
{
}

void HistogramCollapsibleWidget::set_image(const QImage& _image)
{
	mpHistogramWidget->setImage(_image);
}

