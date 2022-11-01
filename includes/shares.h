#ifndef GUARD_shares_h
#define GUARD_shares_h

#include<initializer_list>
#include<SDL.h>
#include<SDL_image.h>

struct position
{
    float x,y;
    position(float i, float j):x(i),y(j){};
    position():position(0.0,0.0){};
    position(std::initializer_list<float> lists);

};

namespace LoadImg
{
void loadJPG(const char *file,SDL_Renderer **r,SDL_Surface **s,SDL_Texture **t);
void loadPNG(const char *file,SDL_Renderer **r,SDL_Surface **s,SDL_Texture **t);
void loadAllIMG(const char *file,SDL_Renderer **r,SDL_Surface **s,SDL_Texture **t);
}


#endif //guard