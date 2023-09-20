#include "bullet.h"

std::vector<Entity*> pbullet;
std::vector<Entity*> ebullet;
//Player bullet texture
SDL_Texture* pbT = NULL;
//Enemy bullet texture
SDL_Texture* ebT = NULL;
void bullet_setup(){
    memset(&bullet, 0, sizeof(bullet));
    pbullet.clear();
    ebullet.clear();
    pbT = IMG_LoadTexture(app.renderer, "texture/laserBullet.png");
    ebT = IMG_LoadTexture(app.renderer, "texture/enemyBullet.png");
    if (pbT == NULL){
        std::cout<<"Not Detect";
        exit(0);
    }
    for (int i=0 ; i < 100; i++){
        bullet[i].rect.w = app.winW * 4/100;
        bullet[i].rect.h = app.winH * 4/100;
        bullet[i].speed = 25;
    }
}

//Next bullet position
int nb = 0;
void fireBullet(Entity* e){
    Entity* b = &bullet[nb];
    if (!b->health){
        if (e->side == 1){
            b->texture = pbT;
            pbullet.push_back(b);
        } else{
            b->texture = ebT;
            ebullet.push_back(b);
        }
        b->health = 1;
        b->side = e->side;
        b->rect.x = e->rect.x;
        b->rect.y = e->rect.y + e->rect.h / 2 - 12;
        drawTexture(pbT, b->rect); 
    }
    nb = (nb + 1) % 100;
}

//Moving bullet on screen
void doBullet(){
    Uint8 i = 0;
    while (i < ebullet.size()){
        if (ebullet[i]->rect.x < 0)
            ebullet[i]->health = 0;
        if  (SDL_HasIntersection(&ebullet[i]->rect, &player.rect)){
            ebullet[i]->health = 0;
            pausegame = true;
        }
        if (!ebullet[i]->health){
            ebullet.erase(ebullet.begin() + i);
            continue;
        }
        ebullet[i]->rect.x -= ebullet[i]->speed;
        drawTexture(ebullet[i]->texture, ebullet[i]->rect);
        i++;
    }
    i = 0;
    while (i < pbullet.size()){
        if (pbullet[i]->rect.x > app.winW)
            pbullet[i]->health = 0;
        if (pbullet[i]->health)
            for (Uint8 j = 0; j < ebullet.size(); j++)
                if (SDL_HasIntersection(&pbullet[i]->rect, &ebullet[j]->rect)){
                    pbullet[i]->health = 0;
                    ebullet[j]->health = 0;
                }
        if (!pbullet[i]->health){
            pbullet.erase(pbullet.begin() + i);
            continue;
        }
        pbullet[i]->rect.x += pbullet[i]->speed;
        drawTexture(pbullet[i]->texture, pbullet[i]->rect);
        i++;
    }
}
