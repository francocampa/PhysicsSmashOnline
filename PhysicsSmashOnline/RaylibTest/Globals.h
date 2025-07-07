#pragma once
#include <vector>;

class Player;
class Enemy;
class Round;
class Bullet;
class ISpatialStructure;

class Globals
{
public:
	static Player* player;
	static std::vector<Enemy*>*enemies;
	static Round* round;
	static std::vector<Bullet*>*bullets;
	static ISpatialStructure* spatialStructure;

	static int SCREENWIDTH;
	static int SCREENHEIGHT;
};

