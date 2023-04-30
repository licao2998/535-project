#include "map2.h"

Map2::Map2(QWidget *parent) :
    QWidget(parent)
{
    //Upper and lower walls
    for(int i=0;i<310;i+=10)
    {
        mapRect.append(QRectF(i,0,10,10));
        mapRect.append(QRectF(i,270,10,10));
    }
    //Left and right walls
    for(int i=10;i<300;i+=10)
    {
        mapRect.append(QRectF(0,i,10,10));
        mapRect.append(QRectF(300,i,10,10));
    }

    //Special obstacles
    for(int i=100;i<200;i+=10)
    {
        mapRect.append(QRectF(170,i,10,10));
        mapRect.append(QRectF(140,i,10,10));
    }
}
