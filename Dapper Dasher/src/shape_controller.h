#pragma once
#include <raylib.h>
#include "shapes.h"
#include "view.h"

class ShapeController
{
    Shape* controllerShapePtr;
public:
    ShapeController(Shape* shape);
    ~ShapeController();

    void UpdateMovement(View* Viewport);
};