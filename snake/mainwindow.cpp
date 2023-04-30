#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFile>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QFile>
#include <QJsonObject>
#include <QDebug>
#include <QJsonArray>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Set Background
    QPixmap pixmap = QPixmap(":/grass.jpg").scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(QPalette::Background, QBrush(pixmap));
    this->setPalette(palette);


    //Dynamically add a "continue game" button depending on the existence of the file game.data
    QFile file("game.data");
    if(file.exists()){


        snakelist.clear();
        //Add "continue" button
        if(continueBtn==NULL){

            continueBtn = new QPushButton("CONTINUE",this);
            continueBtn->resize(93,28);
            continueBtn->move(200,60);
        }
        //Read files, encapsulate data
        QFile file("game.data");
        if(!file.open(QIODevice::ReadOnly))
        {
            qDebug() << "read json file failed";
        }
        QByteArray ba = file.readAll();
        QJsonParseError e;
        QJsonDocument jsonDoc = QJsonDocument::fromJson(ba, &e);
        QJsonArray jsonarry = jsonDoc.array();

        //Encapsulate snake
        for(int i=0;i<jsonarry.size()-5;i++){

            int cx = jsonarry.at(i).toObject().value("x").toInt();
            int cy = jsonarry.at(i).toObject().value("y").toInt();
            QRectF rec(cx,cy,10,10);
            snakelist.append(rec);
        }
        //Encapsulate difficulty level
        level = QString::number(jsonarry.at(jsonarry.size()-5).toObject().value("level").toInt());
        //Encapsulate directions
        dir = QString::number(jsonarry.at(jsonarry.size()-4).toObject().value("dir").toInt());

        //Encapsulate food
        foodP.setX(jsonarry.at(jsonarry.size()-3).toObject().value("x").toInt());
        foodP.setY(jsonarry.at(jsonarry.size()-3).toObject().value("y").toInt());

        //Encapsulate map
         mapstr = QString(jsonarry.at(jsonarry.size()-2).toObject().value("map").toString());
        //Encapsulate score
        score = jsonarry.at(jsonarry.size()-1).toObject().value("score").toInt();

        if(!connFlag){
            if(continueBtn!=NULL){
                connect(continueBtn,&QPushButton::clicked,this,[=](){
                    playWidget = new Widget;
                    playWidget->score=score;
                    playWidget->setDirection(dir);
                    playWidget->setLevel(level);
                    QString str = QString("<html><head/><body><p><span style=\"font-size:12pt;\">%1</span><br/></p></body></html>").arg(score);
                    playWidget->setScoreSTr(str);
                    playWidget->setSnakeList(snakelist);
                    playWidget->setMap(mapstr);
                    playWidget->setFood(foodP);
                    playWidget->show();
                    this->close();
                });
                connFlag = true;
            }
        }

    }else{
        continueBtn=NULL;
    }

    connect(ui->startButton,&QPushButton::clicked,this,&MainWindow::onstart_click);
    connect(ui->scoreButton,&QPushButton::clicked,this,&MainWindow::onrank_click);

    connect(ui->endButto,&QPushButton::clicked,this,[=](){
        this->close();
    });

}


void MainWindow::onstart_click()
{
    chooseWidget = new choose;
    chooseWidget->setmainwidget(this);
    chooseWidget->show();
}


void MainWindow::onrank_click()
{
    rankWidget = new RankWidget(this);
    rankWidget->show();
}


void MainWindow::deletBtn()
{
    if(continueBtn!=NULL){
        qDebug()<<"in delete btn"<<endl;
        continueBtn->hide();
    }
}

void MainWindow::save_rank()
{

    //Read files
    QFile rankfile("rank.data");
    QFile gamefile("game.data");
    if(!gamefile.exists()){
        //if game.data does not exist

        //
    }else if(!rankfile.exists()){
        //game.data exists,rank.data does not exist
        int scorearr[1];
        scorearr[0]=score;
        //Write to data
        if(!rankfile.open(QIODevice::WriteOnly))
        {
           qDebug() << "write json file failed3";
        }

        rankfile.write(QString::number(scorearr[0]).toUtf8());
        rankfile.close();


    }else{
        //game.data exists,rank.data exists
        if(!rankfile.open(QIODevice::ReadWrite))
        {
           qDebug() << "write json file failed1";
        }

        QString scorestr(rankfile.readAll());
        QStringList strlist = scorestr.split("\n");
        strlist.append(QString::number(score));
        int scorearr[strlist.size()];
        for(int i=0;i<strlist.size();i++){
            scorearr[i] = strlist.at(i).toInt();
        }

        rankfile.close();
        //Sorting
        std::sort(scorearr,scorearr+strlist.size(),[](int a, int b){ return a>b;});

        //Empty the file contents
        rankfile.resize(0);
        //Write to data
        if(!rankfile.open(QIODevice::WriteOnly))
        {
           qDebug() << "write json file failed3";
        }

        for(int j=0;j<strlist.size()-1;j++){
            rankfile.write(QString::number(scorearr[j]).append("\n").toUtf8());
        }
        rankfile.write(QString::number(scorearr[strlist.size()-1]).toUtf8());
        rankfile.close();

    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
