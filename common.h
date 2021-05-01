#pragma once
#include <SDL.h>
#include <string>
const int FPS                                   = 60;
const int DELAY                                 = 1000/FPS;

const int MAX_CASES                             = 31;

const std::string WINDOW_TITLE                  = "Block Puzzle";

const std::string  PATH_BKG                     = "data/img/bkg.jpg";
const std::string  PATH_iCON                    = "data/img/icon.png";
const std::string  PATH_iCON_WINDOW             = "data/img/icon.jpg";

const std::string  PATH_BUTTON                  = "data/img/bt.png";
const std::string  PATH_HOME_BUTTON             = "data/img/home_bt.png";
const std::string  PATH_MUTE_BUTTON             = "data/img/mute.png";
const std::string  PATH_UNMUTE_BUTTON           = "data/img/unMute.png";
const std::string  PATH_MUTEMUSIC_BUTTON        = "data/img/muteMusic.png";
const std::string  PATH_UNMUTEMUSIC_BUTTON      = "data/img/unMuteMusic.png";

const std::string  PATH_GAMEOVER_SCREEN         = "data/img/gameOver.png";
const std::string  PATH_COMFIRM_SCREEN          = "data/img/confirm.png";

const std::string  PATH_FONT                    = "data/font/aachenb.ttf";

const std::string  PATH_BGM                     = "data/mus/bgm1.mp3";          /// nhạc nền
const std::string  PATH_EFFECT_WAV              = "data/mus/effect.wav";        /// âm thanh hiệu ứng

const std::string  PATH_FILE_HIGH_SCORE         = "data/s.scre";

const SDL_Color CYAN_COLOR                      = {  0, 255, 255};
const SDL_Color BLUE_COLOR                      = {  0,   0, 255};
const SDL_Color ORANGE_COLOR                    = {255, 165,   0};
const SDL_Color YELLOW_COLOR                    = {255, 255,   0};
const SDL_Color LIME_COLOR                      = {  0, 255,   0};
const SDL_Color PURPLE_COLOR                    = {128,   0, 128};
const SDL_Color RED_COLOR                       = {255,   0,   0};
const SDL_Color GREEN_COLOR                     = {  0, 128,   0};
const SDL_Color WHITE_COLOR                     = {255, 255, 255};
const SDL_Color BLACK_COLOR                     = {  0,   0,   0};
const SDL_Color LINE_COLOR                      = {115, 136, 193};
const SDL_Color DOAN_COLOR                      = {160, 160, 160};
