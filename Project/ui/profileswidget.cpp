#include "profileswidget.h"
#include "ui_profileswidget.h"
#include "App.h"
#include <QString>
#include <QButtonGroup>

ProfilesWidget::ProfilesWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ProfilesWidget)
{
    ui->setupUi(this);
    /*

        buttons[5] array, is the users buttons, that connect to the historyWidget.ui
        buttons[0] is the default user
        buttons[1-5] is for the 5 Profiles you can can add.

        they are buttons to allow as when you click on a "profile" you can edit it
    */

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



    currentButtons[0] = ui->current1;
    currentButtons[1] = ui->current2;
    currentButtons[2] = ui->current3;
    currentButtons[3] = ui->current4;
    currentButtons[4] = ui->current5;

    for (QPushButton* b : currentButtons) { b->setAttribute(Qt::WA_TransparentForMouseEvents); }

    /*
        All these buttons and connects are for the profile widget tab

    */
    QButtonGroup* buttonGroup = new QButtonGroup(this);
    buttonGroup->addButton(ui->maleRadioButton);
    buttonGroup->addButton(ui->femaleRadioButton);


    connect(ui->deleteButton, SIGNAL (released()), this, SLOT (deleteProfile()));
    connect(ui->saveButton, SIGNAL (released()), this, SLOT (save()));
    connect(ui->addButton, SIGNAL (released()), this, SLOT (addProfile()));
    connect(ui->cancelButton, SIGNAL (released()), this, SLOT (cancel()));
    connect(ui->backButton, SIGNAL (released()), this, SLOT (cancel()));
    connect(ui->checkBox, SIGNAL (clicked()), this, SLOT (select()));

    connect(ui->weightText, SIGNAL (textChanged(QString)), this, SLOT (checkNums()));
    connect(ui->heightText, SIGNAL (textChanged(QString)), this, SLOT (checkNums()));
}

ProfilesWidget::~ProfilesWidget()
{
    delete ui;
}
/*
    Default behaviour,
    Our amount of users are hard coded, we display the ones who are active and setText i.e the name

*/
void ProfilesWidget::reload() {
    ui->stackedWidget->setCurrentIndex(0);
    Profile* current = App::user();

    users = App::users();
    buttons[0]->setVisible(users.size() < 5);

    int i = 1;
    for (Profile* p : users) {
        QString name = QString::fromStdString(p->name);
        buttons[i]->setText(name);
        buttons[i]->setVisible(true);
        currentButtons[i-1]->setVisible(p == current);
        ++i;
    }

    for (; i < 6; ++i) {
        buttons[i]->setVisible(false);
        currentButtons[i-1]->setVisible(false);
    }
}

void ProfilesWidget::edit() {
    QPushButton* button = qobject_cast<QPushButton*>(sender());

    bool b = button == buttons[0];
    /*
        We reuse the page depending on if you are editing or adding a profile
        Editing:
            set delete, save, profile and checkbox  are a group,
                and
        Adding:
            set cancel and add button are another group.

    */
    ui->deleteButton->setVisible(!b);
    ui->saveButton->setVisible(!b);
    ui->profileLabel->setVisible(!b);
    ui->checkBox->setVisible(!b);

    ui->cancelButton->setVisible(b);
    ui->addButton->setVisible(b);

    ui->nameText->setText("");
    ui->weightText->setText("");
    ui->heightText->setText("");
    ui->maleRadioButton->setChecked(true);
    if (!b) {
        for (int i = 1; i < 6; ++i) {
            if (button == buttons[i]) {
                user = users.at(i-1);
                break;
            }
        }
        QString name = QString::fromStdString(user->name);
        QString weight = QString::number(user->weight);
        QString height = QString::number(user->height);

        ui->nameText->setText(name);
        ui->weightText->setText(weight);
        ui->heightText->setText(height);
        ui->femaleRadioButton->setChecked(!user->isMale);
        ui->checkBox->setChecked(user == App::user());
    }
    //After gettinng all the information we check as we do not allow empty fields
    checkNums();
    ui->stackedWidget->setCurrentIndex(1);
}
//CheckSums
void ProfilesWidget::checkNums() {
    bool isWeightNum, isHeightNum;
    ui->weightText->displayText().toInt(&isWeightNum);
    isWeightNum = !isWeightNum ? false : ui->weightText->displayText().toInt() > 0 && ui->weightText->displayText().toInt() < 1000;
    ui->heightText->displayText().toInt(&isHeightNum);
    isHeightNum = !isHeightNum ? false : ui->heightText->displayText().toInt() > 0 && ui->heightText->displayText().toInt() < 300;

    ui->addButton->setEnabled(isWeightNum && isHeightNum);
    ui->saveButton->setEnabled(isWeightNum && isHeightNum);
}
//the data is aved to the current user (user)
void ProfilesWidget::save() {
    std::string newName = ui->nameText->displayText().toStdString();
    short weight = ui->weightText->displayText().toInt();
    short height = ui->heightText->displayText().toInt();
    user->name = newName;
    user->weight = weight;
    user->height = height;
    user->isMale = ui->maleRadioButton->isChecked();
    reload();
}

//Remove profile
void ProfilesWidget::deleteProfile() {
    App::removeProfile(user);
    reload();
}
//if save button is selected, then we create a new profile and add it.
void ProfilesWidget::addProfile() {
    // Get the name string
    std::string newProfileName = ui->nameText->displayText().toStdString();
    short newWeight = ui->weightText->displayText().toInt();
    short newHeight = ui->heightText->displayText().toInt();
    bool newIsMale = ui->maleRadioButton->isChecked();
    // Add profile to the app
    App::addProfile(newProfileName, newIsMale, newWeight, newHeight);
    // Refresh the UI
    reload();
}

void ProfilesWidget::cancel() {
    reload();
}
//finds and set the selected profile as current, this allows the correct the graph(s) to be displayed
void ProfilesWidget::select() {
    if (ui->checkBox->isChecked()) {
        App::setCurrentProfile(user);
    } else {
        ui->checkBox->setChecked(true);
    }
}


