#pragma once
#include <raylib.h>

class Bullet
{
private:
	Vector2 position;
	Vector2 dir;
public:
	void process(float deltaTime);
	Vector2 getPosition() { return position; };
	~Bullet() {};
};