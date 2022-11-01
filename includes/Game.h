#ifndef GUARD_Game_h
#define GUARD_Game_h

#include<SDL.h>
#include<SDL_image.h>
#include<stdlib.h>
#include<stdio.h>
#include<stdexcept>
#include"shares.h"
#include"strdef.h"

#ifdef __WIN
#define Main SDL_main
#endif

#ifndef __WIN
#define Main main
#endif

enum GameState
{
    START,
    RUNNING,
    END
};

static constexpr uint32_t FrameRate = 50;
static constexpr uint32_t FrameTime = 1000/FrameRate;

class Game
{
public:
    Game();
    ~Game();
    void init();
    void mainloop();
    void render();

protected:
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;
    SDL_Surface *m_backgroundSurface;
    SDL_Texture *m_backgroundTexture;

    FILE *m_log;
    GameState m_state;
};


#endif //guard