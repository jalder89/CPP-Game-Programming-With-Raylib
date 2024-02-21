#pragma once
#include <raylib.h>
#include <raymath.h>
#include "character.h"
#include "view.h"
#include <iostream>

class CharacterController
{
    Character* characterPtr;

    bool isGrounded;
    const int gravity = 500;             // Acceleration due to gravity. (Pixels/Frame)/FrameFrame
public:
    CharacterController(Character* character);

    bool GroundCheck(View* Viewport);
    void UpdateMovement(View* Viewport);
    void ApplyGravity(View* Viewport);
    void UpdateTexture(Character* characterPtr);
};