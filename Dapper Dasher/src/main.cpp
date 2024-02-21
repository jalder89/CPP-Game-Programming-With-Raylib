#include <iostream>
#include <raylib.h>
#include <raymath.h>
#include "view.h"
#include "character.h"
#include "character_controller.h"

int main()
{
    // Initial window viewport setup. Check View for scaling
    View Viewport;                          
    InitWindow(Viewport.Width, Viewport.Height, "Dapper Dasher!");

    Character character(&Viewport);
    CharacterController characterController(&character);

    while (!WindowShouldClose()) {
        Viewport.deltaTime = GetFrameTime();
        BeginDrawing();
        ClearBackground(RAYWHITE);

        characterController.UpdateMovement(&Viewport);
        
        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}