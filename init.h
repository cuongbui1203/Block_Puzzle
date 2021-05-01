#pragma once

#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>

#include "Img.h"
#include "common.h"

struct toado{
    int x,y;
    bool operator==(const toado &a) const {
        return (x == a.x && y == a.y);
    }
};

typedef enum luachon{
    NONE,
    PLAY,
    EXIT
} luachon;

void init();
void logSDLError(std::ostream&,const std::string&,bool);
void createWindow(SDL_Window* &window, SDL_Renderer* &renderer,toado &s);
void waitUntilKeyPressed();
void getResolution(toado&);

