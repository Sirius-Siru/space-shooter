#include "enemy.h"

//Set up Entity enemy
void Enemy_Setup(){
    for (int i = 0; i<10; i++){
        memset(&enemy, 0, sizeof(enemy));
        enemy[i].side = -1;
        enemy[i].texture = IMG_LoadTexture(app.renderer, "texture/enemy.png");
        enemy[i].w = player.w;
        enemy[i].h = player.h;
        enemy[i].x = app.winW;
        enemy[i].speed = 4;
    }
}

//Spawn enemy
int spawn_delay = 0;
int next = 0;
std::vector<Entity*> enemy_wait;
void spawnEnemy(){
    if (!spawn_delay){
        Entity* nEnemy = &enemy[next];
        nEnemy->health = 1;
        nEnemy->y = rand() % (app.winH - nEnemy->h);
        enemy_wait.push_back(nEnemy);
        drawTexture(nEnemy->texture, nEnemy->x, nEnemy->y, nEnemy->w, nEnemy->h);
        spawn_delay = 128;
        next = (next + 1) % 10;
    }
    else spawn_delay--;
}

//Enemy move and shoot
void msEnemy(Entity *nEnemy){
    nEnemy->x -= nEnemy->speed;
    if (nEnemy->up)
        nEnemy->y -= nEnemy->speed;
    else if (nEnemy->down)
        nEnemy->y += nEnemy->speed;
    if (nEnemy->shoot) 
        fire_bullet(nEnemy);
}

//Enemy random move delay
int move_delay = 0;
//Enemy random shoot delay
int shoot_delay = 0;
//Enemy logic
void enemyLogic(Entity *nEnemy){
    if (!move_delay){
        nEnemy->up = nEnemy->down = 0;
        if (!rand() % 2)
            nEnemy->up = 1;
        else nEnemy->down = 1;
        nEnemy->delay = 128;
    }
    if (!shoot_delay){
        nEnemy->shoot = randact() % 2;
        shoot_delay = 18;
    }
    msEnemy(nEnemy);
}

//Draw enemy every frame and delete enemy when its health drop to 0
void doEnemy(){
    int i = 0;
    while (i < enemy_wait.size()){
        if (enemy[i]->x < -enemy[i]->w){
            enemy[i]->health = 0;
            enemy_wait.erase(enemy_wait.begin() + i);
            continue;
        }
        else {
            enemyLogic(enemy[i]);
            drawTexture(enemy[i].texture, enemy[i].x, enemy[i].y, enemy[i].w, enemy[i].h);
            i++;
        }
    }
}

void callEnemy(){
    spawn
}