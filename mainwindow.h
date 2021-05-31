#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();
};


class logoWidget : public QWidget
{
    Q_OBJECT
public:
    logoWidget (QWidget *parent);
protected:
    void paintEvent (QPaintEvent *event) override;
};
#endif // MAINWINDOW_H
