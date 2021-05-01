#pragma once
#include <SDL_mixer.h>

typedef struct vocaloid{
    Mix_Music* music;
    Mix_Chunk* effect;
    bool singingMusic,singingEffect;

    void create();
    void begin();

    void sing(void);
    void playEffect(void);

    void loadMus(void);

    void free(void);
}vocaloid;
