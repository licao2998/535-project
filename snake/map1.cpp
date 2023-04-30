#include "map1.h"

Map1::Map1(QWidget *parent) :
    QWidget(parent)
{
    //上下墙体
    for(int i=0;i<310;i+=10)
    {
        mapRect.append(QRectF(i,0,10,10));
<<<<<<< HEAD
        mapRect.append(QRectF(i,270,10,10));
    }
    //左右墙体
    for(int i=10;i<300;i+=10)
=======
        mapRect.append(QRectF(i,260,10,10));
    }
    //左右墙体
    for(int i=10;i<270;i+=10)
>>>>>>> 72dfa4d273bb020e5973a1a1712d0d2cd7205b93
    {
        mapRect.append(QRectF(0,i,10,10));
        mapRect.append(QRectF(300,i,10,10));
    }

    //特殊墙体
<<<<<<< HEAD
    for(int i=140;i<200;i+=10)
=======
    for(int i=40;i<170;i+=10)
>>>>>>> 72dfa4d273bb020e5973a1a1712d0d2cd7205b93
    {
        mapRect.append(QRectF(i,140,10,10));
    }
}
