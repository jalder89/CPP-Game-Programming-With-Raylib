#include "rectangle.h"
#include "collider.h"

ShapeRectangle::ShapeRectangle(View* Viewport)
{
    x = Viewport->Width * 0.90f;
    y = Viewport->Height * 0.0625f;
    width = 16 * Viewport->Scale;
    height = 16 * Viewport->Scale;
    // collider = new Collider(this);
    left_x = x;
    right_x = x + width;
    bottom_y = y;
    upper_y = y + height;
    speed = Viewport->Scale + 2;
    direction = 1;
}