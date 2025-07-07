#pragma once
#include <vector>
#include "raylib.h"

class Enemy;
class Bullet;

class ISpatialStructure
{
public:
	virtual void fill() {};
	virtual void frameEnd() {};
	virtual std::vector<Enemy*>& getCloseEnemies(Vector2 pos) { 
		std::vector<Enemy*> e;
		return e; 
	};
	virtual std::vector<Bullet*>& getCloseBullets(Vector2 pos) { 
		std::vector<Bullet*> e;
		return e;
	};
	virtual void addEnemy(Enemy* e) {};
	virtual void addBullet(Bullet* b) {};
	virtual void draw() {};
};

