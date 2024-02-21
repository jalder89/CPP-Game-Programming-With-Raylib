#include "character.h"

Character::Character()
{
    texture = LoadTexture("assets/textures/scarfy.png");
    
    velocity.x = 0;
    velocity.y = 0;
    velocityY = 0;
    moveVelocity = 500;
    jumpVelocity = 500;

    width = 128;
    height = 128;

    characterRectangle.width = texture.width / 6;
    characterRectangle.height = texture.height;
    characterRectangle.x = 0;
    characterRectangle.y = 0;

    characterPosition.x = 160;
    characterPosition.y = 90;
}

Character::~Character()
{
    UnloadTexture(texture);
}

Character::Character(View* Viewport)
{
    texture = LoadTexture("assets/textures/scarfy.png");
    
    velocity.x = 0;
    velocity.y = 0;
    velocityY = 0;
    moveVelocity = 500;
    jumpVelocity = 500;

    width = 128;
    height = 128;

    characterRectangle.width = texture.width / 6;
    characterRectangle.height = texture.height;
    characterRectangle.x = 0;
    characterRectangle.y = 0;

    characterPosition.x = Viewport->Center.X - (characterRectangle.width / 2);
    characterPosition.y = Viewport->Center.Y - (characterRectangle.height / 2);
}