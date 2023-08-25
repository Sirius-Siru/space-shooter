#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

#include <SDL.h>
#include <SDL_image.h>
#include "struct.h"
#include "draw.h"
#include <vector>
#include <cmath>

void Player_Setup();
void collscr();
void solveInput();
void dokeyUp();
void dokeyDown();
void doInput();
void getInput();

#endif // INPUT_H_INCLUDED