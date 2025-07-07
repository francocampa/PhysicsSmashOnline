#include "Spawner.h"
#include "Globals.h"
#include "ISpatialStructure.h"
#include "Enemy.h"
#include "Player.h"
#include "utils.h"

Spawner::Spawner(float timeBetweenRounds, float timeBetweenSpawns, uint16_t enemiesToSpawn, uint32_t poolSize)
{
	this->timeBetweenSpawns = timeBetweenSpawns;
	this->timeBetweenRounds = timeBetweenRounds;
	this->enemiesToSpawn = enemiesToSpawn;
	this->enemiesSpawned = 0;
	this->spawning = false;

	for (int i = 0;i < poolSize;i++) 
		extendPool();
}

void Spawner::extendPool()
{
	pool.push_back(std::make_unique<Enemy>(this, Vector2{ 0, 0 }));
	pointersPool.push_back(pool.back().get());
}

Vector2 getRandomSpawnPosition() {
	float angle = getRandomFloat(0,2*PI);
	float distance = getRandomFloat(100,200);
	Vector2 playerPos = Globals::player->getPosition();
	return { playerPos.x + cosf(angle) * distance, playerPos.y + sinf(angle) * distance };
}

void Spawner::process(float deltaTime, std::vector<Enemy*>& enemies)
{
	timer += deltaTime;
	if (spawning) {
		if (timer < timeBetweenSpawns)
			return;

		if (pointersPool.size() == 0)
			extendPool();

		Enemy* e = pointersPool.back();
		pointersPool.pop_back(); 

		Vector2 pos = getRandomSpawnPosition();
		e->setPosition(pos);
		enemies.push_back(e);

		enemiesSpawned++;
		timer = 0;
		if (enemiesSpawned == enemiesToSpawn)
		{
			spawning = false;
			enemiesSpawned = 0;
		}
	}
	else if (timer >= timeBetweenRounds)
		spawning = true;
	
}
