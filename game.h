#pragma once
#include "init.h"
#include "sound.h"


typedef struct Game{
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Texture* texture;
    toado screen;
    vocaloid miku;

    void create();

    void chaneRenderTargetToScreen(void)  {SDL_SetRenderTarget(renderer,nullptr);}
    void chaneRenderTargetToTexture(void) {SDL_SetRenderTarget(renderer,texture);}

    void free();

}Game;
