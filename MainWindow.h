#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsLineItem>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QDoubleSpinBox>
#include <QLabel>
#include <iostream>

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);

signals:

public slots:
    void changeAntenneSize(double);
    void changeAngleCable(double);

private:
    QGraphicsScene *scene;
    QGraphicsView *view;
    QGraphicsRectItem *rect;
    QGraphicsRectItem *ground;
    QGraphicsLineItem *line1;
    QGraphicsLineItem *line2;
    QHBoxLayout *mainLay;
    QGridLayout *controlLay;
    QDoubleSpinBox *heightspinbox;
    QDoubleSpinBox *anglespinbox;
    QLabel *txtheight;
    QLabel *txtangle;

    QLabel *txtdist;
    QLabel *txtrayon;

    double height;
    float dist;
    int max_angle;
    double rayon;

    void setLines(float angle);

};

#endif // MAINWINDOW_H
