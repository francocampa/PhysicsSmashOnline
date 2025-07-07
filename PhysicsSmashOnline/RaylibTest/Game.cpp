#include "Game.h"

#include "Globals.h"
#include "Player.h"
#include "Round.h"
#include "WorldGrid.h"
#include <string>

Game::Game()
{
	this->player = new Player();
	Globals::player = this->player;
	Globals::spatialStructure = new WorldGrid();
	this->roundNumber = 0;
	this->startRound();
}

void Game::process(float deltaTime)
{
	//printf("frame start: ");
	BeginMode2D(player->getCamera());
	//printf("process player: ");
	player->process(deltaTime);
	//printf("process round: ");
	round->process(deltaTime);
	//printf("process spatial draw: ");
	Globals::spatialStructure->draw();

	EndMode2D();
	//printf("process spatial frame end: ");
	Globals::spatialStructure->frameEnd();

	DrawFPS(10,10);
	//printf("process hud 1: ");
	std::string enemiesProgress = std::to_string(round->getSpawnedEnemies());
	enemiesProgress.append("/").append(std::to_string(round->getTotalEnemies()));
	DrawText(enemiesProgress.c_str(), 10, 30, 20, BLACK);
	//printf("process hud 2: ");
	std::string round = "Round ";
	round.append(std::to_string(roundNumber));
	DrawText(round.c_str(), 10, 50, 20, BLACK);
	//printf("frame end\n ");
}

void Game::startRound()
{
	//this->roundNumber++;
	this->round = new Round((std::pow(2,this->roundNumber)) * 20); //TODO: adjust enemy number
}

void Game::beatRound()
{
	Round* round = this->round;
	delete round;

	startRound();
}
