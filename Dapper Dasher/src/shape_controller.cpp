#include "shape_controller.h"

ShapeController::ShapeController(Shape* shape)
{
    controllerShapePtr =  shape;
}

ShapeController::~ShapeController()
{
    delete controllerShapePtr;
    controllerShapePtr = nullptr;
}

void ShapeController::UpdateMovement(View* Viewport)
{
    if (IsKeyDown(KEY_D) && controllerShapePtr->positionX < Viewport->Width)
    {
        controllerShapePtr->positionX += (controllerShapePtr->speed);
    }

    if (IsKeyDown(KEY_A) && controllerShapePtr->positionX > 0)
    {
        controllerShapePtr->positionX -= (controllerShapePtr->speed);
    }

    if (IsKeyDown(KEY_SPACE))
    {
        controllerShapePtr->positionY -= (controllerShapePtr->velocity);
    }
}