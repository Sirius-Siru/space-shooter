#include "input.h"

//Set up Entity player struct
void Player_Setup(){
    memset(&player, 0, sizeof(player));
    player.side = 1;
    player.texture = IMG_LoadTexture(app.renderer, "texture/player.png");
    player.x = 100;
    player.y = app.winH / 2;
    player.w = app.winW * 5/100;
    player.h = app.winH * 10/100;
    player.speed = 13;
}

//Collision halding when player move out the screen
void collscr(){
    if (player.x < 0)
        player.x = 0;
    else if (player.x > (app.winW - player.w))
        player.x = app.winW - player.w;
    if (player.y < 0)
        player.y = 0;
    else if (player.y > (app.winH - player.h))
        player.y = app.winH -player.h;
}

//Moving velocity
typedef struct{
    float x, y; 
} Velocity;
Velocity velocity;

//Moving and shooting bullet
void solveInput(){
    if (player.up)
        velocity.y = -1;
    if (player.down)
        velocity.y = 1;
    if (player.left)
        velocity.x = -1;
    if (player.right)
        velocity.x = 1;
    if (player.shoot)
        fireBullet();
    float length = sqrt(velocity.x * velocity.x + velocity.y * velocity.y);
    if (!length)
        return;
    float normalizeX = velocity.x / length;
    float normalizeY = velocity.y / length; 
    player.x += player.speed * normalizeX;
    player.y += player.speed * normalizeY;
    memset(&velocity, 0, sizeof(Velocity));
}

//Solve keyboard event key up
void dokeyUp(SDL_KeyboardEvent *event){
    if (event->keysym.scancode == SDL_SCANCODE_UP)
        player.up = 0;
    if (event->keysym.scancode == SDL_SCANCODE_DOWN)
        player.down = 0;
    if (event->keysym.scancode == SDL_SCANCODE_RIGHT)
        player.right = 0;
    if (event->keysym.scancode == SDL_SCANCODE_LEFT)
        player.left = 0;
    if (event->keysym.scancode == SDL_SCANCODE_SPACE)
        player.shoot = 0;
}
//Solve keyboard events key down
void dokeyDown(SDL_KeyboardEvent *event){
    if (event->repeat == 0){
        if (event->keysym.scancode == SDL_SCANCODE_UP)
            player.up = 1;
        if (event->keysym.scancode == SDL_SCANCODE_DOWN)
            player.down = 1;
        if (event->keysym.scancode == SDL_SCANCODE_RIGHT)
            player.right = 1;
        if (event->keysym.scancode == SDL_SCANCODE_LEFT)
            player.left = 1;
        if (event->keysym.scancode == SDL_SCANCODE_SPACE)
            player.shoot = 1;
    }
}


//Get input events
void doInput(){
    SDL_Event event;
    while (SDL_PollEvent(&event))
        switch (event.type){
            case SDL_QUIT:
                exit(0);
                break;
            case SDL_KEYDOWN:
                dokeyDown(&event.key);
                break;
            case SDL_KEYUP:
                dokeyUp(&event.key);
            default:
                break;
        }
}

//Do every frame
void getInput(){
    doInput();
    solveInput();
    doBullet();
    collscr();
    drawTexture(player.texture, player.x, player.y, player.w, player.h);
}
