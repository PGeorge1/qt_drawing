#include "mainwindow.h"
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
   logoWidget *widget = new logoWidget (this);
   setCentralWidget (widget);
}

logoWidget::logoWidget (QWidget *parent) : QWidget (parent)
{
    resize (50, 50);
}


void draw_fractals (QPainter &painter, QPoint central_point, int radius)
{
  if (radius == 0) return;

  double height = radius;
  painter.drawEllipse (central_point, radius, radius);
  draw_fractals (painter, central_point - QPoint (0, 2 * height / 3), radius / 4);
  draw_fractals (painter, central_point + QPoint (height / sqrt (3), height / 3), radius / 4);
  draw_fractals (painter, central_point + QPoint (-height / sqrt (3), height / 3), radius / 4);
}


void logoWidget::paintEvent (QPaintEvent *event)
{
    QPainter painter (this);

    painter.setBackground(QBrush (Qt::white));
    // QColor

    painter.setPen (QPen (QBrush (Qt::blue), 7));
    painter.setBrush (QBrush (Qt::red));

    QPoint center_widget (width () / 2, height () / 2);
    int radius = std::min (width (), height ()) / 4;
    painter.drawEllipse (center_widget, radius, radius);

    double triangle_height = height () / 2;

    painter.setPen (Qt::green);
    painter.setBrush (QBrush (Qt::white));
    QList<QPoint> points = {center_widget - QPoint (0, 2 * triangle_height / 3),
                            center_widget + QPoint (triangle_height / sqrt (3), triangle_height / 3),
                            center_widget + QPoint (-triangle_height / sqrt (3), triangle_height / 3)};

    QPolygon polygon (points);
    painter.drawPolygon (polygon);


    draw_fractals (painter, center_widget, height () / 2);
}


MainWindow::~MainWindow()
{
}

