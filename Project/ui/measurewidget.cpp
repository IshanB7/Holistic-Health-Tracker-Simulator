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
    connect(ui->okButton, SIGNAL (released()), this, SLOT (pressOk()));
    connect(ui->goButton, SIGNAL (released()), this, SLOT (pressGo()));
}

MeasureWidget::~MeasureWidget()
{
    delete ui;
}

void MeasureWidget::reload() {
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
        ui->bgMeasure->setVisible(false);
        ui->measureButton->setVisible(true);
        ui->fakeButton->setVisible(false);
    }
}

void MeasureWidget::pressOk() { reload(); }

void MeasureWidget::pressGo() {
    QTabWidget* tabWidget = qobject_cast<QTabWidget*>(parentWidget()->parentWidget());
    tabWidget->setCurrentIndex(1);
}
