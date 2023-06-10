#include "imagewidget.h"


ImageWidget::ImageWidget(QWidget* parent)
    : QWidget(parent)
{
}

void ImageWidget::setImage(const QImage& image)
{
    m_image = image;
    update();// Trigger a repaint of the widget
}

void ImageWidget::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    painter.drawImage(rect(), m_image);
    QWidget::paintEvent(event);
}
