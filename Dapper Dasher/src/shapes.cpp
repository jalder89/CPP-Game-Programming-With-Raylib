#include "shapes.h"

Shape::Shape(View* Viewport)
{
    width = 50;
    height = 80;
    positionX = Viewport->Center.X - (width / 2);
    positionY = Viewport->Center.Y - (height / 2);
}

Shape::Shape(View* Viewport, int newWidth, int newHeight)
{
    width = newWidth;
    height = newHeight;
    positionX = Viewport->Center.X - (width / 2);
    positionY = Viewport->Center.Y - (height / 2);
}