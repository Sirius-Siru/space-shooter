#include "game.h"

App app;
Entity player;
Entity bullet[100];
Entity enemy[100];
bool pausegame = false;
SDL_Texture* lastRenderer;
GameUI window;
GameUI restart;

void GameUIGen(){
    window.texture = IMG_LoadTexture(app.renderer, "texture/Window.png");
    restart.texture = IMG_LoadTexture(app.renderer, "texture/Replay_BTN.png");
    if (restart.texture == NULL)
        exit(1);
    window.rect.w = 400;
    window.rect.h = 500;
    window.rect.x = app.winW / 2 - 200;
    window.rect.y = app.winH / 2 - 250;
    restart.rect.x = window.rect.x + window.rect.w / 2  - 50;
    restart.rect.y = window.rect.y + window.rect.h - 150;
    restart.rect.w = 100;
    restart.rect.h = 100;
}

void render(){
    SDL_SetRenderTarget(app.renderer, lastRenderer);
    prepareScreen();
    getInput();
    callEnemy();
    doBullet();
    SDL_SetRenderTarget(app.renderer, NULL);
    SDL_RenderCopy(app.renderer, lastRenderer, NULL, NULL);
    SDL_RenderPresent(app.renderer);
    SDL_SetRenderTarget(app.renderer, lastRenderer);
}

void game(){
    app.cursorrect.w = 1;
    app.cursorrect.h = 1;
    player_setup();
    bullet_setup();
    Enemy_Setup();
    GameUIGen();
    lastRenderer = NULL;
    lastRenderer = SDL_CreateTexture(app.renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_TARGET, app.winW, app.winH);
    srand(time(NULL));  
    while (1){
        Uint32 start = SDL_GetTicks();
        if (pausegame) pause();
        else render();
        Uint32 end = SDL_GetTicks();
        if (end - start < 16)
            SDL_Delay(16 - (end - start));
    }
}

void pause(){
    SDL_SetRenderTarget(app.renderer, NULL);
    prepareScreen();    
    SDL_RenderCopy(app.renderer, lastRenderer, NULL, NULL);
    SDL_RenderCopy(app.renderer, window.texture, NULL, &window.rect);
    SDL_GetMouseState(&app.cursorrect.x, &app.cursorrect.y);
    if (SDL_HasIntersection(&app.cursorrect, &restart.rect)){
        SDL_Rect rect;
        rect.x = window.rect.x + window.rect.w / 2  - 55;
        rect.y = window.rect.y + window.rect.h - 155;
        rect.w = restart.rect.w + 10;
        rect.h = restart.rect.h + 10;
        SDL_RenderCopy(app.renderer, restart.texture, NULL, &rect);
        doButton();
    }
    else SDL_RenderCopy(app.renderer, restart.texture, NULL, &restart.rect);
    doInput();
    SDL_RenderPresent(app.renderer);
    if (!pausegame)
        game();
}