#include "measurewidget.h"
#include "ui_measurewidget.h"
#include "Radotech.h"
#include "App.h"

MeasureWidget::MeasureWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MeasureWidget)
{
    ui->setupUi(this);
    connect(ui->okButton, SIGNAL (released()), this, SLOT (pressOk()));
}

MeasureWidget::~MeasureWidget()
{
    delete ui;
}

void MeasureWidget::reload() {
    if (App::user() == nullptr) {
        ui->errorLabel->setText("Please select a profile for metering.");
        ui->stackedWidget->setCurrentIndex(0);
    } else if (!Radotech::on()) {
        ui->errorLabel->setText("Please turn on your Radotech device.");
        ui->stackedWidget->setCurrentIndex(0);
    } else {
        ui->stackedWidget->setCurrentIndex(1);
    }
}

void MeasureWidget::pressOk() { reload(); }
