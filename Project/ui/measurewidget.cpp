#include "measurewidget.h"
#include "ui_measurewidget.h"
#include "Radotech.h"
#include "App.h"
#include <QTabWidget>

MeasureWidget::MeasureWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MeasureWidget)
{
    ui->setupUi(this);

    points[0] = ui->point1;
    points[1] = ui->point2;
    points[2] = ui->point3;
    points[3] = ui->point4;
    points[4] = ui->point5;
    points[5] = ui->point6;

    points[6] = ui->point7;
    points[7] = ui->point8;
    points[8] = ui->point9;
    points[9] = ui->point10;
    points[10] = ui->point11;
    points[11] = ui->point12;

    points[12] = ui->point13;
    points[13] = ui->point14;
    points[14] = ui->point15;
    points[15] = ui->point16;
    points[16] = ui->point17;
    points[17] = ui->point18;

    points[18] = ui->point19;
    points[19] = ui->point20;
    points[20] = ui->point21;
    points[21] = ui->point22;
    points[22] = ui->point23;
    points[23] = ui->point24;

    measureTimeout.setInterval(100);
    measureTimer.setInterval(500);
    connect(&measureTimeout, SIGNAL (timeout()), this, SLOT (refresh()));
    connect(&measureTimer, SIGNAL (timeout()), this, SLOT (showNextPoint()));
    connect(ui->okButton, SIGNAL (released()), this, SLOT (pressOk()));
    connect(ui->goButton, SIGNAL (released()), this, SLOT (pressGo()));
    connect(ui->measureButton, SIGNAL (released()), this, SLOT (pressMeasure()));
    connect(ui->doneButton, SIGNAL (released()), this, SLOT (pressDone()));
}

MeasureWidget::~MeasureWidget()
{
    delete ui;
}

void MeasureWidget::reload() {
    measureTimeout.stop();
    measureTimer.stop();
    if (Radotech::skinOn()) { Radotech::toggleSkin(); }

    if (App::user() == nullptr) {
        ui->errorLabel->setText("Please select a profile for metering.");
        ui->okButton->setVisible(false);
        ui->goButton->setVisible(true);
        ui->stackedWidget->setCurrentIndex(0);
    } else if (!Radotech::on()) {
        ui->errorLabel->setText("Please turn on your Radotech device.");
        ui->okButton->setVisible(true);
        ui->goButton->setVisible(false);
        ui->stackedWidget->setCurrentIndex(0);
    } else {
        ui->stackedWidget->setCurrentIndex(1);
        initMeasure();
        measureTimeout.start();
    }
}

void MeasureWidget::pressOk() { reload(); }

void MeasureWidget::pressGo() {
    QTabWidget* tabWidget = qobject_cast<QTabWidget*>(parentWidget()->parentWidget());
    tabWidget->setCurrentIndex(1);
}

void MeasureWidget::refresh() {
    if (!Radotech::on()) reload();
}

void MeasureWidget::pressMeasure() {
    ui->measureFrame->setVisible(true);
    ui->measureButton->setVisible(false);
    measureTimer.start();
    Radotech::toggleSkin();
}

void MeasureWidget::initMeasure() {
    reading = Radotech::getReading();
    setPoints();
    pointNum = 0;

    ui->measureFrame->setVisible(false);
    ui->doneButton->setVisible(false);
    ui->measureButton->setVisible(true);
}

void MeasureWidget::setPoints() {
    int x, y;
    for (int i = 0; i < 24; ++i) {
        y = 10 + (500 - 2.5 * reading[i]);
        x = points[i]->x();
        points[i]->move(x, y);
        points[i]->setVisible(false);
    }
}

void MeasureWidget::showNextPoint() {
    if (pointNum == 24) {
        App::user()->addReading(reading);
        ui->doneButton->setVisible(true);
        measureTimeout.stop();
        measureTimer.stop();
        Radotech::toggleSkin();
    } else {
        points[pointNum++]->setVisible(true);
    }
}

void MeasureWidget::pressDone() {
    QTabWidget* tabWidget = qobject_cast<QTabWidget*>(parentWidget()->parentWidget());
    tabWidget->setCurrentIndex(2);
}
