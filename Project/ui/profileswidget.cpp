#include "profileswidget.h"
#include "ui_profileswidget.h"
#include "App.h"
#include <QString>

ProfilesWidget::ProfilesWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ProfilesWidget)
{
    ui->setupUi(this);

    buttons[0] = ui->newProfileButton;
    buttons[1] = ui->profile1Button;
    buttons[2] = ui->profile2Button;
    buttons[3] = ui->profile3Button;
    buttons[4] = ui->profile4Button;
    buttons[5] = ui->profile5Button;

    connect(buttons[0], SIGNAL (released()), this, SLOT (edit()));
    connect(buttons[1], SIGNAL (released()), this, SLOT (edit()));
    connect(buttons[2], SIGNAL (released()), this, SLOT (edit()));
    connect(buttons[3], SIGNAL (released()), this, SLOT (edit()));
    connect(buttons[4], SIGNAL (released()), this, SLOT (edit()));
    connect(buttons[5], SIGNAL (released()), this, SLOT (edit()));

    connect(ui->deleteButton, SIGNAL (released()), this, SLOT (deleteProfile()));
    connect(ui->saveButton, SIGNAL (released()), this, SLOT (save()));
    connect(ui->addButton, SIGNAL (released()), this, SLOT (addProfile()));
    connect(ui->cancelButton, SIGNAL (released()), this, SLOT (cancel()));
    connect(ui->backButton, SIGNAL (released()), this, SLOT (cancel()));
    connect(ui->checkBox, SIGNAL (clicked()), this, SLOT (select()));
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
    QPushButton* button = qobject_cast<QPushButton*>(sender());

    bool b = button == buttons[0];
    ui->deleteButton->setVisible(!b);
    ui->saveButton->setVisible(!b);
    ui->cancelButton->setVisible(b);
    ui->addButton->setVisible(b);
    ui->profileLabel->setVisible(!b);
    ui->checkBox->setVisible(!b);

    ui->nameText->setText("");
    if (!b) {
        for (int i = 1; i < 6; ++i) {
            if (button == buttons[i]) {
                user = users.at(i-1);
                break;
            }
        }
        QString name = QString::fromStdString(user->getName());
        ui->nameText->setText(name);

        ui->checkBox->setChecked(user == App::user());
    }

    ui->stackedWidget->setCurrentIndex(1);
}

void ProfilesWidget::save() {
    std::string newName = ui->nameText->displayText().toStdString();
    user->setName(newName);
    reload();
}

void ProfilesWidget::deleteProfile() {
    App::removeProfile(user);
    reload();
}

void ProfilesWidget::addProfile() {
    // Get the name string
    std::string newProfileName = ui->nameText->displayText().toStdString();
    // Add profile to the app
    App::addProfile(newProfileName);
    // Refresh the UI
    reload();
}

void ProfilesWidget::cancel() {
    reload();
}

void ProfilesWidget::select() {
    if (ui->checkBox->isChecked()) {
        App::setCurrentProfile(user);
    } else {
        ui->checkBox->setChecked(true);
    }
}
