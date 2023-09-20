#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <SDL.h>
#include <SDL_image.h>
#include "struct.h"
#include "init.h"
#include "draw.h"
#include "enemy.h"
#include "bullet.h"
#include "input.h"

void GameUIGen();
void render();
void game();
void pause();

#endif //GAME_H_INCLUDED