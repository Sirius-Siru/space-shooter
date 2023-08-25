#ifndef ENEMY_H_INCLUDE
#define ENEMY_H_INCLUDE

#include <SDL.h>
#include <SDL_image.h>
#include "struct.h"
#include "draw.h"
#include <cstdlib>
#include <time.h>

void Enemy_Setup();
void spawnEnemy();
void msEnemy(Entity* nEnemy);
void enemyLogic(Entity* nEnemy);
void doEnemy();
void callEnemy();

#endif //ENEMY_H_INCLUDE