#include <iostream>
#include <string>
#include <raylib.h>
#include <raymath.h>
#include "view.h"
#include "circle.h"
#include "rectangle.h"

using std::string;

int main()
{
    // Initial window viewport setup. Check View for scaling
    View Viewport;                          
    InitWindow(Viewport.Width, Viewport.Height, "A New Window");
    SetTargetFPS(120);

    // Setup game shapes
    ShapeCircle circle(&Viewport);
    ShapeRectangle rectangle(&Viewport);

    // Setup game conditions
    bool is_collision_with_axe = false;
    string gameOver = "Game Over!";

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RED);

        // Game Logic
        // Collision check
        if ((rectangle.bottom_y >= circle.upper_y) && 
            (rectangle.upper_y <= circle.bottom_y) && 
            (rectangle.right_x >= circle.left_x) && 
            (rectangle.left_x <= circle.right_x))
        {
            is_collision_with_axe = true;
        }

        // Game Loop Condition
        if (is_collision_with_axe)
        {
            DrawText("Game Over!", Viewport.Center.X - (gameOver.length() * 12), (Viewport.Center.Y / 4), 48, BLACK);
        } else
        {
            // Update circle collider
            circle.left_x = circle.x - circle.radius;
            circle.right_x = circle.x + circle.radius;
            circle.upper_y = circle.y - circle.radius;
            circle.bottom_y = circle.y + circle.radius;

            // Update rectangle collider
            rectangle.left_x = rectangle.x;
            rectangle.right_x = rectangle.x + rectangle.width;
            rectangle.upper_y = rectangle.y;
            rectangle.bottom_y = rectangle.y + rectangle.height;

            DrawCircle(circle.x, circle.y, circle.radius, circle.color);
            DrawRectangle(rectangle.x, rectangle.y, rectangle.width, rectangle.height, rectangle.color);

            if (rectangle.y > Viewport.Height - rectangle.height || rectangle.y < 0)
            {
                rectangle.direction = -rectangle.direction;
            }
            rectangle.y += rectangle.speed * rectangle.direction;

            if (IsKeyDown(KEY_D) && circle.x < Viewport.Width)
            {
                circle.x += (circle.speed);
            }
            if (IsKeyDown(KEY_A) && circle.x > 0)
            {
                circle.x -= (circle.speed);
            }
        }

        // Game Logic End - Cleanup
        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}