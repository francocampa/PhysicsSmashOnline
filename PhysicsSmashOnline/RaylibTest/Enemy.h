#pragma once
#include "raylib.h"

class Spawner;

enum ENEMYSTATE {
	ROAMING,
	CHASING
};

struct EnemyStats {
	float range = 200.0f;
	float speed = 70.0f;
};

class Enemy
{
private:
	Spawner* spawner;

	Vector2 position;
	float radius = 10;

	Rectangle frameRec;
	float frameTimer = 0;
	const int frameRate = 6;
	int spriteFrame = 0;

	EnemyStats stats;

	void die();
public:
	static Texture2D spriteSheet;
	Enemy(Spawner* spawner,Vector2 position);
	void process(float deltaTime);
	void draw(float deltaTime);
	void setPosition(Vector2 position);
	Vector2 getPosition() { return position; };
};

