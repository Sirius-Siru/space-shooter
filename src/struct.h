#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED

#include <vector>

typedef struct {
    SDL_Window *window;
    SDL_Renderer *renderer;
    int winW, winH;
} App;
extern App app;

typedef struct{
    int topY, bottomY;
    int leftX, RightX;
} Collider;

typedef struct{
    SDL_Texture *texture;
    int side;
    float x, y;
    int w, h;
    int health = 0;
    int up, down, right, left, shoot;
    int speed;
} Entity;
extern Entity player;
extern Entity bullet[30];
extern Entity enemy[10];

#endif // STRUCT_H_INCLUDED
