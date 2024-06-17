#pragma once

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>

class CollapsibleWidget : public QWidget
{
	Q_OBJECT
public:
	CollapsibleWidget(QWidget* _parent = nullptr);
	~CollapsibleWidget();

	void set_content_widget(QWidget* _content);
private:
	QPushButton* mpCollapsibleBtn;
	QVBoxLayout* mMainLayout;
};