#include <raylib.h>
#include <raymath.h>
#include "view.h"
#include "shapes.h"
#include  "shape_controller.h"

int main()
{
    // Initial window viewport setup. Check View for scaling
    View Viewport;                          
    InitWindow(Viewport.Width, Viewport.Height, "Dapper Dasher!");
    SetTargetFPS(120);

    Shape rectangle(&Viewport, 24, 48);
    ShapeController rectangleController(&rectangle);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        rectangleController.UpdateMovement(&Viewport);
        DrawRectangle(rectangle.positionX, rectangle.positionY, rectangle.width, rectangle.height, BLACK);
        
        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}