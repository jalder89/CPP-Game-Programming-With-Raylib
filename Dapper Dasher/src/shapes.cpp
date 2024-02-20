#include "shapes.h"
#include <iostream>
using namespace std;

Shape::Shape()
{
    speed = 5;
    velocity = 5;

    width = 50;
    height = 120;

    positionX = 160;
    positionY = 90;
}

Shape::Shape(View* Viewport)
{
    speed = 5;
    velocity = 5;

    width = 50;
    height = 80;

    positionX = Viewport->Center.X - (width / 2);
    positionY = Viewport->Center.Y - (height / 2);
}

Shape::Shape(View* Viewport, int newWidth, int newHeight)
{
    speed = 5;
    velocity = 5;

    width = newWidth;
    height = newHeight;
    
    positionX = Viewport->Center.X - (width / 2);
    positionY = Viewport->Center.Y - (height / 2);
}