#pragma once
#include <QApplication>
#include <QImage>
#include <QPainter>
#include <QWidget>
class ImageWidget : public QWidget
{
    Q_OBJECT

public:
    ImageWidget(QWidget* parent = nullptr);
    void setImage(const QImage& image);

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    QImage m_image;
};
