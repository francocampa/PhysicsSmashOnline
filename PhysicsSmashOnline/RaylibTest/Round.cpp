#include "Round.h"
#include "Enemy.h"
#include "Spawner.h"
#include "Globals.h"

Round::Round(uint16_t totalEnemies)
{
	this->totalEnemies = totalEnemies;
	this->spawner = new Spawner(5.0f,0.3f,5,totalEnemies);
	Globals::enemies = &enemies;
}

void Round::process(float deltaTime)
{
	for (Enemy* enemy : enemies)
	{
		//printf("process enemy: ");
		enemy->process(deltaTime);
	}

	int oldSize = enemies.size();
	if(spawnedEnemies < totalEnemies)
	{
		//printf("process spawner: ");
		spawner->process(deltaTime, enemies);
		//printf("process spawner end: ");
	}
	int newSize = enemies.size();

	if (newSize > oldSize)
		spawnedEnemies++;
}

void Round::killedEnemy(Enemy* enemy)
{
	int index = 0;
	for(Enemy* e:enemies) //TODO: Make a better way to get the index
		if (e == enemy)
			break;
		else
			index++;

	//Move to last place
	Enemy* aux = enemies.back();
	enemies[enemies.size() - 1] = enemies[index];
	enemies[index] = aux;

	//Remove last place
	enemies.pop_back();
}

