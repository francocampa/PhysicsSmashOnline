#pragma once
#include <vector>
#include <memory>

class Enemy;

class Spawner
{
private:
	std::vector<std::unique_ptr<Enemy>> pool;
	std::vector<Enemy*> pointersPool;
	float timeBetweenRounds;

	bool spawning;
	float timeBetweenSpawns;
	uint16_t enemiesToSpawn;
	uint16_t enemiesSpawned;

	float timer = 0;

	void extendPool();
public:
	Spawner(float timeBetweenRounds, float timeBetweenSpawns, uint16_t enemiesToSpawn, uint32_t poolSize);
	void process(float deltaTime, std::vector<Enemy*>& enemies);
};

