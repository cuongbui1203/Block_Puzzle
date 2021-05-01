#include "block.h"
#include "common_function.h"
#include <vector>
#include "Img.h"
void block::showBoard(SDL_Renderer*&renderer,const SDL_Rect& playScreen){
    SDL_Rect dsc;

    dsc.x = playScreen.x-p;
    dsc.y = playScreen.y;
    dsc.w = p;
    dsc.h = playScreen.h + p;
    setColorRenderer(renderer,WHITE_COLOR);
    for(int i = 0;i<11;i++){
        SDL_RenderFillRect(renderer,&dsc);
        dsc.x += size + p;
    }
    dsc.x = playScreen.x -  p;
    dsc.y = playScreen.y -  p;
    dsc.w = playScreen.w + 2*p;
    dsc.h = p;
    for(int i = 0;i<11;i++){
        SDL_RenderFillRect(renderer,&dsc);
        dsc.y += size + p;
    }

    dsc.x = playScreen.x;
    dsc.y = playScreen.y;
    dsc.w = dsc.h = size;

    for(int i = 0;i<row;i++){
        for(int t = 0;t<col;t++){
            if(h[posInArr(i,t,col)] != 0){
                setColor2(renderer,h[posInArr(i,t,col)]);
                SDL_RenderFillRect(renderer,&dsc);
            }

            dsc.x+=size+p;
        }
        dsc.x = playScreen.x;
        dsc.y += size + p;
    }
}

void block::showBoard2(SDL_Renderer*&renderer,const SDL_Rect& playScreen){
        SDL_Rect dsc;
    //dsc.w = dsc.h = size;

    dsc.x = playScreen.x-p;
    dsc.y = playScreen.y;
    dsc.w = p;
    dsc.h = playScreen.h + p;
    setColorRenderer(renderer,WHITE_COLOR);
    for(int i = 0;i<11;i++){
        SDL_RenderFillRect(renderer,&dsc);
        dsc.x += size + p;
    }

    dsc.x = playScreen.x -  p;
    dsc.y = playScreen.y -  p;

    dsc.w = playScreen.w + 2*p;
    dsc.h = p;
    for(int i = 0;i<11;i++){
        SDL_RenderFillRect(renderer,&dsc);
        dsc.y += size + p;
    }

    dsc.x = playScreen.x;
    dsc.y = playScreen.y;
    dsc.w = dsc.h = size;

    for(int i = 0;i<row;i++){
        for(int t = 0;t<col;t++){
            if(h2[posInArr(i,t,col)] != 0){
                setColor2(renderer,h[posInArr(i,t,col)]);
                SDL_RenderFillRect(renderer,&dsc);
            }
            dsc.x+=size+p;
        }
        dsc.x = playScreen.x;
        dsc.y += size + p;
    }
}

void block::deleteCol(const int& pos){
    for(int i = 0;i<row;i++){
        h[posInArr(i,pos,col)] = 0;
        h2[posInArr(i,pos,col)] = 0;
    }
}

void block::deleteRow(const int& pos){
    for(int i = 0;i<col;i++){
        h[posInArr(pos,i,col)] = 0;
        h2[posInArr(pos,i,col)] = 0;
    }
}

bool block::fullCol(const int& pos){
    for(int i = 0;i<row;i++){
        if(!h[posInArr(i,pos,col)])
            return false;
    }
    return true;
}

bool block::fullRow(const int& pos){
    for(int i = 0;i<col;i++){
        if(!h[posInArr(pos,i,col)])
            return false;
    }
    return true;
}

void block::create(const int c,const int r){
//    delete[] h;
    revive();
    col = c;
    row = r;
    width = col * (size + p);
    height = row * (size + p);
    h = new int[col * row]();
    h2 = new int[col * row]();

    UnFocus();
}

void block::setSize(const SDL_Rect playScreen){
    size = playScreen.w/col - p;
}

void block::setColor(const int &cl){
    for(int i = 0;i<row;i++){
        for(int t = 0;t<col;t++){
            if(h[posInArr(i,t,col)] != 0){
                h[posInArr(i,t,col)] = cl;
            }
        }
    }
}

toado block::miniArr(){
    int r = 0,c = 0;
    toado res;
    res.x = 0; ///col
    res.y = 0; ///row
    for(int i = 0;i<row;i++){
        for(int j = 0;j<col;j++){
            if(h[posInArr(i,j,col)] != 0){
                r = i;
                c = j;
                getmax(res.x,res.y,c,r);
            }
        }
    }
    res.x++;
    res.y++;
    return res;
}

void block::optimize(){
    toado tg = miniArr();
    resize(tg);
    col = tg.x;
    row = tg.y;
    width = col * (size + p) + (col > 3 ? size:0);
    height = row * (size + p) + (row > 3 ? size:0);
}

void block::resize(const toado& tg){
    int *b = new int[tg.x*tg.y]();
    for(int i = 0;i<tg.y;i++){
        for(int t = 0;t<tg.x;t++){
            b[posInArr(i,t,tg.x)] = h[posInArr(i,t,col)];
        }
    }
    delete[] h;
    h = b;
    col = tg.x;
    row = tg.y;
}

void block::getmax(int&maxRow,int&maxCol,int&row_,int&col_){
    maxCol = std::max(maxCol,col_);
    maxRow = std::max(maxRow,row_);
}

void block::showShape(SDL_Renderer*&renderer,const SDL_Rect& a){
    SDL_Rect dsc;
    dsc.x = a.x;
    dsc.y = a.y;
    dsc.w = dsc.h = size;
    for(int i = 0;i<row;i++){
        for(int t = 0;t<col;t++){
                if(h[posInArr(i,t,col)] != 0){
                    setColor2(renderer,h[posInArr(i,t,col)]);
                    SDL_RenderFillRect(renderer,&dsc);
                }
            dsc.x+=size+o;
        }
        dsc.x = a.x;
        dsc.y += size + o;
    }
}

bool block::inBlock(const toado& point){ /// chuột
    SDL_Rect rect;

    rect.y = td.y;
    rect.x = td.x;
    rect.h = (size+p)*row; /// chiều dài(x)
    rect.w = (size+p)*col; /// chiều rộng(y)
    int x,y;
    for(int i = 0;i<row;i++){
        for(int t = 0;t<col;t++){
            if(point.x > rect.x && point.x < (rect.x + rect.w) && point.y > rect.y && point.y < (rect.h + rect.y)){
                    x = (size+p)*t;
                    y = (size+p)*i;
                    if(point.x >= (rect.x + x) && point.x <= (rect.x + x + size + p) && point.y >= rect.y + y && point.y <= (rect.y + y + size + p)){
                        return true;
                }
            }
        }
    }
    return false;
}

void block::update(SDL_Rect&dsc){
        dsc.x = td.x;
        dsc.y = td.y;
}

bool block::inBoard(block& board){
    int r = (td.y + size/2 - board.getToado().y) / (board.size + p);
    int c = (td.x + size/2 - board.getToado().x) / (board.size + p);
    if(
       td.x + size/2 >= board.getToado().x- size/2&&
      (td.x + size/2 + getWidth()) <= (board.getToado().x + board.getWidth()) &&
       td.y + size/2 >= board.getToado().y- size/2&&
      (td.y + size/2 + getHeigh()) <= (board.getToado().y + board.getHeigh()) &&
       inCorect(board,r,c)){
/*
        td.x = c*(board.size + p) + board.getToado().x;
        td.y = r*(board.size + p)+ board.getToado().y;
*/
        for(int i = 0;i<row;i++){
            for(int t = 0;t<col;t++){
                if(h[posInArr(i,t,col)] != 0)
                    board.h[posInArr(i+r,t+c,board.getCol())] = h[posInArr(i,t,col)];
            }
        }

        //std::cout<<"c = "<<c<<"\nr = "<<r<<"\nx = "<<tg.x<<"\ny = "<<tg.y<<"\n";
        return true;
    }
    return false;
}

bool block::inCorect(const block &board,const int &r,const int &c){
    for(int i = 0;i<row;i++){
        for(int t = 0;t<col;t++){
            if(h[posInArr(i,t,col)] != 0 && board.h[posInArr(i+r,t+c,board.getCol())] != 0)
                return false;
        }
    }
    return true;
}
bool block::inCorect(const block& board) const {
    std::vector<bool> trg;

    for(int i = 0;i<(board.getRow() - row + 1);i++){
        for(int t = 0;t < (board.getCol() - col + 1);t++){

             /****************************************************/

                    bool tip = false;
                    for(int j = 0;j < row;j++){
                        for(int k = 0;k < col;k++){
                            if(h[posInArr(j,k,col)] * board.h[posInArr(i+j,t+k,board.getCol())] != 0)
                                tip = true;
                            if(tip == true)
                                break;
                        }
                        if(tip == true){
                            trg.push_back(false);
                            break;
                        }else if(tip == false && j == row-1)
                            trg.push_back(true);
                    }

            /********************************************************/

        }
    }
    for(bool c:trg)
        if(c == true){
            trg.clear();
            return false;
        }

    trg.clear();
    return true;
}



int block::check(void){
    std::vector<Uint8> colFull;
    std::vector<Uint8> rowFull;

    for(int i = 0;i<col;i++)
        if(fullCol(i))
            colFull.push_back(i);
    for(int i = 0;i<row;i++)
        if(fullRow(i))
            rowFull.push_back(i);

    for(Uint8 i:colFull)
        deleteCol(i);

    for(Uint8 i:rowFull)
        deleteRow(i);
    int res = colFull.size() + rowFull.size();
    rowFull.clear();
    colFull.clear();
    return res;
}

int block::countZero(void) const{
    int res = 0;
    for(int i = 0;i<row;i++){
        for(int t = 0;t<col;t++){
            if(h[posInArr(i,t,col)] == 0){
                res++;
            }
        }
    }
    return res;
}

void block::kill(void){
    live = false;

}

void block::ncTiepTheo(block& board){
    for(int i = 0;i < board.getCol()*board.getRow();i++){
        board.h2[i] = board.h[i];
    }

    int r = (td.y + size/2 - board.getToado().y) / (board.size + p);
    int c = (td.x + size/2 - board.getToado().x) / (board.size + p);
    if(
       td.x + size/2 >= board.getToado().x- size/2&&
      (td.x + size/2 + getWidth()) <= (board.getToado().x + board.getWidth()) &&
       td.y + size/2 >= board.getToado().y- size/2&&
      (td.y + size/2 + getHeigh()) <= (board.getToado().y + board.getHeigh()) &&
       inCorect(board,r,c)){
            for(int i = 0;i<row;i++){
                for(int t = 0;t<col;t++){
                    if(h[posInArr(i,t,col)] != 0)
                        board.h2[posInArr(i+r,t+c,board.getCol())] = h[posInArr(i,t,col)];
                }
            }
        }
}

void setColor2(SDL_Renderer*&renderer, int val){
    switch(val){
    case 1:
        setColorRenderer(renderer,CYAN_COLOR);
        break;
    case 2:
        setColorRenderer(renderer,BLUE_COLOR);
        break;
    case 3:
        setColorRenderer(renderer,ORANGE_COLOR);
        break;
    case 4:
        setColorRenderer(renderer,YELLOW_COLOR);
        break;
    case 5:
        setColorRenderer(renderer,LIME_COLOR);
        break;
    case 6:
        setColorRenderer(renderer,PURPLE_COLOR);
        break;
    case 7:
        setColorRenderer(renderer,RED_COLOR);
        break;
    case 8:
        setColorRenderer(renderer,GREEN_COLOR);
        break;
    default:
        setColorRenderer(renderer,WHITE_COLOR);

    }
}
