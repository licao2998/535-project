#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QTimer>
#include <QList>
#include <QDebug>
#include <QTime>
#include <QKeyEvent>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QFile>
#include <QFileInfo>
#include <QJsonObject>
#include <QDebug>
#include <QJsonArray>
#include <QTime>
#include <QRectF>
#include "mainwindow.h"
#include <QMessageBox>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QString str = QString("<html><head/><body><p><span style=\"font-size:12pt;\">%1</span><br/></p></body></html>").arg(score);
    ui->score_label->setText(str);

    mapRect = Map1(this).mapRect;
    snake.append(QRectF(100,50,snakeNodeWidth,snakeNodeHeight));
    snakeAI.append(QRectF(200,50,snakeNodeWidth,snakeNodeHeight));
    addRightRectF();
    addRightRectF();
    ai_init_addRightRectF();
    ai_init_addRightRectF();
    ai_init_addRightRectF();
    ai_init_addRightRectF();
    //Generate food
    QPointF point = x_notin_block();
    rewardNode.append(QRectF(point.x(),point.y(),snakeNodeWidth,snakeNodeWidth));

    QPointF point2 = x_notin_block();
    rewardNode.append(QRectF(point2.x(),point2.y(),snakeNodeWidth,snakeNodeWidth));

    timer = new QTimer(this);
    connect(timer,&QTimer::timeout,this,&Widget::timeOut);

    init_btn_connect();

}
//Plotting
void Widget::paintEvent(QPaintEvent *event)
{

    QPainter painter(this);
    QPen pen;
    QBrush brush(Qt::darkGreen);


    //Draw screen background

    painter.setBrush(brush);
    QPixmap pix;
    pix.load(":/background.png");
    painter.drawPixmap(0,0,310,280,pix);
    painter.setRenderHint(QPainter::Antialiasing, true);
    //Set pen color, width
    painter.setPen(QPen(QColor(180, 211, 200,100), 3));
    //Set the brush color
    painter.setBrush(QColor(150, 150, 150));

    //Draw the walls
    for(int i=0; i<mapRect.length(); i++){
        painter.drawRect(mapRect.at(i));
    }

    pen.setColor(Qt::black);
    brush.setColor(Qt::green);
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);
    painter.setPen(pen);
    //Draw the snake
    for(int i=0; i<snake.size(); i++){
        painter.drawRect(snake.at(i));
    }
    
    brush.setColor(Qt::blue);
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);
    for(int i=0; i<5; i++){
        painter.drawRect(snakeAI.at(i));
    }
    brush.setColor(Qt::red);
    //Draw the food
    painter.setBrush(brush);
    for(int i=0; i<rewardNode.length(); i++){
        painter.drawEllipse(rewardNode.at(i));
    }



    //Check if map and snake overlap
    if(!snake_notin_wall() && !flags ){
        flags = true;
        timer->stop();
        gameOver = true;
        //Game over
        infow = new InfoWidget(this);
        infow->show();

    }
    //Check whether a snake has eaten itself
    if(snakeStrike() && !flags){
        flags = true;
        timer->stop();
        gameOver = true;
        //Game over
        infow = new InfoWidget(this);
        infow->show();
    }

    QWidget::paintEvent(event);
}

//Delete ending data
void Widget::delete_ai_LastRectF()
{
    snakeAI.removeLast();
}

//Check if SnakeAI has eaten itself
bool Widget::willAiSnakeCollide(QPointF newPosition) {
    QRectF newHead = QRectF(newPosition, QSizeF(snakeNodeWidth, snakeNodeHeight));

    for (int i = 1; i < snakeAI.size(); i++) {
        if (snakeAI.at(i).intersects(newHead)) {
            return true;
        }
    }
    

    return false;
}

//SnakeAI move
void Widget::aiSnake()
{
    //change direction
    std::srand(std::time(nullptr));
    int r = (int)(4.0 * std::rand() / (RAND_MAX + 1.0));
    if(r==0 && ai_moveFlage != Left) {
        ai_addRightRectF();
    } else if(r==1 && ai_moveFlage != Right) {
        ai_addLeftRectF();
    } else if(r==2 && ai_moveFlage != Down) {
        ai_addTopRectF();
    } else if(r==3 && ai_moveFlage != Up){
        ai_addDownRectF();
    }
           
}

bool Widget::ifCollide()
{
    for(int i=0; i<snakeAI.length(); i++){
        for(int j=0; j<snake.length(); j++){
            if(snakeAI.at(i) == snake.at(j)){
                return true;
            }
        }
    }
   
    

    return false;
}


//Move up
void Widget::addTopRectF()
{
    if(snake.at(0).y()-snakeNodeHeight < 0){
        snake.insert(0,QRectF(QPointF(snake.at(0).x(),this->height()-snakeNodeHeight),
                              QPointF(snake.at(0).x()+snakeNodeWidth,this->height())));
    }else{
        snake.insert(0,QRectF(snake.at(0).topLeft()+QPointF(0,-snakeNodeHeight),snake.at(0).topRight()));
    }
}
//Move down
void Widget::addDownRectF()
{
    if(snake.at(0).y()+snakeNodeHeight*2 > this->height()){
        snake.insert(0,QRectF(QPointF(snake.at(0).x(),snakeNodeHeight),
                              QPointF(snake.at(0).x()+snakeNodeWidth,0)));
    }else{
        snake.insert(0,QRectF(snake.at(0).bottomLeft(),snake.at(0).bottomRight()+QPointF(0,snakeNodeHeight)));
    }
}
//Move left
void Widget::addLeftRectF()
{
    if(snake.at(0).x()-snakeNodeWidth < 0){
        snake.insert(0,QRectF(QPointF(310-snakeNodeWidth,snake.at(0).y()),
                              QPointF(310,snake.at(0).y()+snakeNodeHeight)));
    }else{
        snake.insert(0,QRectF(snake.at(0).topLeft()+QPointF(-snakeNodeWidth,0),snake.at(0).bottomLeft()));
    }
}
//Move right
void Widget::addRightRectF()
{
    if(snake.at(0).x()+snakeNodeWidth*2 > this->width()){
        snake.insert(0,QRectF(QPointF(0,snake.at(0).y()),
                              QPointF(snakeNodeWidth,snake.at(0).y()+snakeNodeHeight)));
    }else{
        snake.insert(0,QRectF(snake.at(0).topRight(),snake.at(0).bottomRight()+QPointF(snakeNodeWidth,0)));
    }
}


bool Widget::nextMoveWillHitMapRect(const QPointF &nextPosition) {
    QRectF nextRect(nextPosition, QSizeF(snakeNodeWidth, snakeNodeHeight));
    return !mapRect.contains(nextRect);
}

// AI Move up
void Widget::ai_addTopRectF() {
    QPointF newPosition = snakeAI.at(0).topLeft() + QPointF(0, -snakeNodeHeight);
    if (!willAiSnakeCollide(newPosition)) {
    //if (!willAiSnakeCollide(newPosition) && !nextMoveWillHitMapRect(newPosition)) {
        if (snakeAI.at(0).y() - snakeNodeHeight < 10) {
		 if (!ai_snake_notin_wall(newPosition)) {
                     //Do nothing
		 }
        } else {
            snakeAI.insert(0, QRectF(snakeAI.at(0).topLeft() + QPointF(0, -snakeNodeHeight), snakeAI.at(0).topRight()));
            ai_moveFlage = Up;
            delete_ai_LastRectF();
        }
    }
}

// AI Move down
void Widget::ai_addDownRectF() {
    QPointF newPosition = snakeAI.at(0).bottomLeft() + QPointF(0, snakeNodeHeight);
    if (!willAiSnakeCollide(newPosition)) {
        if (snakeAI.at(0).y() + snakeNodeHeight * 2 > 270) {
		if (!ai_snake_notin_wall(newPosition)) {
                    //Do nothing
		}
        } else {
            snakeAI.insert(0, QRectF(snakeAI.at(0).bottomLeft(), snakeAI.at(0).bottomRight() + QPointF(0, snakeNodeHeight)));
            ai_moveFlage = Down;
            delete_ai_LastRectF();
        }
    }
}

// AI Move left
void Widget::ai_addLeftRectF() {
    QPointF newPosition = snakeAI.at(0).topLeft() + QPointF(-snakeNodeWidth, 0);
    if (!willAiSnakeCollide(newPosition)) {
        if (snakeAI.at(0).x() - snakeNodeWidth < 10) {
		if (!ai_snake_notin_wall(newPosition)) {
                    //Do nothing
		}
        } else {
            snakeAI.insert(0, QRectF(snakeAI.at(0).topLeft() + QPointF(-snakeNodeWidth, 0), snakeAI.at(0).bottomLeft()));
            ai_moveFlage = Left;
            delete_ai_LastRectF();
        }
    }
}

// AI Move right
void Widget::ai_addRightRectF() {
    QPointF newPosition = snakeAI.at(0).topRight() + QPointF(snakeNodeWidth, 0);
    if (!willAiSnakeCollide(newPosition)) {
        if (snakeAI.at(0).x() + snakeNodeWidth * 2 > 300) {
          if (!ai_snake_notin_wall(newPosition)) {
              //Do nothing
          }
        } else {
            snakeAI.insert(0, QRectF(snakeAI.at(0).topRight(), snakeAI.at(0).bottomRight() + QPointF(snakeNodeWidth, 0)));
            delete_ai_LastRectF();
            ai_moveFlage = Right;
        }
    }
}

// AI Move right init
void Widget::ai_init_addRightRectF() {
    QPointF newPosition = snakeAI.at(0).topRight() + QPointF(snakeNodeWidth, 0);
    if (!willAiSnakeCollide(newPosition)) {
        if (snakeAI.at(0).x() + snakeNodeWidth * 2 > 300) {
            //Do nothing
        } else {
            snakeAI.insert(0, QRectF(snakeAI.at(0).topRight(), snakeAI.at(0).bottomRight() + QPointF(snakeNodeWidth, 0)));
            ai_moveFlage = Right;
        }
    }
}


//Delete ending data
void Widget::deleteLastRectF()
{
    snake.removeLast();
}

void Widget::timeOut()
{

    bool foodEaten = false;
    bool foodEaten_ai = false;
    int foodIndex = -1;
    int foodIndex_ai = -1;
    for (int i = 0; i < rewardNode.length(); i++) {
        if (rewardNode.at(i).contains(snake.at(0).topLeft() + QPointF(snakeNodeWidth / 2, snakeNodeHeight / 2))) {
            foodEaten = true;
            foodIndex = i;
            break;
        }
    }

    for (int i = 0; i < rewardNode.length(); i++) {
        if (rewardNode.at(i).contains(snakeAI.at(0).topLeft() + QPointF(snakeNodeWidth / 2, snakeNodeHeight / 2))) {
            foodEaten_ai = true;
            foodIndex_ai = i;
            break;
        }
    }

    if (foodEaten) {
        addscore();
        rewardNode.removeAt(foodIndex);
        rewardTimeOut();
        switch (moveFlage) {
            case Up:
                addTopRectF();
                break;
            case Down:
                addDownRectF();
                break;
            case Right:
                addRightRectF();
                break;
            case Left:
                addLeftRectF();
                break;
            default:
                break;
        }
    } else {
        switch (moveFlage) {
            case Up:
                addTopRectF();
                break;
            case Down:
                addDownRectF();
                break;
            case Right:
                addRightRectF();
                break;
            case Left:
                addLeftRectF();
                break;
            default:
                break;
        }
        deleteLastRectF();
    }
    if (foodEaten_ai) {
        //addscore();
        rewardNode.removeAt(foodIndex_ai);
        rewardTimeOut();
        aiSnake();
    } else {
        aiSnake();
    }

    while (rewardNode.length() < 2) {
        QPointF point = x_notin_block();
        rewardNode.append(QRectF(point.x(), point.y(), snakeNodeWidth, snakeNodeWidth));
    }
    update();
    //Collide each other
    if (ifCollide()) {
    	//flags = true;
        timer->stop();
        gameOver = true;
        //Game over
        infow = new InfoWidget(this);
        infow->show();
     }
}


void Widget::rewardTimeOut()
{

    while (rewardNode.length() < 2) {
        QPointF point = x_notin_block();
        rewardNode.append(QRectF(point.x(), point.y(), snakeNodeWidth, snakeNodeWidth));
    }
}




void Widget::setMap(QString smap)
{
    mapstr = smap;
    if(smap.compare("map1")==0){
        QList<QRectF> map1 =  Map1(this).mapRect;
        mapRect = map1;
    }else if (smap.compare("map2")==0) {
        mapRect =  Map2(this).mapRect;
    }else if (smap.compare("map3")==0) {
        mapRect =  Map3(this).mapRect;
    }
}

bool Widget::snakeStrike()
{
    for(int i=0; i<snake.length(); i++){
        for(int j=i+1; j<snake.length(); j++){
            if(snake.at(i) == snake.at(j)){
                return true;
            }
        }
    }
    return false;

}

bool Widget::ai_snakeStrike()
{
    for(int i=0; i<snakeAI.length(); i++){
        for(int j=i+1; j<snakeAI.length(); j++){
            if(snakeAI.at(i) == snakeAI.at(j)){
                return true;
            }
        }
    }
    return false;

}

QPointF Widget::x_notin_block()
{
    bool flag = false;
    qsrand(QTime::currentTime().msec());
    int cx;
    int cy;
    while(true){
        cx = (qrand()%(200/20)*20)+10;
        cy = (qrand()%(200/20)*20)+10;
        for(int i=0;i<mapRect.length();i++){
            if(mapRect.at(i).left()==cx&&mapRect.at(i).top()==cy){
                flag = true;
                break;
            }
        }
        if(flag){
            flag = false;
            continue;
        }
        for(int i=0;i<snake.length();i++){
            if(snake.at(i).left()==cx&&snake.at(i).top()==cy){
                flag = true;
                break;
            }
        }
        if(flag){
            flag = false;
            continue;
        }
        for(int i=0;i<rewardNode.length();i++){
            if(rewardNode.at(i).left()==cx&&rewardNode.at(i).top()==cy){
                flag = true;
                break;
            }
        }
        if(flag){
            flag = false;
            continue;
        }
        if(!flag){
            break;
        }
    }
    return QPoint(cx,cy);
}

bool Widget::snake_notin_wall()
{
    for(int i=0;i<mapRect.length();i++)
    {
        if(mapRect.contains(snake.at(0))){
            return false;
        }

    }
    return true;
}

bool Widget::ai_snake_notin_wall(QPointF newPosition)
{
    QRectF newHead = QRectF(newPosition, QSizeF(snakeNodeWidth, snakeNodeHeight));
    for(int i=0;i<mapRect.length();i++)
    {
        if(mapRect.at(i).intersects(newHead)){
            return false;
        }

    }
    return true;
}

void Widget::addscore()
{
   score+=5;
   QString str = QString("<html><head/><body><p><span style=\"font-size:12pt;\">%1</span><br/></p></body></html>").arg(score);
   ui->score_label->setText(str);
}

void Widget::init_btn_connect()
{

    connect(ui->exit_btn,&QPushButton::clicked,this,[=](){
        if(!gameOver){
            timer->stop();
            gameOver = true;
            //Game over
            infow = new InfoWidget(this);
            infow->show();
        }
    });


    //Pause and back to the mainwindow
    connect(ui->save_exit_btn,&QPushButton::clicked,this,[=](){
        if(gameStart){
            if(gameOver){
                timer->stop();
                save_rank_data();
                //Do not save the game data, delete the file game.data
                if(QFile::exists("./game.data")){
                    QFile::remove("./game.data");
                }
            }else {
                timer->stop();
                gameOver = true;
                //Save game data
                savedata();
            }
        }else {
            if(!gameOver){
            //Save game data
            savedata();
            }else if(gameOver){
                timer->stop();
                save_rank_data();
                if(QFile::exists("./game.data")){
                    QFile::remove("./game.data");
                }
            }

        }

        mainwidget = new MainWindow;
        mainwidget->show();
        this->close();

    });

    //Click the up button
    connect(ui->up_btn,&QPushButton::clicked,this,[=](){
        if(moveFlage != Down&&!gameOver){
            moveFlage = Up;
        }
    });
    //Click the down button
    connect(ui->down_btn,&QPushButton::clicked,this,[=](){
        if(moveFlage != Up&&!gameOver){
            moveFlage = Down;
        }
    });
    //Click the left button
    connect(ui->left_btn,&QPushButton::clicked,this,[=](){
        if(moveFlage != Right&&!gameOver){
            moveFlage = Left;
        }
    });
    //Click the right button
    connect(ui->right_btn,&QPushButton::clicked,this,[=](){
        if(moveFlage != Left&&!gameOver){
            moveFlage = Right;
        }
    });
    //Click the pause button
    connect(ui->stop_btn,&QPushButton::clicked,this,[=](){
        if(gameStart && !gameOver){
            timer->stop();
            gameStart = false;
            ui->stop_btn->setText("start");
        }else if(!gameStart && !gameOver){
            timer->start(time);
            gameStart = true;
            ui->stop_btn->setText("pause");
            
        }
    });

}

void Widget::setScoreSTr(QString str)
{
     ui->score_label->setText(str);
}

void Widget::setSnakeList(QList<QRectF> snakelist)
{
    snake.clear();
    snake.clear();
    snake = snakelist;
}

void Widget::setFood(QPointF point)
{
    rewardNode.clear();
    rewardNode.append(QRectF(point.x(),point.y(),10,10));
}



//Save last game data
void Widget::savedata()
{

    QJsonArray array;
    for(int i=0;i<snake.size();i++){
        QJsonObject obj1;
        obj1.insert("x", snake.at(i).topLeft().x());
        obj1.insert("y", snake.at(i).topLeft().y());
        array.push_back(obj1);
    }
    QJsonObject levelobj;
    QJsonObject dirobj;
    QJsonObject mapobj;
    QJsonObject scoreobj;
    QJsonObject foodobj;
    if(rewardNode.size()==0){
        QPointF pointf = x_notin_block();

        foodobj.insert("x",pointf.x());
        foodobj.insert("y",pointf.y());
    }else {
        foodobj.insert("x",rewardNode.at(0).topLeft().x());
        foodobj.insert("y",rewardNode.at(0).topLeft().y());
    }

    int i=5;
    if(moveFlage==Up){
        i=1;
    }

    if(moveFlage==Down){
        i=2;
    }

    if(moveFlage==Left){
        i=3;

    }

    if(moveFlage==Right){
        i=4;

    }
    levelobj.insert("level",level);
    dirobj.insert("dir",i);
    mapobj.insert("map", mapstr);
    scoreobj.insert("score", score);

    array.push_back(levelobj);
    array.push_back(dirobj);
    array.push_back(foodobj);
    array.push_back(mapobj);
    array.push_back(scoreobj);
    //Write to data

    QJsonDocument jsonDoc(array);
    QByteArray ba = jsonDoc.toJson();
    QFile file("game.data");
    if(!file.open(QIODevice::ReadWrite|QIODevice::Truncate))
    {
       qDebug() << "write json file failed";
    }
    file.write(ba);

    file.close();
}


void Widget::save_rank_data()
{
    //Read files
    QFile file("rank.data");
    if(!file.exists()){
        int scorearr[1];
        scorearr[0]=score;
        //Write to data
        if(!file.open(QIODevice::WriteOnly))
        {
           qDebug() << "write json file failed3";
        }

        file.write(QString::number(scorearr[0]).toUtf8());
        file.close();
    }else {
        if(!file.open(QIODevice::ReadWrite))
        {
           qDebug() << "write json file failed1";
        }

        QString scorestr(file.readAll());
        QStringList strlist = scorestr.split("\n");
        strlist.append(QString::number(score));
        int scorearr[strlist.size()];
        for(int i=0;i<strlist.size();i++){
            scorearr[i] = strlist.at(i).toInt();
        }

        file.close();
        //Sorting
        std::sort(scorearr,scorearr+strlist.size(),[](int a, int b){ return a>b;});

        //Empty the file contents
        file.resize(0);
        //Write to data
        if(!file.open(QIODevice::WriteOnly))
        {
           qDebug() << "write json file failed3";
        }

        for(int j=0;j<strlist.size()-1;j++){
            file.write(QString::number(scorearr[j]).append("\n").toUtf8());
        }
        file.write(QString::number(scorearr[strlist.size()-1]).toUtf8());
        file.close();
    }
}

//Set difficulty level
void Widget::setLevel(QString levelstr)
{

    if(levelstr.compare("1")==0){
        level = 1;
        time = 500;
    }else if (levelstr.compare("2")==0) {
        level = 2;
        time = 300;
    }else if(levelstr.compare("3")==0){
        level = 3;
        time = 100;
    }
}

void Widget::setDirection(QString dir)
{
    if(dir.compare("1")==0){
        moveFlage = Up;
    }else if (dir.compare("2")==0) {
        moveFlage = Down;
    }else if(dir.compare("3")==0){
        moveFlage = Left;
    }else if(dir.compare("4")==0){
        moveFlage = Right;
    }
}

Widget::~Widget()
{
    delete ui;
}
