#ifndef BULLET_H_INCLUDE
#define BULLET_H_INCLUDE 

typedef struct{
    SDL_Texture *texture;
    int side;
    float x, y;
    int w, h;
    float speed = 30;
} Bullet;
extern Bullet bullet[30];

#endif //BULLET_H_INCLUDE