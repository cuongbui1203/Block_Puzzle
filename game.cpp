#include "game.h"

#define SCREEN_WIDTH screen.x
#define SCREEN_HEIGHT screen.y

void Game::create(void){
    init();                     /// khởi tạo các thư viện cần thiết

    window      = nullptr;
    renderer    = nullptr;
    texture     = nullptr;
    screen.x    = 0;
    screen.y    = 0;

    miku.create();

    miku.singingMusic       = true;
    miku.singingEffect      = true;
    miku.begin();

    miku.sing();

    ///lấy kích thước màn hình hiện tại
    getResolution(screen);

    /// thay đổi độ phân giải
    std::cout<<SCREEN_HEIGHT<<'\n'<<SCREEN_WIDTH<<'\n';
    SCREEN_WIDTH = 1920;
    SCREEN_HEIGHT = 1080;

    createWindow(window,renderer,screen);

    ///cài đặt hiển thị của icon game
/**************************************************************/
    SDL_Surface* icon = IMG_Load(PATH_iCON_WINDOW.c_str());
    SDL_SetWindowIcon(window,icon);
    SDL_FreeSurface(icon);
    icon = nullptr;
/**************************************************************/

    texture = SDL_CreateTexture(renderer,SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_TARGET,SCREEN_WIDTH,SCREEN_HEIGHT);

}

void Game::free(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(texture);
    miku.free();

    window      = nullptr;
    renderer    = nullptr;
    texture     = nullptr;

    /// thoát khởi các thư viện
    SDL_Quit();
    Mix_Quit();
    TTF_Quit();
}
