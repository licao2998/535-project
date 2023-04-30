#include "rankwidget.h"
#include "ui_rankwidget.h"
#include <QFile>
#include <QDebug>

RankWidget::RankWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RankWidget)
{
    ui->setupUi(this);
    this->move(100,50);
    //Set modal window properties
    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    setWindowModality(Qt::WindowModal);

    connect(ui->pushButton,&QPushButton::clicked,this,&QWidget::close);

    //Read files, encapsulate data
    QFile file("rank.data");
    QTreeWidget *treeWidget = ui->treeWidget;
    treeWidget->setHeaderLabels(QStringList()<<"rank"<<"score");
    if(file.exists()){
        if(!file.open(QIODevice::ReadWrite))
        {
           qDebug() << "write json file failed2";
        }

        QString scorestr(file.readAll());
        QStringList strlist = scorestr.split("\n");

        file.close();

        for(int i=0;i<strlist.size();i++){
            if(i==3){
                break;
            }
            QTreeWidgetItem *item2 = new QTreeWidgetItem(QStringList()<<QString::number(i+1)<<strlist.at(i));

            treeWidget->addTopLevelItem(item2);
        }
    }



}

RankWidget::~RankWidget()
{
    delete ui;
}
