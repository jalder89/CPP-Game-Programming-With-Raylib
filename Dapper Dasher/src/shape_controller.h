#pragma once
#include <raylib.h>
#include "shapes.h"
#include "view.h"

class ShapeController
{
    Shape* controllerShapePtr;

    bool isGrounded;
    const int gravity = 10;             // Acceleration due to gravity. (Pixels/Frame)/FrameFrame

public:
    ShapeController(Shape* shape);

    bool GroundCheck(View* Viewport);
    void UpdateMovement(View* Viewport);
    void ApplyGravity();
};