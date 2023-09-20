#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

#include <vector>
#include <cmath>
#include <cstring>
#include "struct.h"
#include "draw.h"
#include "bullet.h"

void player_setup();
void collscr();
void solveInput();
void dokeyUp(SDL_KeyboardEvent *event);
void dokeyDown(SDL_KeyboardEvent *event);
void dobuttonDown(SDL_MouseButtonEvent *event);
void doButton();
void doInput();
void getInput();

#endif // INPUT_H_INCLUDED