#pragma once

class Player;
class Round;

class Game
{
private:
	Player* player;

	int roundNumber = 0;
	Round* round;
public:
	Game();
	void process(float deltaTime);

	void startRound();
	void beatRound();
};

