#include "profileswidget.h"
#include "ui_profileswidget.h"
#include "App.h"
#include <QString>

#include <QDebug>

ProfilesWidget::ProfilesWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ProfilesWidget)
{
    ui->setupUi(this);
    activeUser="null";

    buttons[0] = ui->newProfileButton;
    buttons[1] = ui->profile1Button;
    buttons[2] = ui->profile2Button;
    buttons[3] = ui->profile3Button;
    buttons[4] = ui->profile4Button;
    buttons[5] = ui->profile5Button;

    checkBox[0]= ui->checkBox0;
    checkBox[1]= ui->checkBox1;
    checkBox[2]= ui->checkBox2;
    checkBox[3]= ui->checkBox3;
    checkBox[4]= ui->checkBox4;


    //allows for the sending of data when clicking on a button
    //instead of having one function for each button
    //we can reduce reuse and recycle


    /*
        Using a QSignalMapper Class
        It allows to pass variables through a slot
        instead of select1,select2 etc, just have one select(int)


    */

    active=-1;
    signalMapper[0]=new QSignalMapper(this);
    signalMapper[1]=new QSignalMapper(this);
    signalMapper[2]=new QSignalMapper(this);
    signalMapper[3]=new QSignalMapper(this);
    signalMapper[4]=new QSignalMapper(this);


    connect(signalMapper[0], SIGNAL(mapped(int)), this, SLOT(select(int)));
    signalMapper[0]->setMapping(checkBox[0],0);
    connect(checkBox[0], SIGNAL(clicked()), signalMapper[0], SLOT(map()));

    connect(signalMapper[1], SIGNAL(mapped(int)), this, SLOT(select(int)));
    signalMapper[1]->setMapping(checkBox[1],1);
    connect(checkBox[1], SIGNAL(clicked()), signalMapper[1], SLOT(map()));

    connect(signalMapper[2], SIGNAL(mapped(int)), this, SLOT(select(int)));
    signalMapper[2]->setMapping(checkBox[2],2);
    connect(checkBox[2], SIGNAL(clicked()), signalMapper[2], SLOT(map()));

    connect(signalMapper[3], SIGNAL(mapped(int)), this, SLOT(select(int)));
    signalMapper[3]->setMapping(checkBox[3],3);
    connect(checkBox[3], SIGNAL(clicked()), signalMapper[3], SLOT(map()));

    connect(signalMapper[4], SIGNAL(mapped(int)), this, SLOT(select(int)));
    signalMapper[4]->setMapping(checkBox[4],4);
    connect(checkBox[4], SIGNAL(clicked()), signalMapper[4], SLOT(map()));

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
    //Check box intilizes

}

ProfilesWidget::~ProfilesWidget()
{
    delete ui;
}

void ProfilesWidget::reload() {
    ui->stackedWidget->setCurrentIndex(0);

    users = App::users();

    int i = 1;
    for (Profile* p : users) {
        QString name = QString::fromStdString(p->getName());
        if(name==activeUser){
            checkBox[i-1]->setChecked(true);
        }
        else{
            checkBox[i-1]->setChecked(false);
        }
        buttons[i]->setText(name);
        qDebug()<<"First Loop: "<< i;
        buttons[i]->setVisible(true);
        checkBox[i-1]->setVisible(true);
        ++i;

    }

    for (; i < 6; ++i) {
        buttons[i]->setVisible(false);
        qDebug()<<"Second Loop: "<< i;
        if(i<=5){
            checkBox[i-1]->setVisible(false);
        }

    }
    //qDebug()<<"Outside Loop: "<< i;
    if(users.size()<5){
        buttons[0]->setVisible(true);

        checkBox[i-2]->setVisible(false);

    }
    else{

         buttons[0]->setVisible(false);

         checkBox[i-2]->setVisible(true);


    }
}

void ProfilesWidget::edit() {
    QPushButton* button = qobject_cast<QPushButton*>(sender());

    bool b = button == buttons[0];
    ui->deleteButton->setVisible(!b);
    ui->saveButton->setVisible(!b);
    ui->cancelButton->setVisible(b);
    ui->addButton->setVisible(b);
    ui->profileLabel->setVisible(!b);
    //ui->checkBox->setVisible(!b);

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

        //ui->checkBox->setChecked(user == App::user());
    }

    ui->stackedWidget->setCurrentIndex(1);
}

void ProfilesWidget::save() {
    std::string newName = ui->nameText->displayText().toStdString();
    if(user->getNameQ()==activeUser){
        activeUser= ui->nameText->displayText();
    }
    user->setName(newName);
    reload();
}

void ProfilesWidget::deleteProfile() {
    if(user->getNameQ()==activeUser){
        activeUser="null";
    }
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


void ProfilesWidget::select(int id){
    if(activeUser=="null"){
        checkBox[id]->setChecked(true);
        activeUser=users[id]->getNameQ();
        App::setCurrentProfile(users[id]);
    }

    else if(users[id]->getNameQ()==activeUser){

        checkBox[id]->setChecked(false);
        activeUser="null";

    }
    else{
        checkBox[id]->setChecked(false);
    }



}
