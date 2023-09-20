#include "init.h"
using namespace std;
void getInit(){
    if (SDL_Init(SDL_INIT_VIDEO) < 0){
        exit(1);
    }
    app.window = SDL_CreateWindow("SDL2_Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1270, 720, SDL_WINDOW_SHOWN);
    if (!app.window){
        exit(1);
    }

    app.renderer = SDL_CreateRenderer(app.window, -1, SDL_RENDERER_ACCELERATED);
    if (!app.renderer){
        exit(1);
    }
    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
}

