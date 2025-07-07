#include <iostream>
#include <cmath>

#include "raylib.h"
#include "Game.h"
#include "Enemy.h"

int main() {
	SetTraceLogLevel(LOG_ALL);
	InitWindow(1024,760,"RaylibTest");

	Enemy::spriteSheet = LoadTexture("sprites/Crab.png");

	SetTargetFPS(60);

	Game game = Game();
	while (!WindowShouldClose()) {
		BeginDrawing();

		ClearBackground(YELLOW);
		
		game.process(GetFrameTime());
		
		EndDrawing();
	}

	CloseWindow();

	return 0;
}