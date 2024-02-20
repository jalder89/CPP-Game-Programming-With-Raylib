#include <raylib.h>
#include <raymath.h>
#include "view.h"
#include "shapes.h"

int main()
{
    // Initial window viewport setup. Check View for scaling
    View Viewport;                          
    InitWindow(Viewport.Width, Viewport.Height, "Dapper Dasher!");
    SetTargetFPS(120);

    Shape rectangle(&Viewport, 100, 300);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawRectangle(rectangle.positionX, rectangle.positionY, rectangle.width, rectangle.height, BLACK);
        DrawLine(rectangle.positionX, rectangle.positionY, 0, 0, RED);
        DrawLine(rectangle.positionX + rectangle.width, rectangle.positionY, Viewport.Width, 0, RED);
        DrawLine(rectangle.positionX + rectangle.width, rectangle.positionY + rectangle.height, Viewport.Width, Viewport.Height, RED);
        DrawLine(rectangle.positionX, rectangle.positionY + rectangle.height, 0, Viewport.Height, RED);

        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}