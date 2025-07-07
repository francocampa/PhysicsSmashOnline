#pragma once
#include "vector";

class Spawner;
class Enemy;

class Round {
private:
	std::vector<Enemy*> enemies;
	Spawner* spawner;

	uint16_t totalEnemies;
	uint16_t spawnedEnemies = 0;
	uint16_t killedEnemies = 0;
public:
	Round(uint16_t totalEnemies);
	void process(float deltaTime);
	void killedEnemy(Enemy* enemy);

	uint16_t getTotalEnemies() { return totalEnemies; }
	uint16_t getSpawnedEnemies() { return spawnedEnemies; }
	uint16_t getKilledEnemies() { return killedEnemies; }
};