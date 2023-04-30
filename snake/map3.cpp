#include "map3.h"

Map3::Map3(QWidget *parent) :
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

    for(int i=120;i<170;i+=10)
    {
        mapRect.append(QRectF(i,140,10,10));

    }
    for(int i=90;i<110;i+=10)
    {
        mapRect.append(QRectF(i,100,10,10));

    }
    for(int i=200;i<250;i+=10)
    {
        mapRect.append(QRectF(i,230,10,10));

    }
}
