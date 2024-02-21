#include <raylib.h>
#include <raymath.h>
#include "view.h"
#include "character.h"
#include  "character_controller.h"

int main()
{
    // Initial window viewport setup. Check View for scaling
    View Viewport;                          
    InitWindow(Viewport.Width, Viewport.Height, "Dapper Dasher!");
    SetTargetFPS(120);

    Character character(&Viewport, 24, 48);
    CharacterController characterController(&character);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        characterController.UpdateMovement(&Viewport);
        DrawRectangle(character.positionX, character.positionY, character.width, character.height, BLACK);
        
        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}