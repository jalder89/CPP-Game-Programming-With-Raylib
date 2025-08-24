#include "circle.h"

ShapeCircle::ShapeCircle(View* Viewport)
{
    x = Viewport->Center.X;
    y = Viewport->Center.Y;
    radius = 8.f * Viewport->Scale;
    // collider = new Collider(this);
    left_x = x - radius;
    right_x = x + radius;
    upper_y = y - radius;
    bottom_y = y + radius;
    speed = Viewport->Scale;
    color = YELLOW;
}

// ShapeCircle::~ShapeCircle()
// {
//     delete collider;
//     collider = nullptr;
// }