#include "profileswidget.h"
#include "ui_profileswidget.h"
#include "App.h"
#include <QString>

ProfilesWidget::ProfilesWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ProfilesWidget)
{
    ui->setupUi(this);

    buttons[0] = ui->addButton;
    buttons[1] = ui->button1;
    buttons[2] = ui->button2;
    buttons[3] = ui->button3;
    buttons[4] = ui->button4;
    buttons[5] = ui->button5;

    connect(buttons[0], SIGNAL (released()), this, SLOT (edit()));
    connect(buttons[1], SIGNAL (released()), this, SLOT (edit()));
    connect(buttons[2], SIGNAL (released()), this, SLOT (edit()));
    connect(buttons[3], SIGNAL (released()), this, SLOT (edit()));
    connect(buttons[4], SIGNAL (released()), this, SLOT (edit()));
    connect(buttons[5], SIGNAL (released()), this, SLOT (edit()));
}

ProfilesWidget::~ProfilesWidget()
{
    delete ui;
}

void ProfilesWidget::reload() {
    ui->stackedWidget->setCurrentIndex(0);

    users = App::users();
    buttons[0]->setVisible(users.size() < 5);

    int i = 1;
    for (Profile* p : users) {
        QString name = QString::fromStdString(p->getName());
        buttons[i]->setText(name);
        buttons[i]->setVisible(true);
        ++i;
    }

    for (; i < 6; ++i) { buttons[i]->setVisible(false); }
}

void ProfilesWidget::edit() {
    ui->stackedWidget->setCurrentIndex(1);
}
