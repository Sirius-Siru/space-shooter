#ifndef GAMEUI_H_INCLUDE
#define GAMEUI_H_INCLUDE

#include "struct.h"

typedef struct{
    SDL_Texture *losewindow;
    SDL_Rect uirect;
} GameUI;
extern GameUI* ui;
#endif GAMEUI_H_INCLUDE