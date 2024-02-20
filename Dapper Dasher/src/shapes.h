#pragma once
#include "view.h"

class Shape
{
public:
    int width;
    int height;
    int positionX;
    int positionY;
    int speed;
    int velocity;

    Shape();
    Shape(View* Viewport);
    Shape(View* Viewport, int newWidth, int newHeight);
};