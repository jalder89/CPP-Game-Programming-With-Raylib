#include "character_controller.h"

CharacterController::CharacterController(Character* character)
{
    characterPtr =  character;
    isGrounded = false;
}

bool CharacterController::GroundCheck(View* Viewport)
{
    return characterPtr->characterPosition.y >= Viewport->Height - characterPtr->height;
}

// Manage character input
void CharacterController::UpdateMovement(View* Viewport)
{
    isGrounded = GroundCheck(Viewport);

    if (IsKeyDown(KEY_A) && characterPtr->characterPosition.x > 0)
    {
        characterPtr->characterPosition.x -= characterPtr->speed;
    }

    if (IsKeyDown(KEY_D) && characterPtr->characterPosition.x < Viewport->Width - characterPtr->characterRectangle.width)
    {
        characterPtr->characterPosition.x += characterPtr->speed;
    }

    if (IsKeyPressed(KEY_SPACE) && isGrounded)
    {
        characterPtr->velocity += -characterPtr->jumpVelocity;
        isGrounded = false;
    }

    ApplyGravity(Viewport);
    UpdateTexture(characterPtr);
}


void CharacterController::ApplyGravity(View* Viewport)
{
    // If grounded, set character velocity to 0 and position to (Viewport height - character texture height)
    // Should help avoid character sticking in the ground after collision.
    if (isGrounded)
    {
        characterPtr->velocity = 0;
        characterPtr->characterPosition.y = Viewport->Height - characterPtr->characterRectangle.height;
    } 
    else
    {
        // Fall: Acceleration due to gravity. (Pixels/Frame)/Frame
        characterPtr->velocity += gravity * GetFrameTime();
    }

    characterPtr->characterPosition.y += characterPtr->velocity;
}

void CharacterController::UpdateTexture(Character* characterPtr)
{
    DrawTextureRec(characterPtr->texture, characterPtr->characterRectangle, characterPtr->characterPosition, WHITE);
}