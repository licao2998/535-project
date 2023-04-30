#include "infowidget.h"
#include "ui_infowidget.h"

InfoWidget::InfoWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InfoWidget)
{
    ui->setupUi(this);

    this->move(150,50);
    //Set modal window properties
    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    setWindowModality(Qt::WindowModal);
    connect(ui->pushButton,&QPushButton::clicked,this,&InfoWidget::close);
}

InfoWidget::~InfoWidget()
{
    delete ui;
}
