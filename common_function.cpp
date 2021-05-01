#include "common_function.h"

void setColorRenderer(SDL_Renderer*& renderer,const SDL_Color &color){
    SDL_SetRenderDrawColor(renderer,color.r,color.g,color.b,color.a);
}

void delay(Uint32& frameStart){
    Uint32 frameTime;

	frameTime = SDL_GetTicks() - frameStart;
	//std::cout<<frameStart<<' '<<frameTime<<'\n';
    if (frameTime < DELAY)
    {
        SDL_Delay(DELAY - frameTime);
    }
}

void showScreen(SDL_Window*& window,SDL_Renderer*& renderer){
    ///Khi thông thường chạy với môi trường bình thường ở nhà
    SDL_RenderPresent(renderer);
    ///Khi chạy ở máy thực hành WinXP ở trường (máy ảo)
    //SDL_UpdateWindowSurface(window);
}


int random(int minN, int maxN){
    return minN + rand() % (maxN + 1 - minN);
}


int posInArr(const int& r,const int& c,const int& colOfArr){
    return (r*colOfArr) + c;
}

int getRandomColor(void){
    return random(1,8);
}
