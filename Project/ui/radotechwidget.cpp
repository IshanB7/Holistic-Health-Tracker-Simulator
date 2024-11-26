#include "radotechwidget.h"
#include "ui_radotechwidget.h"
#include <QGraphicsColorizeEffect>
#include <QColor>

RadotechWidget::RadotechWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RadotechWidget)
    , radotech(Radotech(this))
{
    ui->setupUi(this);
    ui->battery->setValue(radotech.battery);
    connect(ui->power, SIGNAL (released()), this, SLOT (togglePower()));
    connect(ui->drain, SIGNAL (released()), this, SLOT (drainBattery()));
    connect(ui->charge, SIGNAL (released()), this, SLOT (chargeBattery()));
    // Set up the timer to drain the battery
    connect(&batteryDrainTimer, SIGNAL (timeout()), this, SLOT (decreaseBattery()));
    batteryDrainTimer.setInterval(2000); // Bettery will drain by 1% every 2 seconds
    batteryDrainTimer.start();
}

RadotechWidget::~RadotechWidget()
{
    delete ui;
}

void RadotechWidget::decreaseBattery() {
    if (radotech.isOn && radotech.battery > 0) {
        radotech.battery -= 1;
        ui->battery->setValue(radotech.battery);
    }

    if (radotech.battery == 0) togglePower();
}

void RadotechWidget::togglePower() {
    QGraphicsColorizeEffect* effect = new QGraphicsColorizeEffect();

    if (!radotech.isOn && radotech.battery > 0) {
        radotech.isOn = true;
        effect->setColor(QColor(255,122,0));
    } else {
        radotech.isOn = false;
        radotech.onSkin = false;
        effect->setColor(QColor(0,0,0));
    }

    ui->power->setGraphicsEffect(effect);
}

void RadotechWidget::drainBattery() {
    if (radotech.battery > 1) {
        radotech.battery = 1;
        ui->battery->setValue(1);
    }
}

void RadotechWidget::chargeBattery() {
    radotech.battery = 100;
    ui->battery->setValue(100);
}

void RadotechWidget::toggleSkin() {
    QGraphicsColorizeEffect* effect = new QGraphicsColorizeEffect();
    if (radotech.onSkin) {
        effect->setColor(QColor(0, 255, 0));
    } else {
        effect->setColor(QColor(255, 122, 0));
    }

    ui->power->setGraphicsEffect(effect);
}
