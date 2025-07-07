#include "WorldGrid.h"

#include "Globals.h"
#include "Enemy.h"
#include "Bullet.h"
#include "string"

int WorldGrid::getGridIndex(Vector2 pos)
{
    int iposy = (int)pos.y;
    int iposx = (int)pos.x;
    return gridSize*(iposy / chunkSize) + iposx/chunkSize;
}

bool WorldGrid::inGrid(Vector2 pos)
{
    return pos.x > 0 && pos.x < maxPos && pos.y > 0 && pos.y < maxPos;
}

WorldGrid::WorldGrid()
{
    for (int i = 0;i < gridSize * gridSize;i++) {
        queryGrid[i] = Chunk();
        nextGrid[i] = Chunk();
    }
}

void WorldGrid::fill()
{
    for (Enemy* e : *Globals::enemies) 
        queryGrid[getGridIndex(e->getPosition())].enemies.push_back(e);
    for (Bullet* b : *Globals::bullets)
        queryGrid[getGridIndex(b->getPosition())].bullets.push_back(b);
}

void WorldGrid::frameEnd()
{
    std::swap(queryGrid, nextGrid);
    for (int i = 0;i < gridSize * gridSize;i++) 
        nextGrid[i] = Chunk();
}

std::vector<Enemy*>& WorldGrid::getCloseEnemies(Vector2 pos)
{
    return queryGrid[getGridIndex(pos)].enemies;
}

std::vector<Bullet*>& WorldGrid::getCloseBullets(Vector2 pos)
{
    return queryGrid[getGridIndex(pos)].bullets;
}

void WorldGrid::addEnemy(Enemy* e)
{
    if (!inGrid(e->getPosition()))
        return;

    int centerIndex = getGridIndex(e->getPosition()); //I'll add it where it is and arround to avoid wrong collitions in borders

    for (int y = -1; y < 2; y++) 
        for (int x = -1; x < 2; x++) {
            int index = centerIndex + y * gridSize + x;
            if(index > 0 && index < gridSize*gridSize)
                nextGrid[index].enemies.push_back(e);
        }

    

}

void WorldGrid::addBullet(Bullet* b)
{
    if (!inGrid(b->getPosition()))
        return;

    nextGrid[getGridIndex(b->getPosition())].bullets.push_back(b);
}

void WorldGrid::draw()
{
    for(int y = 0; y < gridSize;y++)
        for (int x = 0; x < gridSize;x++) {
            int enemies = queryGrid[y * gridSize + x].enemies.size();
            DrawRectangleLines(x*chunkSize,y*chunkSize,chunkSize,chunkSize,BLUE);
            if (enemies > 0)
                DrawText(std::to_string(enemies).c_str(), x * chunkSize + 10, y * chunkSize + 10, 20, BLUE);
        }
}
