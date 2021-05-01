#pragma once
#include "init.h"

class block{
private:
    toado td;
    int row,col;
    int size;
    bool m,live,focus;
    int p = 6;
    int o = 2;
    int width,height;

    toado miniArr();
    void resize(const toado&);
    void getmax(int&,int&,int&,int&);
    bool inCorect(const block&,const int&,const int&);
public:
    int* h;
    int* h2;

    void move(const bool& val)  {m = val;}
    void setSize(const int& val) {size = val;}
    void setPossition(const toado & val)  {td = val;}
    void setPossition(const int& x,const int& y)  {td.x = x; td.y = y;}
    void setPossition(const SDL_Rect&val) {td.x = val.x;td.y = val.y;}
    void setSize(const SDL_Rect);
    void setColor(const int&);
    void kill(void);
    void revive(void) {live = true;}
    void setWidth(const int & val) {width = val;}
    void setHeight(const int & val) {height = val;}
    void Focus() {focus = true;}
    void UnFocus() {focus = false;}
    void create(const int,const int);

    void optimize();

    int countZero(void) const;

    int getRow() const {return row;}
    int getCol() const {return col;}
    int getSize() const {return size;}
    int getWidth() const {return width;}
    int getHeigh() const {return height;}
    bool isMove() const {return m;}
    bool isLive() const {return live;}
    bool isFocus() const {return focus;}
    bool inCorect(const block&)const;
    toado getToado() const {return td;}

    bool inBlock(const toado&);
    bool inBoard(block&);

    bool fullCol(const int& pos);
    bool fullRow(const int& pos);
    void deleteCol(const int& pos);
    void deleteRow(const int& pos);

    int check(void);
    void update(SDL_Rect&dsc);
    void ncTiepTheo(block&);

    void showBoard(SDL_Renderer*&,const SDL_Rect&);
    void showBoard2(SDL_Renderer*&,const SDL_Rect&);
    void showShape(SDL_Renderer*&,const SDL_Rect&);

};

void setColor2(SDL_Renderer*&,int);
