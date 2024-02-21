#pragma once
#include <raylib.h>
#include "view.h"

class Character
{
public:
    int width;
    int height;
    int speed;
    float velocity;
    float jumpVelocity;
    Texture2D texture;
    Vector2 characterPosition;
    Rectangle characterRectangle;
    

    Character();
    Character(View* Viewport);
};