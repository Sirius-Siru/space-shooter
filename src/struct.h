#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED

#include <SDL.h>
#include <SDL_image.h>
#include <vector>

typedef struct {
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    int winW = 1280, winH = 720;
    SDL_Rect cursorrect;
} App;
extern App app;

typedef struct{
    SDL_Texture *texture = NULL;
    SDL_Rect rect;
} GameUI;
extern GameUI window;
extern GameUI restart;

typedef struct{
    SDL_Texture *texture;
    SDL_Rect rect;
    int side;
    int health;
    int up, down, right, left, shoot;
    int shoot_delay;
    int speed;
} Entity;
extern Entity player;
extern Entity bullet[100];
extern Entity enemy[100];
extern bool pausegame;

#endif // STRUCT_H_INCLUDED
