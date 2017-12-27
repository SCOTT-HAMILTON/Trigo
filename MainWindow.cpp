#include "MainWindow.h"
#include <QBrush>
#include <QtMath>

#ifndef M_PI
#define M_PI 3.14159265359
#endif

MainWindow::MainWindow(QWidget *parent) : QWidget(parent),
    height(100), max_angle(63)
{
    scene = new QGraphicsScene;

    rect = new QGraphicsRectItem(200, 200, 20, 100);
    ground = new QGraphicsRectItem(0, 300, 420, 10);



    line1 = new QGraphicsLineItem;
    line2 = new QGraphicsLineItem;

    txtdist = new QLabel(tr("cable longueur : 0"));
    txtrayon = new QLabel(tr("rayon de haubanage : 0"));

    setLines(10);

    QBrush groundBrush(Qt::black);
    ground->setBrush(groundBrush);
    scene->addItem(rect);
    scene->addItem(ground);
    scene->addItem(line1);
    scene->addItem(line2);

    view = new QGraphicsView(scene);
    view->setFixedHeight(310);
    //view->setFixedWidth(420);

    txtheight = new QLabel(tr("Entrer la hauteur de votre antenne :"));
    heightspinbox = new QDoubleSpinBox;
    txtangle = new QLabel(tr("Entrer l'angle de vos haubans :"));
    anglespinbox = new QDoubleSpinBox;


    heightspinbox->setMaximum(10000);
    anglespinbox->setMaximum(max_angle);

    heightspinbox->setValue(100);
    anglespinbox->setValue(10);

    controlLay = new QGridLayout;
    controlLay->addWidget(txtheight, 0, 0);
    controlLay->addWidget(heightspinbox, 0, 1);
    controlLay->addWidget(txtangle, 1, 0);
    controlLay->addWidget(anglespinbox, 1, 1);
    controlLay->addWidget(txtdist, 2, 0);
    controlLay->addWidget(txtrayon, 3, 0);


    mainLay = new QHBoxLayout;
    mainLay->addLayout(controlLay);
    mainLay->addWidget(view);

    setLayout(mainLay);

    QObject::connect(heightspinbox, SIGNAL(valueChanged(double)), this, SLOT(changeAntenneSize(double)));
    QObject::connect(anglespinbox, SIGNAL(valueChanged(double)), this, SLOT(changeAngleCable(double)));
}

void MainWindow::changeAntenneSize(double val){
    QString txt(tr("longueur de hauban : "));
    height = val;
    dist = qFabs(height/qCos(qDegreesToRadians(anglespinbox->value())));
    txt += QString::number(dist);
    txtdist->setText(txt);
    rayon = qTan(qDegreesToRadians(anglespinbox->value()))*height;
    txt = QString(tr("rayon de haubannage : "));
    txt += QString::number(rayon);
    txtrayon->setText(txt);
}

void MainWindow::changeAngleCable(double val){
    setLines(val);
}

void MainWindow::setLines(float angle){
    if (angle <= max_angle){
        float pos_x = 200.0f, pos_y = 200.0f;
        float rad = qDegreesToRadians(angle+90);
        dist = qFabs(100/qCos(qDegreesToRadians(angle)));
        pos_x += qCos(rad)*dist;
        pos_y += qSin(rad)*dist;

        line1->setLine(200, 200, pos_x, pos_y);

        pos_x = 220.0f; pos_y = 200.0f;
        rad = qDegreesToRadians(90-angle);
        pos_x += qCos(rad)*dist;
        pos_y += qSin(rad)*dist;

        line2->setLine(220, 200, pos_x, pos_y);

        dist = qFabs(height/qCos(qDegreesToRadians(angle)));
        QString txt(tr("longueur de hauban : "));
        txt += QString::number(dist);
        txtdist->setText(txt);

        rayon = qTan(qDegreesToRadians(angle))*height;
        txt = QString(tr("rayon de haubannage : "));
        txt += QString::number(rayon);
        txtrayon->setText(txt);
    }
}
