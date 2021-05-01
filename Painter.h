#ifndef PAINTER_H
#define PAINTER_H
#include "init.h"

class Painter
{
    toado td;
    float angle;
    int width;
    int height;
    SDL_Color color;
public:
    void setPosition(toado val) { td = val; }
    void setPosition(int x,int y) {td.x = x;td.y = y;}
    void setAngle(float angle);

};

#endif // PAINTER_H
