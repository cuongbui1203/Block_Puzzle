#include "xuly.h"
#include "game.h"

int main(int agrc,char* agrv[]){
    /*** khởi tạo các biến cần thiết ***/
    Game game;

    game.create();

    switch(home(game)){
    case PLAY:
        play(game);
        break;
    default:
        break;
    }

    game.free();

    return 0;
}
