#include "map1.h"

Map1::Map1(QWidget *parent) :
    QWidget(parent)
{
    //上下墙体
    for(int i=0;i<300;i+=10)
    {
        mapRect.append(QRectF(i,0,10,10));
        mapRect.append(QRectF(i,300,10,10));
    }
    //左右墙体
    for(int i=10;i<310;i+=10)
    {
        mapRect.append(QRectF(0,i,10,10));
        mapRect.append(QRectF(290,i,10,10));
    }

    //特殊墙体
    for(int i=240;i<170;i+=10)
    {
        mapRect.append(QRectF(i,140,10,10));
    }
}
