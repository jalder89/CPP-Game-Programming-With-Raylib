#pragma once
#include <raylib.h>
#include "view.h"
#include "collider.h"

class ShapeRectangle
{
public:
    int x;
    int y;
    int width;
    int height;
    int speed;
    int direction;
    // Collider* collider;
    int left_x;
    int right_x;
    int upper_y;
    int bottom_y;
    Color color = BLACK;

    ShapeRectangle(View* Viewport);
    // ~ShapeRectangle();
};