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

void RecoWidget::reload(){
    Profile *current=App::user();
    int i=0;
    int readAt=current->readings.size();
    QString appropriateAdvice;
    QChar bulletChar(0x2022);
    //QStringLiteral newLine("  A\n");
    if(readAt==0){
        appropriateAdvice="Add a reading to receive Advice";
        //add please add a reading
    }

    else{

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
void RecoWidget::save() {
    App::user()->setAdvice(ui->lineEdit->toPlainText());
    reload();
}

void RecoWidget::cancel(){
    ui->lineEdit->clear();
}


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

