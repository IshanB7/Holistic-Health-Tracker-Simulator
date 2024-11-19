#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "App.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    App();
}

MainWindow::~MainWindow()
{
    delete ui;
}
