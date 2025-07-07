#include "Enemy.h"
#include "Player.h"
#include "ISpatialStructure.h"
#include "Globals.h"
#include "utils.h"
#include <raymath.h>

Texture2D Enemy::spriteSheet = {};

Enemy::Enemy(Spawner* spawner, Vector2 position)
{
	this->spawner = spawner;
	this->position = position;
	this->frameRec = { 0.0f,0.0f, spriteSheet.width / 4.0f,(float)spriteSheet.height };
}

void Enemy::process(float deltaTime)
{
	Vector2 playerPos = Globals::player->getPosition();
	Vector2 toPlayer = { playerPos.x - position.x, playerPos.y - position.y };
	float distance = Vector2Length(toPlayer);

	if (distance < 200.0f) {
		Vector2 dir = Vector2Normalize(toPlayer);
		position += dir * stats.speed * deltaTime;
	}

	for (Enemy* e : Globals::spatialStructure->getCloseEnemies(position)) { //TODO: make so that it returns a radius
		//for (Enemy* e:*Globals::enemies) {
		Vector2 ePos = e->getPosition();
		Vector2 toE = {position.x - ePos.x, position.y - ePos.y};
		float distance = Vector2Length(toE);
		if (distance < radius*2) {
			Vector2 dir = Vector2Normalize(toE);
			position += dir * (radius*2 - distance);
		}
	}

	Globals::spatialStructure->addEnemy(this);
	draw(deltaTime);
}

void Enemy::draw(float deltaTime)
{
	frameTimer += deltaTime;
	if (frameTimer > 1.0f / frameRate)
	{
		spriteFrame = (spriteFrame + 1) % 4;
		frameRec.x = (spriteSheet.width / 4.0f) * spriteFrame;
		frameTimer = 0.0f;
	}
	DrawTextureRec(spriteSheet, frameRec, { position.x - 12, position.y - 12 }, BLUE);
	//DrawCircle(position.x,position.y, radius,PURPLE);
}

void Enemy::setPosition(Vector2 position)
{
	this->position = position;
}
