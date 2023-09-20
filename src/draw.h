#ifndef DRAW_H_INCLUDED
#define DRAW_H_INCLUDED

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "struct.h"

SDL_Texture *loadTexture(const char *filename);
void prepareScreen();
void drawTexture(SDL_Texture *texture, SDL_Rect rect);

#endif // DRAW_H_INCLUDED