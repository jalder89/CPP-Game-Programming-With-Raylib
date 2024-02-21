#pragma once
#include <raylib.h>
#include "character.h"
#include "view.h"

class CharacterController
{
    Character* characterPtr;

    bool isGrounded;
    const int gravity = 10;             // Acceleration due to gravity. (Pixels/Frame)/FrameFrame

public:
    CharacterController(Character* character);

    bool GroundCheck(View* Viewport);
    void UpdateMovement(View* Viewport);
    void ApplyGravity(View* Viewport);
    void UpdateTexture(Character* characterPtr);
};