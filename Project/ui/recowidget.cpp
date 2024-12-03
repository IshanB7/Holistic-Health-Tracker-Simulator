#include "recowidget.h"
#include "ui_recowidget.h"
#include "App.h"
#include <QString>
#include <QButtonGroup>
#include <QStringLiteral>
#include "QDebug"
RecoWidget::RecoWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RecoWidget)
{
    ui->setupUi(this);
    connect(ui->save, SIGNAL (released()), this, SLOT (save()));
    connect(ui->cancel, SIGNAL (released()), this, SLOT (cancel()));

}

RecoWidget::~RecoWidget()
{
    delete ui;
}

/*
    Default behaviour:
    Three Cases
    1) no user in the system or current
    2) no reading to give recommendation too
    3) if 1) and 2) are not true, geneerate the advice
        3.a) if ==-1 it is a "bad" reading on EITHER, left or rightW
*/
void RecoWidget::reload(){

    QString appropriateAdvice;
    if (App::user() == nullptr){
        appropriateAdvice="Add a User...";
        ui->appRecomend->setPlainText(appropriateAdvice);
        return;

    }
    int i=0;
    int readAt=0;
    QChar bulletChar(0x2022);
    Profile *current=App::user();
    if(App::user()->readings.size()==0){
        appropriateAdvice="Add a reading to receive Advice";
    }

    else{
        readAt=current->readings.size();
        while(i<12){
            if (((current->getReading(readAt-1).at(2*(i)).second)==-1)||((current->getReading(readAt-1).at(2*(i)+1).second)==-1)){
                appropriateAdvice+=bulletChar;
                appropriateAdvice+=allAdvice(i)+"\n";

            }
            i++;
        }
    }

    ui->appRecomend->setPlainText(appropriateAdvice);
    ui->lineEdit->setText(current->getAdvice());
}
//Save advice in the textfield to a Profile QString
void RecoWidget::save() {
    App::user()->setAdvice(ui->lineEdit->toPlainText());
    reload();
}
//just clear it
void RecoWidget::cancel(){
    ui->lineEdit->clear();
}

//all advice, hard coded no LLM, although that be cool.
QString RecoWidget::allAdvice(int i){
    switch (i){
        case 0:
            return("Lung reading is poor, recommendation is cardio");

        case 1:
            return ("Pericardium reading is poor, recommendation is see a Heart Specialist ");

        case 2:
            return("Heart reading is poor we recommendation is cardio");

        case 3:
            return("Small Intestinge reading is poor, recommendation eat more fiber");

        case 4:
            return("Immunity reading is poor, recommendation Vitaime D");

        case 5:
            return("Large Intestine reading is poor, recommendation eat more fiber");

        case 6:
            return("Pancrease reading is poor, recommendation visit a Pancreatologists");

        case 7:
            return("Liver reading is poor, consume less alcohal");

        case 8:
            return("Kidney reading is poor, drink more water");

        case 9:
            return("Genitouriney reading is poor, see a urologist or gynecologist ");

        case 10:
            return("Gall Bladder reading is poor, recommendation consume less soda");

        case 11:
            return("Stomach reading is poor, recommendation eat more fiber");

        default:
            break;
        }
    return "should never be called";
}

