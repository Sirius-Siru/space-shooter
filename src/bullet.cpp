#include "bullet.h"
#define Player_Side -1
#define Enemy_Side 1

std::vector<Entity*> bullet_shot;

//Player bullet texture
SDL_Texture *pbTexture = IMG_LoadTexture(app.renderer, "texture/laserBullet");
//Enemy bullet texture
SDL_Texture *ebTexture = IMG_LoadTexture(app.renderer, "texture/enemyBullet");

//Next bullet position
int nb = 0;
void fireBullet(int bullet_side){
    if (!bullet_side && !player.shoot_delay){

    }
}

//Moving bullet on screen
void doBullet(){
        for (int i = 0; i < bullet_shot.size(); i++){
            bullet_shot[i]->x += bullet[i].speed;
            if (bullet_shot[i]->x > app.winW){
                bullet_shot[i]->health = 0;
                bullet_shot.erase(bullet_shot.begin() + i);
            }
            else
                drawTexture(bullet_shot[i]->texture, bullet_shot[i]->x, bullet_shot[i]->y, bullet_shot[i]->w, bullet_shot[i]->h);
        }
    if (player.bullet_delay != 0)
        player.bullet_delay -= 1;
}