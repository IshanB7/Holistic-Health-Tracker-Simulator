/********************************************************************************
** Form generated from reading UI file 'profileswidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROFILESWIDGET_H
#define UI_PROFILESWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProfilesWidget
{
public:
    QStackedWidget *stackedWidget;
    QWidget *profiles;
    QPushButton *newProfileButton;
    QPushButton *profile1Button;
    QPushButton *profile2Button;
    QPushButton *profile3Button;
    QPushButton *profile4Button;
    QPushButton *profile5Button;
    QCheckBox *checkBox0;
    QCheckBox *checkBox1;
    QCheckBox *checkBox2;
    QCheckBox *checkBox3;
    QCheckBox *checkBox4;
    QLabel *label;
    QWidget *profile;
    QFrame *frame;
    QPushButton *deleteButton;
    QPushButton *saveButton;
    QLabel *nameLabel;
    QLineEdit *nameText;
    QPushButton *addButton;
    QLabel *profileLabel;
    QPushButton *cancelButton;
    QPushButton *backButton;

    void setupUi(QWidget *ProfilesWidget)
    {
        if (ProfilesWidget->objectName().isEmpty())
            ProfilesWidget->setObjectName(QString::fromUtf8("ProfilesWidget"));
        ProfilesWidget->resize(444, 671);
        stackedWidget = new QStackedWidget(ProfilesWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setEnabled(true);
        stackedWidget->setGeometry(QRect(0, 0, 444, 671));
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 181, 104);"));
        profiles = new QWidget();
        profiles->setObjectName(QString::fromUtf8("profiles"));
        newProfileButton = new QPushButton(profiles);
        newProfileButton->setObjectName(QString::fromUtf8("newProfileButton"));
        newProfileButton->setGeometry(QRect(18, 20, 410, 40));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(newProfileButton->sizePolicy().hasHeightForWidth());
        newProfileButton->setSizePolicy(sizePolicy);
        newProfileButton->setCursor(QCursor(Qt::PointingHandCursor));
        newProfileButton->setAutoFillBackground(false);
        newProfileButton->setStyleSheet(QString::fromUtf8("text-align: left;\n"
"background-color: white;\n"
"color: black;\n"
"border-radius: 5px;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        newProfileButton->setIcon(icon);
        newProfileButton->setIconSize(QSize(32, 32));
        profile1Button = new QPushButton(profiles);
        profile1Button->setObjectName(QString::fromUtf8("profile1Button"));
        profile1Button->setEnabled(true);
        profile1Button->setGeometry(QRect(18, 120, 410, 40));
        sizePolicy.setHeightForWidth(profile1Button->sizePolicy().hasHeightForWidth());
        profile1Button->setSizePolicy(sizePolicy);
        profile1Button->setCursor(QCursor(Qt::PointingHandCursor));
        profile1Button->setAutoFillBackground(false);
        profile1Button->setStyleSheet(QString::fromUtf8("text-align: left;\n"
"background-color: white;\n"
"color: black;\n"
"border-radius: 5px;\n"
"padding-left: 5px;"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        profile1Button->setIcon(icon1);
        profile1Button->setIconSize(QSize(32, 32));
        profile2Button = new QPushButton(profiles);
        profile2Button->setObjectName(QString::fromUtf8("profile2Button"));
        profile2Button->setGeometry(QRect(18, 190, 410, 40));
        sizePolicy.setHeightForWidth(profile2Button->sizePolicy().hasHeightForWidth());
        profile2Button->setSizePolicy(sizePolicy);
        profile2Button->setCursor(QCursor(Qt::PointingHandCursor));
        profile2Button->setAutoFillBackground(false);
        profile2Button->setStyleSheet(QString::fromUtf8("text-align: left;\n"
"background-color: white;\n"
"color: black;\n"
"border-radius: 5px;\n"
"padding-left: 5px;"));
        profile2Button->setIcon(icon1);
        profile2Button->setIconSize(QSize(32, 32));
        profile3Button = new QPushButton(profiles);
        profile3Button->setObjectName(QString::fromUtf8("profile3Button"));
        profile3Button->setGeometry(QRect(18, 260, 410, 40));
        sizePolicy.setHeightForWidth(profile3Button->sizePolicy().hasHeightForWidth());
        profile3Button->setSizePolicy(sizePolicy);
        profile3Button->setCursor(QCursor(Qt::PointingHandCursor));
        profile3Button->setAutoFillBackground(false);
        profile3Button->setStyleSheet(QString::fromUtf8("text-align: left;\n"
"background-color: white;\n"
"color: black;\n"
"border-radius: 5px;\n"
"padding-left: 5px;"));
        profile3Button->setIcon(icon1);
        profile3Button->setIconSize(QSize(32, 32));
        profile4Button = new QPushButton(profiles);
        profile4Button->setObjectName(QString::fromUtf8("profile4Button"));
        profile4Button->setGeometry(QRect(18, 330, 410, 40));
        sizePolicy.setHeightForWidth(profile4Button->sizePolicy().hasHeightForWidth());
        profile4Button->setSizePolicy(sizePolicy);
        profile4Button->setCursor(QCursor(Qt::PointingHandCursor));
        profile4Button->setAutoFillBackground(false);
        profile4Button->setStyleSheet(QString::fromUtf8("text-align: left;\n"
"background-color: white;\n"
"color: black;\n"
"border-radius: 5px;\n"
"padding-left: 5px;"));
        profile4Button->setIcon(icon1);
        profile4Button->setIconSize(QSize(32, 32));
        profile5Button = new QPushButton(profiles);
        profile5Button->setObjectName(QString::fromUtf8("profile5Button"));
        profile5Button->setGeometry(QRect(18, 400, 410, 40));
        sizePolicy.setHeightForWidth(profile5Button->sizePolicy().hasHeightForWidth());
        profile5Button->setSizePolicy(sizePolicy);
        profile5Button->setCursor(QCursor(Qt::PointingHandCursor));
        profile5Button->setAutoFillBackground(false);
        profile5Button->setStyleSheet(QString::fromUtf8("text-align: left;\n"
"background-color: white;\n"
"color: black;\n"
"border-radius: 5px;\n"
"padding-left: 5px;"));
        profile5Button->setIcon(icon1);
        profile5Button->setIconSize(QSize(32, 32));
        checkBox0 = new QCheckBox(profiles);
        checkBox0->setObjectName(QString::fromUtf8("checkBox0"));
        checkBox0->setGeometry(QRect(400, 130, 16, 20));
        checkBox0->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"color: black;"));
        checkBox0->setIconSize(QSize(30, 30));
        checkBox1 = new QCheckBox(profiles);
        checkBox1->setObjectName(QString::fromUtf8("checkBox1"));
        checkBox1->setGeometry(QRect(400, 200, 16, 20));
        checkBox1->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"color: black;"));
        checkBox1->setIconSize(QSize(30, 30));
        checkBox2 = new QCheckBox(profiles);
        checkBox2->setObjectName(QString::fromUtf8("checkBox2"));
        checkBox2->setGeometry(QRect(400, 270, 16, 20));
        checkBox2->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"color: black;"));
        checkBox2->setIconSize(QSize(30, 30));
        checkBox3 = new QCheckBox(profiles);
        checkBox3->setObjectName(QString::fromUtf8("checkBox3"));
        checkBox3->setGeometry(QRect(400, 340, 16, 20));
        checkBox3->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"color: black;"));
        checkBox3->setIconSize(QSize(30, 30));
        checkBox4 = new QCheckBox(profiles);
        checkBox4->setObjectName(QString::fromUtf8("checkBox4"));
        checkBox4->setGeometry(QRect(400, 410, 16, 20));
        checkBox4->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"color: black;"));
        checkBox4->setIconSize(QSize(30, 30));
        label = new QLabel(profiles);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(390, 90, 49, 16));
        stackedWidget->addWidget(profiles);
        newProfileButton->raise();
        profile1Button->raise();
        profile2Button->raise();
        profile3Button->raise();
        profile4Button->raise();
        profile5Button->raise();
        checkBox1->raise();
        checkBox2->raise();
        checkBox3->raise();
        checkBox4->raise();
        label->raise();
        checkBox0->raise();
        profile = new QWidget();
        profile->setObjectName(QString::fromUtf8("profile"));
        frame = new QFrame(profile);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(19, 40, 410, 620));
        frame->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"border-radius: 20px;"));
        frame->setFrameShape(QFrame::NoFrame);
        deleteButton = new QPushButton(frame);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        deleteButton->setGeometry(QRect(152, 490, 110, 40));
        deleteButton->setCursor(QCursor(Qt::PointingHandCursor));
        deleteButton->setStyleSheet(QString::fromUtf8("color: orange;"));
        saveButton = new QPushButton(frame);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        saveButton->setGeometry(QRect(16, 550, 380, 40));
        saveButton->setCursor(QCursor(Qt::PointingHandCursor));
        saveButton->setStyleSheet(QString::fromUtf8("background-color: orange;\n"
"color: white;\n"
"border-radius: 15px;"));
        nameLabel = new QLabel(frame);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));
        nameLabel->setGeometry(QRect(30, 80, 80, 30));
        nameLabel->setStyleSheet(QString::fromUtf8("color: black;"));
        nameText = new QLineEdit(frame);
        nameText->setObjectName(QString::fromUtf8("nameText"));
        nameText->setGeometry(QRect(110, 87, 200, 15));
        nameText->setStyleSheet(QString::fromUtf8("border-bottom: 1px solid orange;\n"
"color: black;"));
        addButton = new QPushButton(frame);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        addButton->setGeometry(QRect(16, 550, 380, 40));
        addButton->setCursor(QCursor(Qt::PointingHandCursor));
        addButton->setStyleSheet(QString::fromUtf8("background-color: orange;\n"
"color: white;\n"
"border-radius: 15px;"));
        profileLabel = new QLabel(frame);
        profileLabel->setObjectName(QString::fromUtf8("profileLabel"));
        profileLabel->setGeometry(QRect(30, 240, 150, 30));
        profileLabel->setStyleSheet(QString::fromUtf8("color: black;"));
        cancelButton = new QPushButton(frame);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(150, 490, 110, 40));
        cancelButton->setCursor(QCursor(Qt::PointingHandCursor));
        cancelButton->setStyleSheet(QString::fromUtf8("color: orange;"));
        backButton = new QPushButton(profile);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        backButton->setGeometry(QRect(30, 5, 30, 30));
        backButton->setCursor(QCursor(Qt::PointingHandCursor));
        backButton->setStyleSheet(QString::fromUtf8("border: none;"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/back.png"), QSize(), QIcon::Normal, QIcon::Off);
        backButton->setIcon(icon2);
        backButton->setIconSize(QSize(30, 30));
        stackedWidget->addWidget(profile);

        retranslateUi(ProfilesWidget);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ProfilesWidget);
    } // setupUi

    void retranslateUi(QWidget *ProfilesWidget)
    {
        ProfilesWidget->setWindowTitle(QCoreApplication::translate("ProfilesWidget", "Form", nullptr));
        newProfileButton->setText(QCoreApplication::translate("ProfilesWidget", "New Profile", nullptr));
        profile1Button->setText(QString());
        profile2Button->setText(QString());
        profile3Button->setText(QString());
        profile4Button->setText(QString());
        profile5Button->setText(QString());
        checkBox0->setText(QString());
        checkBox1->setText(QString());
        checkBox2->setText(QString());
        checkBox3->setText(QString());
        checkBox4->setText(QString());
        label->setText(QCoreApplication::translate("ProfilesWidget", "Active", nullptr));
        deleteButton->setText(QCoreApplication::translate("ProfilesWidget", "Delete Profile", nullptr));
        saveButton->setText(QCoreApplication::translate("ProfilesWidget", "Save", nullptr));
        nameLabel->setText(QCoreApplication::translate("ProfilesWidget", "Name", nullptr));
        nameText->setText(QString());
        addButton->setText(QCoreApplication::translate("ProfilesWidget", "Add Profile", nullptr));
        profileLabel->setText(QString());
        cancelButton->setText(QCoreApplication::translate("ProfilesWidget", "Cancel", nullptr));
        backButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ProfilesWidget: public Ui_ProfilesWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFILESWIDGET_H
