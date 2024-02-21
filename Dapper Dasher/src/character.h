#pragma once
#include <raylib.h>
#include "view.h"

class Character
{
public:
    int width;
    int height;
    Vector2 velocity;
    float velocityY;
    float moveVelocity;
    float jumpVelocity;
    Texture2D texture;
    Vector2 characterPosition;
    Rectangle characterRectangle;
    

    Character();
    ~Character();
    Character(View* Viewport);
};