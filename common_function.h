#pragma once
#include "init.h"

void setColorRenderer(SDL_Renderer*&,const SDL_Color&);
void delay(Uint32&);
void showScreen(SDL_Window*&,SDL_Renderer*&);

int random(int,int);

int posInArr(const int&,const int&,const int&);

int getRandomColor(void);
