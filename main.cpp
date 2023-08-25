#include <SDL.h>
#include <SDL_image.h>
#include "struct.h"
#include "init.h"
#include "draw.h"
#include "enemy.h"
#include "input.h"

using namespace std;
App app;
Entity player;
Enemy enemy[30];
Entity bullet[16];

int main(int argc, char* argv[]) {
    getInit();
    player.texture = loadTexture("texture/player.png");
    IETexture();
    IBTexture();
    player.w = app.winW * 5/100;
    player.h = app.winH * 10/100;
    player.speed = 13;
    srand(time(NULL));  
    while (1){
        prepareScreen();
        getInput();
        spawnEnemy();
        doEnemy();
        SDL_RenderPresent(app.renderer);
        SDL_Delay(16);
    }
    cout<<0;
    exit(0);
}
