#include "enemy.h"

extern std::vector<Entity*> pbullet;
std::vector<Entity*> enemy_wait;

//Set up Entity enemy
void Enemy_Setup(){ 
    memset(&enemy, 0, sizeof(enemy));
    enemy_wait.clear();
    for (int i = 0; i<100; i++){   
        enemy[i].side = -1;
        enemy[i].texture = IMG_LoadTexture(app.renderer, "texture/enemy.png");
        enemy[i].rect.w = player.rect.w;
        enemy[i].rect.h = player.rect.h;
        enemy[i].speed = 4;
    }
}

//Spawn enemy
int spawn_delay = 0;
int next = 0;
void spawnEnemy(){
    if (!spawn_delay){
        Entity* nEnemy = &enemy[next];
        nEnemy->health = 1;
        if (nEnemy->texture == NULL){
            exit(1);
        }
        nEnemy->rect.x = app.winW;
        nEnemy->rect.y = rand() % (app.winH - nEnemy->rect.h);
        enemy_wait.push_back(nEnemy);
        drawTexture(nEnemy->texture, nEnemy->rect);
        spawn_delay = 90;
        next = (next + 1) % 100;
    }
    else spawn_delay--;
}

//Enemy random move delay
int move_delay = 0;
//Enemy move and shoot
void msEnemy(Entity *nEnemy){
    nEnemy->rect.x -= nEnemy->speed;
    if (nEnemy->rect.y <= 0){
        nEnemy->up = 0;
        nEnemy->down = 1;
        move_delay = 64;
    }
    else if (nEnemy->rect.y >= app.winH - nEnemy->rect.h){
        nEnemy->up = 1;
        nEnemy->down = 0;
        move_delay = 64;
    }
    if (nEnemy->up)
        nEnemy->rect.y -= nEnemy->speed;
    else if (nEnemy->down)
        nEnemy->rect.y += nEnemy->speed;
    if (nEnemy->shoot){
        fireBullet(nEnemy);
        nEnemy->shoot = 0;
    }
}

//Enemy logic
void enemyLogic(Entity *nEnemy){
    if (!move_delay){
        nEnemy->up = nEnemy->down = 0;
        if (!rand() % 4){
            if (rand() % 2)
                nEnemy->up = 1;
            else nEnemy->down = 1;
        }
        else {
            if (player.rect.y < nEnemy->rect.y)
                nEnemy->up = 1;
            else nEnemy->down = 1;
        }
        move_delay = 64;
    } else move_delay--;
    if (!nEnemy->shoot_delay){
        nEnemy->shoot = rand() % 2;
        nEnemy->shoot_delay = 8;
    } else nEnemy->shoot_delay--;
    msEnemy(nEnemy);
}

//Draw enemy every frame and delete enemy when its health drop to 0
void doEnemy(){
    Uint8 i = 0;
    while (i < enemy_wait.size()){
        if (SDL_HasIntersection(&enemy_wait[i]->rect, &player.rect)){
            enemy_wait[i]->health = 0;
            pausegame = true;    
        }
        for (Uint8 j = 0; j < pbullet.size(); j++)
            if (SDL_HasIntersection(&enemy_wait[i]->rect, &pbullet[j]->rect)){
                enemy_wait[i]->health = 0;
                pbullet[j]->health = 0;
            }
        if (enemy_wait[i]->rect.x < -enemy_wait[i]->rect.w)
            enemy_wait[i]->health = 0;
        if (!enemy_wait[i]->health){
            enemy_wait.erase(enemy_wait.begin() + i);
            continue;
        }
            enemyLogic(enemy_wait[i]);
            drawTexture(enemy_wait[i]->texture, enemy_wait[i]->rect);
            i++;
        }
}

void callEnemy(){
    spawnEnemy();
    doEnemy();
}