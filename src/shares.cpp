#include"shares.h"

#include<SDL.h>
#include<SDL_image.h>
#include<cstring>

position::position(std::initializer_list<float> list){
    auto it = list.begin();
    x = *it++;
    y = *it++;
};

void LoadImg::loadJPG(const char *file,SDL_Renderer **r,SDL_Surface **s,SDL_Texture **t){
        *s = IMG_LoadJPG_RW(SDL_RWFromFile(file,"rb"));

        *t = SDL_CreateTextureFromSurface(*r,*s);
        SDL_FreeSurface(*s);
        *s = nullptr;
}

void LoadImg::loadPNG(const char *file,SDL_Renderer **r,SDL_Surface **s,SDL_Texture **t){
        *s = IMG_LoadPNG_RW(SDL_RWFromFile(file,"rb"));

        *t = SDL_CreateTextureFromSurface(*r,*s);
        SDL_FreeSurface(*s);
        *s = nullptr;
}

void LoadImg::loadAllIMG(const char *file,SDL_Renderer **r,SDL_Surface **s,SDL_Texture **t){
        size_t len = strlen(file);
        if(file[len-2]=='p') *s = IMG_LoadJPG_RW(SDL_RWFromFile(file,"rb"));
        else if(file[len-2]=='n') *s = IMG_LoadPNG_RW(SDL_RWFromFile(file,"rb"));

        *t = SDL_CreateTextureFromSurface(*r,*s);
        SDL_FreeSurface(*s);
        *s = nullptr;
}