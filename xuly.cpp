#include "xuly.h"
#include "common_function.h"
#include "Img.h"
#include "Button.h"
#include "Text.h"
#include "SDL2_rotozoom.h"
#include "common.h"

#define SCREEN_HEIGHT game.screen.y
#define SCREEN_WIDTH game.screen.x
#define window game.window
#define renderer game.renderer
#define miku game.miku

/**************************************************/
const int CAC_TRUONG_HOP[MAX_CASES][5][5]{
             /**
                *       1
            */
            {
                {-1, 0, 0, 0, 0},
                { 0, 0, 0, 0, 0},
                { 0, 0, 0, 0, 0},
                { 0, 0, 0, 0, 0},
                { 0, 0, 0, 0, 0},
            },
            /**
                **      2
                **
            */
            {
                {-1,-1, 0, 0, 0},
                {-1,-1, 0, 0, 0},
                { 0, 0, 0, 0, 0},
                { 0, 0, 0, 0, 0},
                { 0, 0, 0, 0, 0},
            },
            /**
                ***     3
                ***
            */
            {
                {-1,-1,-1, 0, 0},
                {-1,-1,-1, 0, 0},
                {-1,-1,-1, 0, 0},
                { 0, 0, 0, 0, 0},
                { 0, 0, 0, 0, 0},
            },
            /**
                *
                *       4
            */
            {
                {-1, 0, 0, 0, 0},
                {-1, 0, 0, 0, 0},
                { 0, 0, 0, 0, 0},
                { 0, 0, 0, 0, 0},
                { 0, 0, 0, 0, 0},
            },
            /**
                **      5
            */
            {
                {-1,-1, 0, 0, 0},
                { 0, 0, 0, 0, 0},
                { 0, 0, 0, 0, 0},
                { 0, 0, 0, 0, 0},
                { 0, 0, 0, 0, 0},
            },
            /**
                *
                *       6
                *
            */
            {
                {-1, 0, 0, 0, 0},
                {-1, 0, 0, 0, 0},
                {-1, 0, 0, 0, 0},
                { 0, 0, 0, 0, 0},
                { 0, 0, 0, 0, 0},
            },

            /**
                ***     7
            */
            {
                {-1,-1,-1, 0, 0},
                { 0, 0, 0, 0, 0},
                { 0, 0, 0, 0, 0},
                { 0, 0, 0, 0, 0},
                { 0, 0, 0, 0, 0},
            },
            /**
                *
                *
                *       8
                *
            */
            {
                {-1, 0, 0, 0, 0},
                {-1, 0, 0, 0, 0},
                {-1, 0, 0, 0, 0},
                {-1, 0, 0, 0, 0},
                { 0, 0, 0, 0, 0},
            },
            /**
                ****        9
            */
            {
                {-1,-1,-1,-1, 0},
                { 0, 0, 0, 0, 0},
                { 0, 0, 0, 0, 0},
                { 0, 0, 0, 0, 0},
                { 0, 0, 0, 0, 0},
            },
            /**
                *
                *
                *
                *       10
                *
            */
            {
                {-1, 0, 0, 0, 0},
                {-1, 0, 0, 0, 0},
                {-1, 0, 0, 0, 0},
                {-1, 0, 0, 0, 0},
                {-1, 0, 0, 0, 0},
            },
            /**
                *****   11
            */
            {
                {-1,-1,-1,-1,-1},
                { 0, 0, 0, 0, 0},
                { 0, 0, 0, 0, 0},
                { 0, 0, 0, 0, 0},
                { 0, 0, 0, 0, 0},
            },
            /**
                **      12
                *
            */
            {
                {-1,-1, 0, 0, 0},
                {-1, 0, 0, 0, 0},
                { 0, 0, 0, 0, 0},
                { 0, 0, 0, 0, 0},
                { 0, 0, 0, 0, 0},
            },
            /**
                **      13
                 *
            */
            {
                {-1,-1, 0, 0, 0},
                { 0,-1, 0, 0, 0},
                { 0, 0, 0, 0, 0},
                { 0, 0, 0, 0, 0},
                { 0, 0, 0, 0, 0},
            },
            /**
                 *      14
                **
            */
            {
                { 0,-1, 0, 0, 0},
                {-1,-1, 0, 0, 0},
                { 0, 0, 0, 0, 0},
                { 0, 0, 0, 0, 0},
                { 0, 0, 0, 0, 0},
            },
            /**
                *
                **      15
            */
            {
                {-1, 0, 0, 0, 0},
                {-1,-1, 0, 0, 0},
                { 0, 0, 0, 0, 0},
                { 0, 0, 0, 0, 0},
                { 0, 0, 0, 0, 0},
            },
            /**
                *
                *       16
                **
            */
            {
                {-1, 0, 0, 0, 0},
                {-1, 0, 0, 0, 0},
                {-1,-1, 0, 0, 0},
                { 0, 0, 0, 0, 0},
                { 0, 0, 0, 0, 0},
            },
            /**
                 *      17
                 *
                **
            */
            {
                { 0,-1, 0, 0, 0},
                { 0,-1, 0, 0, 0},
                {-1,-1, 0, 0, 0},
                { 0, 0, 0, 0, 0},
                { 0, 0, 0, 0, 0},
            },
            /**
                  *     18
                ***
            */
            {
                { 0, 0,-1, 0, 0},
                {-1,-1,-1, 0, 0},
                { 0, 0, 0, 0, 0},
                { 0, 0, 0, 0, 0},
                { 0, 0, 0, 0, 0},
            },
            /**
                ***     19
                  *
            */
            {
                {-1,-1,-1, 0, 0},
                { 0, 0,-1, 0, 0},
                { 0, 0, 0, 0, 0},
                { 0, 0, 0, 0, 0},
                { 0, 0, 0, 0, 0},
            },
            /**
                 *      20
                ***
            */
    {
                { 0,-1, 0, 0, 0},
                {-1,-1,-1, 0, 0},
                { 0, 0, 0, 0, 0},
                { 0, 0, 0, 0, 0},
                { 0, 0, 0, 0, 0},
            },
            /**
                ***
                *
            */
            {
                {-1,-1,-1, 0, 0},
                { 0,-1, 0, 0, 0},
                { 0, 0, 0, 0, 0},
                { 0, 0, 0, 0, 0},
                { 0, 0, 0, 0, 0},
            },
            /**
                *
                **
                *
            */
            {
                {-1, 0, 0, 0, 0},
                {-1,-1, 0, 0, 0},
                {-1, 0, 0, 0, 0},
                { 0, 0, 0, 0, 0},
                { 0, 0, 0, 0, 0},
            },
            /**
                 *
                **
                 *
            */
            {
                { 0,-1, 0, 0, 0},
                {-1,-1, 0, 0, 0},
                { 0,-1, 0, 0, 0},
                { 0, 0, 0, 0, 0},
                { 0, 0, 0, 0, 0},
            },
            /**
                 **
                **
            */

            {
                { 0,-1,-1, 0, 0},
                {-1,-1, 0, 0, 0},
                { 0, 0, 0, 0, 0},
                { 0, 0, 0, 0, 0},
                { 0, 0, 0, 0, 0},
            },
            /**
                **
                 **
            */

            {
                {-1,-1, 0, 0, 0},
                { 0,-1,-1, 0, 0},
                { 0, 0, 0, 0, 0},
                { 0, 0, 0, 0, 0},
                { 0, 0, 0, 0, 0},
            },
            /**
                 *
                **
                *
            */

            {
                { 0,-1, 0, 0, 0},
                {-1,-1, 0, 0, 0},
                {-1, 0, 0, 0, 0},
                { 0, 0, 0, 0, 0},
                { 0, 0, 0, 0, 0},
            },
            /**
                *
                **
                 *
            */

            {
                {-1, 0, 0, 0, 0},
                {-1,-1, 0, 0, 0},
                { 0,-1, 0, 0, 0},
                { 0, 0, 0, 0, 0},
                { 0, 0, 0, 0, 0},
            },
            /**
               ***
               *
               *
            */

            {
                {-1,-1,-1, 0, 0},
                {-1, 0, 0, 0, 0},
                {-1, 0, 0, 0, 0},
                { 0, 0, 0, 0, 0},
                { 0, 0, 0, 0, 0},
            },
            /**
               ***
                 *
                 *
            */

            {
                {-1,-1,-1, 0, 0},
                { 0, 0,-1, 0, 0},
                { 0, 0,-1, 0, 0},
                { 0, 0, 0, 0, 0},
                { 0, 0, 0, 0, 0},
            },
            /**
                 *
                 *
               ***
            */

            {
                { 0, 0,-1, 0, 0},
                { 0, 0,-1, 0, 0},
                {-1,-1,-1, 0, 0},
                { 0, 0, 0, 0, 0},
                { 0, 0, 0, 0, 0},
            },
            /**
                *
                *
                ***
            */

            {
                {-1, 0, 0, 0, 0},
                {-1, 0, 0, 0, 0},
                {-1,-1,-1, 0, 0},
                { 0, 0, 0, 0, 0},
                { 0, 0, 0, 0, 0},
            },
    };

/**************************************************/

void play(Game& game){

    SDL_Texture* staticTexture      = nullptr;
    SDL_Surface* staticSurface      = nullptr;
    SDL_Surface* load               = nullptr;


    int board_size                  = 74;
    int shape_size                  = 50; /// kích thước của các hình thu nhỏ
    int crFull                      = 0;  /// tổng số cột và hàng full trong mảng
    int tam                         = 0;  /// tổng số cột và hàng full trong mảng (tạm thời)

    /// các biến cần thiết
    bool isrunning                  = true;
    bool restart                    = false;
    bool game_over                  = false;
    SDL_Event e;
    Uint32 startTime,oldTimeShowBonus,timeShowBonus;
    unsigned int score = 0,hightScore = 0;
    toado mouse,tg,oldMouse;
    block board,hinh1,hinh2,hinh3;
    toado dsc1Old,dsc2Old,dsc3Old;

    std::string bonuss[3];
    bonuss[0] = "cool";
    bonuss[1] = "excellent";
    bonuss[2] = "perfect";

    ///img icon,bkground; /// hình background và hình icon
    ///biến lưu vị trí và kích thước của các vị trí
    SDL_Rect playScreen,dsc1,dsc2,dsc3,dscIcon,dscScore,dscHightScore,dscNameScore,dscNameHightScore,dscMenu,dscMsgBonus;
    ///biến kiểm soát các chữ viết
    ///text nameScore,nameHightScore;
    ///biến kiểm soát các button
    Button menu;
    std::fstream f;
    f.open(PATH_FILE_HIGH_SCORE,std::ios_base::in);
    f>>hightScore;
    f.close();
    ///cài đặt các vị trí cho các thành phần
/*******************************************/
    dscNameScore.x = 220;
    dscNameScore.y = 330;
    dscNameScore.w = 0;
    dscNameScore.h = 0;

    dscNameHightScore.x = 170;
    dscNameHightScore.y = 330-121-50;
    dscNameHightScore.w = 0;
    dscNameHightScore.h = 0;

    dscHightScore.x = 100;
    dscHightScore.y = 205;
    dscScore.w = dscHightScore.w = 390;
    dscScore.h = dscHightScore.h = 121;

    dscScore.x = 100;
    dscScore.y = 380;

    dscMenu.w = 95;
    dscMenu.h = 90;
    dscMenu.x = 65;
    dscMenu.y = 41;


    dscIcon.x = 140;
    dscIcon.y = 562;
    dscIcon.h = 447;
    dscIcon.w = 330;


    playScreen.w = playScreen.h = 794;
    playScreen.x = 567;
    playScreen.y = 189;


    dsc1.x = 1572;
    dsc1.y = 165;
    dsc1Old.x = dsc1.x;
    dsc1Old.y = dsc1.y;
    dsc1.w = dsc1.h = 258;

    dsc2.x = dsc1.x;
    dsc2.y = 458;
    dsc2Old.x = dsc2.x;
    dsc2Old.y = dsc2.y;
    dsc2.w = dsc2.h = 258;

    dsc3.x = dsc2.x;
    dsc3.y = 751;
    dsc3Old.x = dsc3.x;
    dsc3Old.y = dsc3.y;
    dsc3.w = dsc3.h = 258;

    dscMsgBonus.x = 835;
    dscMsgBonus.y = 131;
    dscMsgBonus.w = 250;
    dscMsgBonus.h = 40;

/**************************************/
///khởi tạo các thành phần tĩnh
/***********************************/
    RESTART2:

    menu.setup(dscMenu);

    std::string path = PATH_BKG;

    SDL_Rect tg_;
    ///load background Image
    staticSurface = IMG_Load(path.c_str());
    //staticSurface = zoomSurface(staticSurface,1920/staticSurface->w,1080/staticSurface->h,SMOOTHING_ON);
    SDL_SetSurfaceBlendMode(staticSurface,SDL_BLENDMODE_NONE);

    ///load icon image

    path = PATH_iCON;

    load = IMG_Load(path.c_str());

    load = zoomSurface(load,0.95,0.95,SMOOTHING_ON);

    SDL_SetSurfaceBlendMode(load,SDL_BLENDMODE_NONE);
    SDL_SetColorKey(load, SDL_TRUE,SDL_MapRGB(load->format,0x0,0x0,0x0));

    tg_ = dscIcon;
    if(SDL_BlitSurface(load,nullptr,staticSurface,&tg_))
        std::cout<<SDL_GetError()<<'\n';

    SDL_FreeSurface(load);
    load = nullptr;
    ///load home button
    path = PATH_HOME_BUTTON;

    load = IMG_Load(path.c_str());

    load = zoomSurface(load,0.9,0.9,SMOOTHING_ON);

    SDL_SetSurfaceBlendMode(load,SDL_BLENDMODE_BLEND);

    tg_ = dscMenu;
    if(SDL_BlitSurface(load,nullptr,staticSurface,&tg_))
        std::cout<<SDL_GetError()<<'\n';

    SDL_FreeSurface(load);
    load = nullptr;

    ///load Text Hight Score
    path = PATH_FONT;
    TTF_Font* font = TTF_OpenFont(path.c_str(),40);

    if(font==nullptr)
        std::cout<<TTF_GetError()<<'\n';
    std::string nd = "HIGH SCORE";

    load = TTF_RenderText_Solid(font,nd.c_str(),BLACK_COLOR);

    if(load == nullptr)
        std::cout<<SDL_GetError();

    SDL_SetSurfaceBlendMode(load,SDL_BLENDMODE_NONE);
    SDL_SetColorKey(load, SDL_TRUE,SDL_MapRGB(load->format,0xFF,0xFF,0xFF));

    tg_ = dscNameHightScore;

    if(SDL_BlitSurface(load,nullptr,staticSurface,&tg_))
        std::cout<<SDL_GetError()<<'\n';

    SDL_FreeSurface(load);
    load = nullptr;

    ///load Text Score
    nd = "SCORE";

    load = TTF_RenderText_Solid(font,nd.c_str(),BLACK_COLOR);

    if(load == nullptr)
        std::cout<<SDL_GetError();

    SDL_SetSurfaceBlendMode(load,SDL_BLENDMODE_NONE);
    SDL_SetColorKey(load, SDL_TRUE,SDL_MapRGB(load->format,0xFF,0xFF,0xFF));

    tg_ = dscNameScore;

    if(SDL_BlitSurface(load,nullptr,staticSurface,&tg_))
        std::cout<<SDL_GetError()<<'\n';

    SDL_FreeSurface(load);
    load = nullptr;

    ///create staticTexture
    staticTexture = SDL_CreateTextureFromSurface(renderer,staticSurface);

/***********************************/

/// khởi tạo các biến của game
/**********************************/
    board.h = nullptr;
    hinh1.h = nullptr;
    hinh2.h = nullptr;
    hinh3.h = nullptr;

    board.setSize(board_size);
    hinh1.setSize(shape_size);
    hinh2.setSize(shape_size);
    hinh3.setSize(shape_size);

    board.create(10,10);

    create(hinh1,board);
    create(hinh2,board);
    create(hinh3,board);

    board.setPossition(playScreen);

    hinh1.setPossition(dsc1);
    hinh2.setPossition(dsc2);
    hinh3.setPossition(dsc3);
/*************************************/
///vòng lặp chính của game
/*************************************/
    oldTimeShowBonus = timeShowBonus = SDL_GetTicks();
    while(isrunning){
        startTime = SDL_GetTicks();

        setColorRenderer(renderer,BLACK_COLOR);
        SDL_RenderClear(renderer);

        SDL_RenderCopy(renderer,staticTexture,nullptr,nullptr);

        setColorRenderer(renderer,{151,255,255});
        SDL_RenderFillRect(renderer,&dscHightScore);
        SDL_RenderFillRect(renderer,&dscScore);


        if((hinh1.isLive() == false && hinh2.isLive() == false && hinh3.isLive() == false)){
            create(hinh1,board);
            create(hinh2,board);
            create(hinh3,board);
        }
        while(gameOver(hinh1,hinh2,hinh3,board,false) != true && hinh1.isLive() && hinh2.isLive() && hinh3.isLive()){
            create(hinh1,board);
            create(hinh2,board);
            create(hinh3,board);
        }

        while(SDL_PollEvent(&e)){
            switch(e.type){
            case SDL_QUIT:
                if(confirm(game))
                    isrunning = false;
                break;
            case SDL_KEYDOWN:
                if(e.key.keysym.sym == SDLK_ESCAPE){
                    switch(cho(game)){
                        case EXIT:
                            goto THOAT;
                            break;
                        case PLAY:
                            restart = true;
                            goto RESTART;
                        case NONE:
                            break;
                        }
                    }
                break;
            case SDL_MOUSEBUTTONDOWN:
                if(e.button.button == SDL_BUTTON_LEFT){

                    oldMouse = mouse;

                    if(hinh1.isMove() == true){
                        hinh1.move(false);
                        if(hinh1.inBoard(board) == true && hinh1.isFocus()){
                            delete[] hinh1.h;
                            hinh1.create(5,5);
                            hinh1.kill();
                            score += 5;
                            miku.playEffect();
                        }
                        hinh1.setPossition(dsc1Old);
                        hinh1.setSize(shape_size);
                        hinh1.UnFocus();
                    }else if(hinh2.isMove() == true && hinh2.isFocus()){
                        hinh2.move(false);
                        if(hinh2.inBoard(board) == true){
                            delete[] hinh2.h;
                            hinh2.create(5,5);
                            hinh2.kill();
                            score += 5;
                            miku.playEffect();
                        }
                        hinh2.setPossition(dsc2Old);
                        hinh2.setSize(shape_size);
                        hinh2.UnFocus();
                    }else if(hinh3.isMove() == true && hinh3.isFocus()){
                        hinh3.move(false);
                        if(hinh3.inBoard(board) == true){
                            delete[] hinh3.h;
                            hinh3.create(5,5);
                            hinh3.kill();
                            score += 5;
                            miku.playEffect();
                        }
                        hinh3.setPossition(dsc3Old);
                        hinh3.setSize(shape_size);
                        hinh3.UnFocus();
                    }else if(hinh1.inBlock(mouse) && !hinh1.isFocus()){
                        tg.x = (mouse.x - hinh1.getToado().x)*1.48;
                        tg.y = (mouse.y - hinh1.getToado().y)*1.48;
                        hinh1.move(true);
                        hinh1.Focus();
                        hinh1.setSize(board.getSize());
                        miku.playEffect();
                    }else if(hinh2.inBlock(mouse) && !hinh2.isFocus()){
                        tg.x = mouse.x - hinh2.getToado().x;
                        tg.y = mouse.y - hinh2.getToado().y;
                        hinh2.move(true);
                        hinh2.Focus();
                        hinh2.setSize(board.getSize());
                        miku.playEffect();
                    }else if(hinh3.inBlock(mouse) && !hinh3.isFocus()){
                        tg.x = mouse.x - hinh3.getToado().x;
                        tg.y = mouse.y - hinh3.getToado().y;
                        hinh3.move(true);
                        hinh3.Focus();
                        hinh3.setSize(board.getSize());
                        miku.playEffect();
                    }

                }
                break;
            case SDL_MOUSEBUTTONUP:
                if(menu.click(oldMouse,mouse)){
                    miku.playEffect();
                    switch(cho(game)){
                        case EXIT:

                            goto THOAT;
                            break;
                        case PLAY:
                            restart = true;
                            goto RESTART;
                        case NONE:
                            break;
                        }

                }
                break;
            case SDL_MOUSEMOTION:
                mouse.x = e.motion.x;
                mouse.y = e.motion.y;
                if(hinh1.isMove() == true  && hinh1.isFocus()){
                    hinh1.setPossition(mouse.x - tg.x,mouse.y - tg.y);
                    hinh1.ncTiepTheo(board);
                }
                if(hinh2.isMove() == true  && hinh2.isFocus()){
                    hinh2.setPossition(mouse.x - tg.x,mouse.y - tg.y);
                    hinh2.ncTiepTheo(board);
                }

                if(hinh3.isMove() == true && hinh3.isFocus()){
                    hinh3.setPossition(mouse.x - tg.x,mouse.y - tg.y);
                    hinh3.ncTiepTheo(board);
                }
                break;
            }
        }

        if(hinh1.isFocus() || hinh2.isFocus() || hinh3.isFocus())
            board.showBoard2(renderer,playScreen);
        else
            board.showBoard(renderer,playScreen);

        //board.showBoard(renderer,playScreen);
        hinh1.update(dsc1);
        hinh2.update(dsc2);
        hinh3.update(dsc3);

        hinh1.showShape(renderer,dsc1);
        hinh2.showShape(renderer,dsc2);
        hinh3.showShape(renderer,dsc3);

        crFull = board.check();

        if(crFull >= 3){
            timeShowBonus += 1000;
            tam = crFull;
        }

        switch(crFull){
        case 0:
            break;
        case 1:
            score += 10;
            break;
        case 2:
            score += 25;
            break;
        case 3:
            score += 50;
            break;
        case 4:
            score += 150;
            break;
        default:
            score += 200;
            break;
        }

        if(oldTimeShowBonus >= timeShowBonus){
            oldTimeShowBonus = timeShowBonus = SDL_GetTicks();

        }else{
            std::string tem;

            oldTimeShowBonus = SDL_GetTicks();

            if(tam == 3)
                tem = bonuss[0];
            else if(tam == 4)
                tem = bonuss[1];
            else if(tam >= 5)
                tem = bonuss[2];

            showText(renderer,tem,35,BLACK_COLOR,dscMsgBonus);
        }

        hightScore = std::max(hightScore,score);

        showText(renderer,std::to_string(score),40,BLACK_COLOR,dscScore);
        showText(renderer,std::to_string(hightScore),40,BLACK_COLOR,dscHightScore);

        if(gameOver(hinh1,hinh2,hinh3,board,true)){
            showImg(renderer,PATH_GAMEOVER_SCREEN,nullptr);
            game_over = true;
            isrunning = false;
            std::cout<<"Game Ovre!\n";
            showScreen(window,renderer);
            SDL_Delay(2000);
            SDL_RenderClear(renderer);
        }

        showScreen(window,renderer);
        delay(startTime);
    }

    f.open(PATH_FILE_HIGH_SCORE,std::ios_base::out);
    f<<(hightScore > score ? hightScore:score);
    f.close();
    if(game_over == true){
        if(gameOver(game,hightScore,score)){
            restart = true;
            goto RESTART;
        }
    }

    THOAT:
    RESTART:

    delete[] hinh1.h;
    delete[] hinh2.h;
    delete[] hinh3.h;
    delete[] board.h;

    delete[] hinh1.h2;
    delete[] hinh2.h2;
    delete[] hinh3.h2;
    delete[] board.h2;

    SDL_DestroyTexture(staticTexture);
    SDL_FreeSurface(staticSurface);
    TTF_CloseFont(font);

    staticSurface       = nullptr;
    staticTexture       = nullptr;
    font                = nullptr;

    if(restart){
        isrunning = true;
        score = 0;
        restart = false;
        game_over = false;
        goto RESTART2;
    }
}

/**************************************************/

luachon cho(Game& game){
    SDL_Event e;
    Uint32 startTime;
    toado mouse,oldMouse;
    Button dscContinue,exit,music,mute,restart;
    SDL_Rect dscExit,dsc_Continue,dscMute,dscMusic,dscRestart;
    std::string mute_[2];
    std::string music_[2];

    mute_[1]  = PATH_UNMUTE_BUTTON;
    mute_[0]  = PATH_MUTE_BUTTON;
    music_[0] = PATH_MUTEMUSIC_BUTTON;
    music_[1] = PATH_UNMUTEMUSIC_BUTTON;

    dscExit.x = 733;
    dscExit.y = 790;
    dscExit.w = 455;
    dscExit.h = 123;

    dsc_Continue.x =  733;
    dsc_Continue.y = 456;
    dsc_Continue.w = 455;
    dsc_Continue.h = 123;

    dscRestart.x =  733;
    dscRestart.y = 623;
    dscRestart.w = 455;
    dscRestart.h = 123;

    dscMute.w = dscMute.h =  dscMusic.h = dscMusic.w = 77;
    dscMute.x = 834;
    dscMute.y = 335;

    dscMusic.x = 1011;
    dscMusic.y = 335;

    exit.setup(dscExit);
    dscContinue.setup(dsc_Continue);
    restart.setup(dscRestart);
    mute.setup(dscMute);
    music.setup(dscMusic);

    while(true){
        startTime = SDL_GetTicks();
        SDL_RenderClear(renderer);
        setColorRenderer(renderer,WHITE_COLOR);

        showImg(renderer,PATH_BKG,nullptr);

        showImg(renderer,PATH_BUTTON,&dsc_Continue);
        showImg(renderer,PATH_BUTTON,&dscRestart);
        showImg(renderer,PATH_BUTTON,&dscExit);
        showImg(renderer,mute_[miku.singingEffect],&dscMute);
        showImg(renderer,music_[miku.singingMusic],&dscMusic);

        showText(renderer,"CONTINUE",40,BLACK_COLOR,dsc_Continue);
        showText(renderer,"EXIT",40,BLACK_COLOR,dscExit);
        showText(renderer,"RESTART",40,BLACK_COLOR,dscRestart);

        while(SDL_PollEvent(&e)){
            switch(e.type){
            case SDL_QUIT:
                return NONE;
            case SDL_KEYDOWN:
                if(e.key.keysym.sym == SDLK_ESCAPE)
                    return NONE;
            case SDL_MOUSEMOTION:
                mouse.x = e.motion.x;
                mouse.y = e.motion.y;
                break;
            case SDL_MOUSEBUTTONDOWN:
                oldMouse = mouse;
                break;
            case SDL_MOUSEBUTTONUP:
                if(dscContinue.click(oldMouse,mouse)){
                    miku.playEffect();
                    return NONE;
                }
                if(exit.click(oldMouse,mouse)){
                    miku.playEffect();
                    if(confirm(game)){
                        return EXIT;
                    }
                }
                if(restart.click(oldMouse,mouse)){
                    miku.playEffect();
                    return PLAY;
                }
                if(music.click(oldMouse,mouse) == true){
                    miku.singingMusic = (miku.singingMusic ? 0:1);
                    miku.playEffect();
                }
                if(mute.click(oldMouse,mouse) == true){
                    miku.singingEffect = (miku.singingEffect ? 0:1);
                    miku.playEffect();
                }
            }
        }
        miku.sing();
        showScreen(window,renderer);
        delay(startTime);
    }
}

/**************************************************/

bool gameOver(Game& game,const int &hight_score,const int &_score){
    SDL_Event e;
    Uint32 startTime;
    toado mouse,oldMouse;
    SDL_Rect dscName,nameScore,nameHightScore,hightScore,score,dscReStart,dscExit;
    Button reStart,exit;

    nameScore.x = 960;
    nameScore.y = 450;
    nameScore.w = 0;
    nameScore.h = 0;

    nameHightScore.x = 960;
    nameHightScore.y = 660;
    nameHightScore.w = 0;
    nameHightScore.h = 0;

    score.x = 562;
    score.y = 480;
    score.w = 796;
    score.h = 113;

    hightScore.x = 562;
    hightScore.y = 686;
    hightScore.w = 796;
    hightScore.h = 113;

    dscName.x = 440;
    dscName.y = 43;
    dscName.w = 1069;
    dscName.h = 266;

    dscReStart.x =  562;
    dscReStart.y = 876;
    dscReStart.w = 315;
    dscReStart.h = 136;


    dscExit.x =  1043;
    dscExit.y = 876;
    dscExit.w = 315;
    dscExit.h = 136;

    reStart.setup(dscReStart);
    exit.setup(dscExit);

    while(true){
        startTime = SDL_GetTicks();
        SDL_RenderClear(renderer);

        showImg(renderer,PATH_BKG,nullptr);
        setColorRenderer(renderer,{151,255,255});

        SDL_RenderFillRect(renderer,&score);
        SDL_RenderFillRect(renderer,&hightScore);

        showText(renderer,std::to_string(_score),40,BLACK_COLOR,score);
        showText(renderer,std::to_string(hight_score),40,BLACK_COLOR,hightScore);
        showText(renderer,"SCORE",40,BLACK_COLOR,nameScore);
        showText(renderer,"HIGH SCORE",40,BLACK_COLOR,nameHightScore);
        showText(renderer,(hight_score == _score ? "HIGH SCORE":"YOUR SCORE"),250,BLACK_COLOR,dscName);

        showImg(renderer,PATH_BUTTON,&dscReStart);
        showImg(renderer,PATH_BUTTON,&dscExit);

        showText(renderer,"RESTART",40,BLACK_COLOR,dscReStart);
        showText(renderer,"EXIT",40,BLACK_COLOR,dscExit);

        while(SDL_PollEvent(&e)){
            switch(e.type){
            case SDL_QUIT:
                if(confirm(game))
                    return false;
            case SDL_KEYDOWN:
                if(e.key.keysym.sym == SDLK_ESCAPE)
                    if(confirm(game))
                        return false;
            case SDL_MOUSEMOTION:
                mouse.x = e.motion.x;
                mouse.y = e.motion.y;
                break;
            case SDL_MOUSEBUTTONDOWN:
                oldMouse = mouse;
                break;
            case SDL_MOUSEBUTTONUP:
                if(reStart.click(oldMouse,mouse))
                    return true;
                if(exit.click(oldMouse,mouse)){
                    if(confirm(game))
                        return false;
                }
                break;
            }
        }

        showScreen(window,renderer);
        delay(startTime);
    }

}

/**************************************************/

luachon home(Game& game){
    //return PLAY;
    setColorRenderer(renderer,BLACK_COLOR);
    SDL_Event e;
    Uint32 startTime = 1;
    toado mouse,oldMouse;
    SDL_Rect dscName,dscMute,dscMusic,dscPlay,dscExit,dscNameMusic,dscNameMute;
    Button play,music,mute,exit;
    luachon res = NONE;
    bool isrunning = true;
    std::string mute_[2];
    std::string music_[2];

    dscName.x = 440;
    dscName.y = 43;
    dscName.w = 1080;
    dscName.h = 266;

    dscMute.w = dscMute.h =  dscMusic.h = dscMusic.w = 77;
    dscMute.x = 865;
    dscMute.y = 431;

    dscMusic.x = 1008;
    dscMusic.y = 431;

    dscNameMute.x = 862;
    dscNameMute.y = 508;
    dscNameMute.w = 67;
    dscNameMute.h = 32;

    dscNameMusic.x = 1013;
    dscNameMusic.y = 508;
    dscNameMusic.w = 65;
    dscNameMusic.h = 32;

    dscPlay.x = 828;
    dscPlay.y = 630;
    dscPlay.w = 294;
    dscPlay.h = 123;

    dscExit.x = 828;
    dscExit.y = 786;
    dscExit.w =294;
    dscExit.h =123;

    play.setup(dscPlay);
    exit.setup(dscExit);
    mute.setup(dscMute);
    music.setup(dscMusic);



    mute_[1]  = PATH_UNMUTE_BUTTON;
    mute_[0]  = PATH_MUTE_BUTTON;
    music_[0] = PATH_MUTEMUSIC_BUTTON;
    music_[1] = PATH_UNMUTEMUSIC_BUTTON;

    while(isrunning){
        startTime = SDL_GetTicks();

        SDL_RenderClear(renderer);

        showImg(renderer,PATH_BKG,nullptr);
        showImg(renderer,PATH_BUTTON,&dscPlay);
        showImg(renderer,PATH_BUTTON,&dscExit);
        showImg(renderer,mute_[miku.singingEffect],&dscMute);
        showImg(renderer,music_[miku.singingMusic],&dscMusic);

        showText(renderer,"BLOCK PUZZLE",200,BLACK_COLOR,dscName);
        showText(renderer,"sound",24,BLACK_COLOR,dscNameMute);
        showText(renderer,"music",24,BLACK_COLOR,dscNameMusic);
        showText(renderer,"PLAY",40,BLACK_COLOR,dscPlay);
        showText(renderer,"EXIT",40,BLACK_COLOR,dscExit);


        while(SDL_PollEvent(&e)){
            switch(e.type){
            case SDL_QUIT:
                if(confirm(game))
                    return EXIT;
            case SDL_KEYDOWN:
                if(e.key.keysym.sym == SDLK_ESCAPE && confirm(game))
                    return EXIT;
            case SDL_MOUSEMOTION:
                mouse.x = e.motion.x;
                mouse.y = e.motion.y;
                break;
            case SDL_MOUSEBUTTONDOWN:
                oldMouse = mouse;
                break;
            case SDL_MOUSEBUTTONUP:
                miku.playEffect();
                if(play.click(oldMouse,mouse) == true){
                    res = PLAY;
                    isrunning = false;
                    break;
                }
                if(exit.click(oldMouse,mouse) == true && confirm(game)){
                    res = EXIT;
                    isrunning = false;
                    break;
                }
                if(music.click(oldMouse,mouse) == true)
                    miku.singingMusic = (miku.singingMusic ? 0:1);
                if(mute.click(oldMouse,mouse) == true)
                    miku.singingEffect = (miku.singingEffect ? 0:1);

            }
        }
        miku.sing();
        showScreen(window,renderer);
        delay(startTime);
    }

    return res;
}
/********************************************/
bool confirm(Game& game){
    SDL_Event e;
    SDL_Rect dscYes,dscNo;
    Button yesBt,noBt;
    toado oldMouse,mouse;

    dscNo.h = dscYes.h = 93;
    dscNo.w = dscYes.w = 233;

    dscNo.x = 810;
    dscNo.y = 635;

    dscYes.x = 1181;
    dscYes.y = 635;

    yesBt.setup(dscYes);
    noBt.setup(dscNo);

    showImg(renderer,PATH_COMFIRM_SCREEN,nullptr);
    showImg(renderer,PATH_BUTTON,&dscNo);
    showImg(renderer,PATH_BUTTON,&dscYes);

    showText(renderer,"YES",40,BLACK_COLOR,dscYes);
    showText(renderer,"NO",40,BLACK_COLOR,dscNo);


    showScreen(window,renderer);

    while(true){
        while(SDL_PollEvent(&e)){
            switch(e.type){
            case SDL_KEYDOWN:
                if(e.key.keysym.sym == SDLK_ESCAPE)
                    return false;
                if(e.key.keysym.sym == SDLK_RETURN)
                    return true;
            case SDL_MOUSEMOTION:
                mouse.x = e.motion.x;
                mouse.y = e.motion.y;
                break;
            case SDL_MOUSEBUTTONDOWN:
                oldMouse = mouse;
                break;
            case SDL_MOUSEBUTTONUP:
                if(yesBt.click(oldMouse,mouse)){
                    miku.playEffect();
                    SDL_Delay(300);
                    return true;
                }
                if(noBt.click(oldMouse,mouse)){
                    miku.playEffect();
                    return false;
                }
            break;
            }
        }
    }
}

/**************************************************/

/**************************************************/

void create(block& h,block& board){
    int a,b;
    START:
        h.create(5,5);

        a = random(1,MAX_CASES) - 1;

        for(int i = 0;i<5;i++){
            for(int t = 0;t<5;t++){
                h.h[posInArr(i,t,5)] = CAC_TRUONG_HOP[a][i][t];
            }
        }

        b = count(h.h,5,5);

        if(b > board.countZero())
            goto START;

        h.setColor(getRandomColor());
        h.optimize();
        h.revive();
}

/**************************************************/

int count(int* h,const int &r,const int &c){
    int res = 0;
    for(int i = 0;i<r;i++){
        for(int t = 0;t<c;t++){
            if(h[posInArr(i,t,c)] != 0)
                res++;
        }
    }
    return res;
}

/**************************************************/

bool gameOver(const block& h1,const block& h2,const block& h3,const block& board,bool flag = true){
    //return false;
    if(flag == true){
        if(h1.isLive() && h2.isLive() && h3.isLive()){
            if(h1.inCorect(board) && h2.inCorect(board) && h3.inCorect(board))
                return true;
            else
                return false;
        }

        if(!h1.isLive() && h2.isLive() && h3.isLive())
            if(h2.inCorect(board) &&h3.inCorect(board))
                return true;
            else
                return false;

        if(h1.isLive() && !h2.isLive() && h3.isLive())
            if(h1.inCorect(board) &&h3.inCorect(board))
                return true;
            else
                return false;

        if(h1.isLive() && h2.isLive() && !h3.isLive())
            if(h2.inCorect(board) &&h1.inCorect(board))
                return true;
            else
                return false;

        if(h1.isLive() && !h2.isLive() && !h3.isLive())
            if(h1.inCorect(board))
                return true;
            else
                return false;

        if(!h1.isLive() && h2.isLive() && !h3.isLive())
            if(h2.inCorect(board))
                return true;
            else
                return false;

        if(!h1.isLive() && !h2.isLive() && h3.isLive())
            if(h3.inCorect(board))
                return true;
            else
                return false;
        return false;
    }else{
        if(h1.inCorect(board) == false && h2.inCorect(board) == false && h3.inCorect(board) == false)
            return true;
        else return false;
    }
}

/**************************************************/
