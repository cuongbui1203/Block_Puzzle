#pragma once
#include "init.h"
#include "block.h"
#include "game.h"
#include <fstream>

void play(Game&);

luachon home(Game&);

luachon cho(Game&);

bool gameOver(Game&,const int&,const int&);

bool confirm(Game&);

void create(block&,block&);

int count(int*,const int&,const int&);

bool gameOver(const block&,const block&,const block&,const block&,bool);
