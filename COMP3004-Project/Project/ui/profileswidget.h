#ifndef PROFILESWIDGET_H
#define PROFILESWIDGET_H

#include <QWidget>
#include <QPushButton>
#include "Profile.h"
#include <vector>
#include <QSignalMapper>
#include <QString>
namespace Ui {
class ProfilesWidget;
}

class ProfilesWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ProfilesWidget(QWidget *parent = nullptr);
    ~ProfilesWidget();
    void reload();

private slots:
    void edit();
    void save();
    void deleteProfile();
    void addProfile();
    //void select();
    void cancel();
    void select(int);

private:
    Ui::ProfilesWidget *ui;
    QPushButton* buttons[6];
    std::vector<Profile*> users;
    Profile* user;
    int active;
    QString activeUser;
    QAbstractButton* checkBox[5];
    QSignalMapper* signalMapper[5];
};

#endif // PROFILESWIDGET_H
