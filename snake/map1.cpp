#include "map1.h"

Map1::Map1(QWidget *parent) :
    QWidget(parent)
{
    //Upper and lower walls
    for(int i=0;i<310;i+=10)
    {
        mapRect.append(QRectF(i,0,10,10));
        mapRect.append(QRectF(i,270,10,10));
    }
    //Left and right walls
    for(int i=10;i<280;i+=10)
    {
        mapRect.append(QRectF(0,i,10,10));
        mapRect.append(QRectF(300,i,10,10));
    }

    //Special obstacles
    for(int i=140;i<200;i+=10)
    {
        mapRect.append(QRectF(i,140,10,10));
    }
}
