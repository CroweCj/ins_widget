#include "collapsible_widget.h"

CollapsibleWidget::CollapsibleWidget(QWidget* _parent) 
	: QWidget(_parent)
	, mpCollapsibleBtn(nullptr)
	, mMainLayout(nullptr)
{
	mpCollapsibleBtn = new QPushButton(QString("Collapsible"), this);
	mpCollapsibleBtn->setFixedSize(400, 30);
	mMainLayout = new QVBoxLayout(this);

	mMainLayout->addWidget(mpCollapsibleBtn);
}

CollapsibleWidget::~CollapsibleWidget()
{
}

void CollapsibleWidget::set_content_widget(QWidget* _content)
{
	QVBoxLayout* contentLayout = new QVBoxLayout(this);
	contentLayout->addWidget(_content);
	mMainLayout->addLayout(contentLayout);
}