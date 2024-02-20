#pragma once
#include <raylib.h>
#include "view.h"
#include "collider.h"

class ShapeCircle
{
public:
    int x;
    int y;
    int speed;
    int radius;
    // Collider* collider;
    int left_x;
    int right_x;
    int upper_y;
    int bottom_y;
    Color color;

    ShapeCircle(View* Viewport);
    // ~ShapeCircle();
};