#pragma once
#include "raylib.h"

enum PLAYERSTATE {
	IDLE,
	MOVING,
	HIT
};

struct AttackStats {
	float rate = 1.0f;
	float range ;
	int noOfShots;
	int noOfBounce;
};
struct PlayerStats {
	int maxHp;
	int hp;
	float speed;
};

class Player
{
private:
	Vector2 position;
	Camera2D camera;

	Rectangle hitbox;

	PLAYERSTATE state = IDLE;
	Rectangle frameRec;
	float frameTimer = 0;
	const int frameRate = 6;
	int spriteFrame = 0;
	
	PlayerStats playerStats;
	AttackStats attackStats;

	void handleMovement(float deltaTime);
	void handleAttack(float deltaTime);
	void draw(float deltaTime);
public:
	Player();
	Texture2D spriteSheet;
	void process(float deltaTime);
	Camera2D& getCamera();
	Vector2& getPosition();
};

