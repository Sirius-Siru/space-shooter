#ifndef ENEMY_H_INCLUDE
#define ENEMY_H_INCLUDE

#include <cstdlib>
#include <time.h>
#include "bullet.h"

void Enemy_Setup();
void spawnEnemy();
void msEnemy(Entity* nEnemy);
void enemyLogic(Entity* nEnemy);
void doEnemy();
void callEnemy();

#endif //ENEMY_H_INCLUDE