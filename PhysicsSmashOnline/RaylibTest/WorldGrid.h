#pragma once  
#include <vector>  
#include <unordered_map>  
#include "raylib.h"  
#include "ISpatialStructure.h"  

class Enemy;  
class Bullet;  

struct Chunk {  
   std::vector<Enemy*> enemies;  
   std::vector<Bullet*> bullets;  
};  

const int gridSize = 20;
class WorldGrid : public ISpatialStructure {
private:  
   std::unordered_map<void*, int> elementIndex;  

   const int chunkSize = 200;
   const float maxPos = gridSize * chunkSize;
   Chunk queryGrid[gridSize*gridSize];
   Chunk nextGrid[gridSize*gridSize];
   int getGridIndex(Vector2 pos);  
   bool inGrid(Vector2 pos);
public:  
   WorldGrid();  
   void fill(); 
   void frameEnd();
   std::vector<Enemy*>& getCloseEnemies(Vector2 pos);  
   std::vector<Bullet*>& getCloseBullets(Vector2 pos);  
   void addEnemy(Enemy* e);  
   void addBullet(Bullet* b);  
   void draw();  
};
