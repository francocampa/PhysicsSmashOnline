#include "Player.h"
#include "Globals.h"
#include <raymath.h>

void Player::handleMovement(float deltaTime)
{
    Vector2 dir = { 0.0f,0.0f };
    
    if (IsKeyDown(KEY_A))
        dir.x += -1.0f;
    if (IsKeyDown(KEY_D))
        dir.x += 1.0f;
    if (IsKeyDown(KEY_S))
        dir.y += 1.0f;
    if (IsKeyDown(KEY_W))
        dir.y += -1.0f;

    bool moving = dir.x != 0 || dir.y != 0;

    if (moving) {
        state = MOVING;
        dir = Vector2Normalize(dir);
        position += dir * playerStats.speed * deltaTime;
        hitbox.x = position.x + 7;
        hitbox.y = position.y + 10;
        camera.target = position;
    }
    else
        state = IDLE;
}

void Player::handleAttack(float deltaTime)
{
}

void Player::draw(float deltaTime)
{
    switch (state) {
    case IDLE:
        frameRec.x = 0;
        break;
    case MOVING:
        frameTimer += deltaTime;
        if (frameTimer > 1.0f / frameRate)
        {
            spriteFrame = (spriteFrame + 1) % 4;
            frameRec.x = (spriteSheet.width / 4.0f) * spriteFrame;
            frameTimer = 0.0f;
        }
        break;
    case HIT:
        //TODO: do this
        break;
    }
    
    DrawTextureRec(spriteSheet, frameRec, position, WHITE);
    //DrawRectangle(hitbox.x,hitbox.y,hitbox.width,hitbox.height,RED);
}

Player::Player()
{
    position = { 1000,1000 };
    playerStats = {2,2,100.0f};
    attackStats = {1.0f,100.0f,1,0};

    hitbox = { position.x + 7,position.y + 10, 10,10 };
    spriteSheet = LoadTexture("sprites/Crab.png");
    frameRec = { 0.0f,0.0f, spriteSheet.width / 4.0f,(float)spriteSheet.height };

    camera = Camera2D();
    camera.target = position;
    camera.offset = { Globals::SCREENWIDTH / 2.0f, Globals::SCREENHEIGHT / 2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 1.5f;
}

void Player::process(float deltaTime)
{
    handleMovement(deltaTime);
    handleAttack(deltaTime);
    draw(deltaTime);
}

Camera2D& Player::getCamera()
{
    return camera;
}

Vector2& Player::getPosition()
{
    return position;
}
