#include "gameui.h"

void GameUIGen(){
    ui->losewindow = IMG_LoadTexture(app.renderer, "texture/Window.png");
    ui->uirect.w = 800;
    ui->uirect.h = 400;
    ui->uirect.x = app.winW / 2 - 400;
    ui->uirect.y = app.winH / 2 - 200;
    if (ui->losewindow = NULL) exit(1);
}

void 