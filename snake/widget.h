#ifndef WIDGET_H
#define WIDGET_H
#include <QRectF>
#include <QWidget>
#include <random>
#include "map1.h"
#include "map2.h"
#include "map3.h"
#include "infowidget.h"


class MainWindow;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:

    explicit Widget(QWidget *parent = 0);
    ~Widget();
    int score=0;
    int moveFlage = Right;
    int ai_moveFlage = Right;
    void paintEvent(QPaintEvent *);
    void setScoreSTr(QString );
    void setSnakeList(QList<QRectF> );
    void setFood(QPointF );
//    void setMainWidget(MainWindow *mainw);
    void setLevel(QString );
    void setDirection(QString );

public slots:
    void setMap(QString smap);

private:
    void ai_addTopRectF();
    void ai_addDownRectF();
    void ai_addLeftRectF();
    void ai_addRightRectF();
    void ai_init_addRightRectF();
    void addTopRectF();
    void addDownRectF();
    void addLeftRectF();
    void addRightRectF();
    void deleteLastRectF();
    bool snakeStrike();
    bool ai_snakeStrike();
    bool snake_notin_wall();
    bool ai_snake_notin_wall(QPointF newPosition);
    void addscore();
    void init_btn_connect();
    QPointF x_notin_block();
    void savedata();
    void save_rank_data();
    void aiSnake();
    void delete_ai_LastRectF();
    bool willAiSnakeCollide(QPointF newPosition);
    bool nextMoveWillHitMapRect(const QPointF &nextPosition);
    bool ifCollide();
protected slots:
    void timeOut();
    void rewardTimeOut();

private:
    Ui::Widget *ui;
    InfoWidget * infow;
    MainWindow *mainwidget;
    QList<QRectF> snake;//snake
    QList<QRectF> snakeAI;//AI snake
    int snakeNodeWidth = 10;
    int snakeNodeHeight = 10;
    QTimer *timer;
    int time = 500;
    bool flags=false;
    int level=1;//1:500,2:300,3:100
    bool gameOver = false;
    bool gameStart = false;
    QList<QRectF> rewardNode;
    QList<QRectF> mapRect;
    QString mapstr;
    //bool ispainted=false;
    enum Move{Left,Right,Up,Down};


};

#endif // WIDGET_H
