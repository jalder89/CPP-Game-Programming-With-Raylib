#include "shape_controller.h"
#include <iostream>

ShapeController::ShapeController(Shape* shape)
{
    controllerShapePtr =  shape;
    isGrounded = false;
}

bool ShapeController::GroundCheck(View* Viewport)
{
    return controllerShapePtr->positionY >= Viewport->Height - controllerShapePtr->height;
}

void ShapeController::UpdateMovement(View* Viewport)
{
    isGrounded = GroundCheck(Viewport);

    if (IsKeyDown(KEY_A) && controllerShapePtr->positionX > 0)
    {
        controllerShapePtr->positionX -= (controllerShapePtr->speed);
    }

    if (IsKeyDown(KEY_D) && controllerShapePtr->positionX < Viewport->Width - controllerShapePtr->width)
    {
        controllerShapePtr->positionX += (controllerShapePtr->speed);
    }

    if (IsKeyPressed(KEY_SPACE) && isGrounded)
    {
        controllerShapePtr->velocity += -controllerShapePtr->jumpVelocity;
        isGrounded = false;
        std::cout << controllerShapePtr->velocity << std::endl;
    }

    ApplyGravity();
}


void ShapeController::ApplyGravity()
{
    if (!isGrounded)
    {
        // Acceleration due to gravity. (Pixels/Frame)/Frame
        controllerShapePtr->velocity += gravity * GetFrameTime();
    } 
    else
    {
        controllerShapePtr->velocity = 0;
    }

    controllerShapePtr->positionY += controllerShapePtr->velocity;
}