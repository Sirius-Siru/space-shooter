#include "draw.h"
using namespace std;
SDL_Texture *loadTexture(const char *filename){
    SDL_Texture *texture = IMG_LoadTexture(app.renderer, filename);
    if (texture == NULL){
        exit(1);
    }
    return texture;
}

void prepareScreen(){
        SDL_RenderClear(app.renderer);
        SDL_SetRenderDrawColor(app.renderer, 50, 50, 50, 255);
        SDL_RenderClear(app.renderer);
}

void drawTexture(SDL_Texture* texture, SDL_Rect rect){
    SDL_RenderCopy(app.renderer, texture, NULL, &rect);
}
