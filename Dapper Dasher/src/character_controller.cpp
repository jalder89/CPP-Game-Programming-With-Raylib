#include "character_controller.h"

CharacterController::CharacterController(Character* character)
{
    characterPtr =  character;
    isGrounded = false;
}

bool CharacterController::GroundCheck(View* Viewport)
{
    return characterPtr->positionY >= Viewport->Height - characterPtr->height;
}

void CharacterController::UpdateMovement(View* Viewport)
{
    isGrounded = GroundCheck(Viewport);

    if (IsKeyDown(KEY_A) && characterPtr->positionX > 0)
    {
        characterPtr->positionX -= (characterPtr->speed);
    }

    if (IsKeyDown(KEY_D) && characterPtr->positionX < Viewport->Width - characterPtr->width)
    {
        characterPtr->positionX += (characterPtr->speed);
    }

    if (IsKeyPressed(KEY_SPACE) && isGrounded)
    {
        characterPtr->velocity += -characterPtr->jumpVelocity;
        isGrounded = false;
    }

    ApplyGravity();
}


void CharacterController::ApplyGravity()
{
    if (!isGrounded)
    {
        // Acceleration due to gravity. (Pixels/Frame)/Frame
        characterPtr->velocity += gravity * GetFrameTime();
    } 
    else
    {
        characterPtr->velocity = 0;
    }

    characterPtr->positionY += characterPtr->velocity;
}