#include "Globals.h"

Player* Globals::player = nullptr;
Round* Globals::round = nullptr;
ISpatialStructure* Globals::spatialStructure = nullptr;
std::vector<Enemy*>* Globals::enemies = nullptr;
std::vector<Bullet*>* Globals::bullets = nullptr;
int Globals::SCREENWIDTH= 1024;
int Globals::SCREENHEIGHT = 760;