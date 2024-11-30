#include "historywidget.h"
#include "ui_historywidget.h"
#include "App.h"
#include <QString>

HistoryWidget::HistoryWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HistoryWidget)
{
    ui->setupUi(this);
    /*
        Our App is hard set, to only allow 10 readings per account
        When you click on a button to display, a graph you are clicking, of these connects are called.

    */
    buttons[0] = ui->reading1;
    buttons[1] = ui->reading2;
    buttons[2] = ui->reading3;
    buttons[3] = ui->reading4;
    buttons[4] = ui->reading5;
    buttons[5] = ui->reading6;
    buttons[6] = ui->reading7;
    buttons[7] = ui->reading8;
    buttons[8] = ui->reading9;
    buttons[9] = ui->reading10;

    for (int i = 0; i < 10; ++i) {
        connect(buttons[i], SIGNAL (released()), this, SLOT (showCharts()));
    }
    /*
        These are used to display the number readings under the graph.
    */

    points[0] = ui->point1;
    points[1] = ui->point2;
    points[2] = ui->point3;
    points[3] = ui->point4;
    points[4] = ui->point5;
    points[5] = ui->point6;
    points[6] = ui->point7;
    points[7] = ui->point8;
    points[8] = ui->point9;
    points[9] = ui->point10;
    points[10] = ui->point11;
    points[11] = ui->point12;
    points[12] = ui->point13;
    points[13] = ui->point14;
    points[14] = ui->point15;
    points[15] = ui->point16;
    points[16] = ui->point17;
    points[17] = ui->point18;
    points[18] = ui->point19;
    points[19] = ui->point20;
    points[20] = ui->point21;
    points[21] = ui->point22;
    points[22] = ui->point23;
    points[23] = ui->point24;

    /*
       Our bar graph is constructed using labels, these arrays are used to construct it.
    */

    labels[0] = ui->label1;
    labels[1] = ui->label2;
    labels[2] = ui->label3;
    labels[3] = ui->label4;
    labels[4] = ui->label5;
    labels[5] = ui->label6;
    labels[6] = ui->label7;
    labels[7] = ui->label8;
    labels[8] = ui->label9;
    labels[9] = ui->label10;
    labels[10] = ui->label11;
    labels[11] = ui->label12;
    labels[12] = ui->label13;
    labels[13] = ui->label14;
    labels[14] = ui->label15;
    labels[15] = ui->label16;
    labels[16] = ui->label17;
    labels[17] = ui->label18;
    labels[18] = ui->label19;
    labels[19] = ui->label20;
    labels[20] = ui->label21;
    labels[21] = ui->label22;
    labels[22] = ui->label23;
    labels[23] = ui->label24;

    /*
        Connect are buttons on the page to operated function.
    */

    connect(ui->chartButton, SIGNAL (released()), this, SLOT (showChart()));
    connect(ui->circleButton, SIGNAL (released()), this, SLOT (showCircle()));
    connect(ui->bodyButton, SIGNAL (released()), this, SLOT (showBody()));
    connect(ui->backButton, SIGNAL (released()), this, SLOT (pressBack()));
}
/*
Prevent memory leaks
*/
HistoryWidget::~HistoryWidget()
{
    delete ui;
}


/*
When Main page of HistoryWidget is viewed it is because this function is envoked.
*/
void HistoryWidget::reload() {
    ui->stackedWidget->setCurrentIndex(0);
    int i = 0;
    //Checking if there is an account
    if (App::user() != nullptr) {
        for (const std::string& time : App::user()->readingTimes) {
            QString text = QString::fromStdString(time);
            buttons[i]->setText(text);
            buttons[i++]->setVisible(true);
        }
    //Display all the buttons that have readings.
    }

    for (; i < 10; ++i) { buttons[i]->setVisible(false); }
    showChart();
}
//bar chart connect
void HistoryWidget::showCharts() {
    setReading();
    setPoints();
    ui->stackedWidget->setCurrentIndex(1);
}
//Find  which reading, was sekected, set it to reading to allow,
void HistoryWidget::setReading(){
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    for (int i = 0; i < 10; ++i) {
        if (buttons[i] == button) {
            reading = App::user()->readings.at(i);
            break;
        }
    }

}

//connects to change and reload pages.
void HistoryWidget::showChart() { ui->chartStack->setCurrentIndex(0); }
void HistoryWidget::showBody() { ui->chartStack->setCurrentIndex(2); }
void HistoryWidget::pressBack() { reload(); }


//Set the text and height of the bar graph, depending on the reading.
void HistoryWidget::setPoints() {
    int x, y, w, h;

    for (int i = 0; i < 24; ++i) {
        x = points[i]->x();
        w = points[i]->width();
        h = 2.5 * reading[i].first;
        y = 520 - h;

        QString num = QString::number(reading[i].first); //iterate through the readings
        labels[i]->setText(num);

        switch (reading[i].second) {
        //if 1 good, 0 neturl and -1 worse, set style sheel of the labels accordingly
        case 1:
            points[i]->setStyleSheet("background-color: rgb(195, 70, 70);");
            break;
        case 0:
            points[i]->setStyleSheet("background-color: rgb(70, 140, 75);");
            break;
        case -1:
            points[i]->setStyleSheet("background-color: rgb(70, 100, 145);");
            break;
        default:
            break;

        }

        points[i]->resize(w, h);
        points[i]->move(x, y);
    }
}

void HistoryWidget::showCircle() {

    //Set image on the Qlabel
    QPixmap image(":images/circleGraph.png");
    ui->imgCircleImg->setScaledContents(true);

    QPainterPath groupPath;

    QPainter Painter(&image);
    Painter.setRenderHint(QPainter::Antialiasing);

    QPen linepen(Qt::red);
    linepen.setCapStyle(Qt::RoundCap);
    linepen.setWidth(10);
    Painter.setPen(linepen);

    int t=(App::user()->readings.size());

    if(t>0){
        setReading();
        //setPointsPainter is called twice and for left and right
        setPointsPainter(&groupPath, 0);
        Painter.fillPath(groupPath, QColor(0,255,0,60));
        setPointsPainter(&groupPath,1);
        Painter.fillPath(groupPath, QColor(255,0,0,120));

    }


    ui->imgCircleImg->setPixmap(image);
    ui->chartStack->setCurrentIndex(1);

}

void HistoryWidget::setPointsPainter(QPainterPath *g,int evenOrOdd){
    double allAngles[12]={M_PI/2,(2*M_PI)/3,(5*M_PI )/6,M_PI,(7*M_PI)/6,(4*M_PI)/3,(3*M_PI)/2,(5*M_PI)/3,(11*M_PI)/6,(2*M_PI),(M_PI)/6,(M_PI)/3};


    int i=0;
    int qx;
    int qy;
    int minimumX;
    int minimumY;
    int px=0;
    int py=0;

    while(i<12){
        //px is the value of the reading
        px=((1.5*(reading.at(2*(i)+evenOrOdd).first)));
        py=(0);
        //We then rotate it around, 0,0 iterating through the 12 different angles for the 12 differents
        qx=cos(allAngles[i])*px-sin(allAngles[i])*(py);
        qy=sin(allAngles[i])*px+cos(allAngles[i])*(py);
        //We have a minimum in order to prevent sharp edges forming on the graph.
        minimumX=cos(allAngles[i])*82-sin(allAngles[i])*(0);
        minimumY=sin(allAngles[i])*82+cos(allAngles[i])*(0);

        if(abs(minimumX)>abs(qx) || abs(minimumY)>abs(qy)){
            qx=minimumX;
            qy=minimumY;
        }
        if(i==0){

            g->moveTo(qx+400,qy+400);
        }
        //Image is 800 by 800, we move the the calculated point by 400,400, as that is the "0,0"
        g->lineTo(qx+400,qy+400);

        i++;
    }
    g->closeSubpath();

}
