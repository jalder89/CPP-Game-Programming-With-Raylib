#pragma once
#include "view.h"

class Shape
{
public:
    int width;
    int height;
    int positionX;
    int positionY;

    Shape(View* Viewport);
    Shape(View* Viewport, int newWidth, int newHeight);
};