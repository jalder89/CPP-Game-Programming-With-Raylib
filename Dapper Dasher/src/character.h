#pragma once
#include "view.h"

class Character
{
public:
    int width;
    int height;
    int positionX;
    int positionY;
    int speed;
    float velocity;
    float jumpVelocity;

    Character();
    Character(View* Viewport);
    Character(View* Viewport, int newWidth, int newHeight);
};