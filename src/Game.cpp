#include"Game.h"
#include"strdef.h"

Game::Game():m_window(nullptr),m_renderer(nullptr),m_backgroundSurface(nullptr),m_backgroundTexture(nullptr),
            m_log(nullptr),m_state(GameState::START)
{
    m_log = fopen(Log::log,"w");
    if(m_log==nullptr){
        exit(-1);
    }
    IMG_Init(IMG_INIT_JPG|IMG_INIT_PNG);
}

Game::~Game(){
    if(m_window!=nullptr){
        SDL_DestroyWindow(m_window);
    }
    if(m_renderer!=nullptr){
        SDL_DestroyRenderer(m_renderer);
    }
    if(m_backgroundSurface!=nullptr){
        SDL_FreeSurface(m_backgroundSurface);
    }
    if(m_backgroundTexture!=nullptr){
        SDL_DestroyTexture(m_backgroundTexture);
    }
    if(m_log!=nullptr){
        fclose(m_log);
    }
    SDL_Quit();
}

void Game::init(){
    if(SDL_Init(SDL_INIT_VIDEO)<0){
        fprintf(m_log,"Failed to init SDL! Erroe:%s\n",SDL_GetError());
        exit(-1);
    }
    m_backgroundSurface = IMG_LoadPNG_RW(SDL_RWFromFile(Img::landing1,"rb"));

    m_window = SDL_CreateWindow("FightNian",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,
                m_backgroundSurface->w,m_backgroundSurface->h,SDL_WINDOW_SHOWN);

    if(!m_window){
        fprintf(m_log,"Cannot create window! Error: %s\n",SDL_GetError());
        exit(-1);
    }

    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
    if(!m_renderer){
        fprintf(m_log,"Cannot create renderer! Error: %s\n",SDL_GetError());
        exit(-4);
    }
    LoadImg::loadPNG(Img::landing1,&m_renderer,&m_backgroundSurface,&m_backgroundTexture);
}

void Game::render(){
    SDL_SetRenderDrawColor(m_renderer, 0xFF,0xFF,0xFF,0xFF);
    SDL_RenderClear(m_renderer);

    switch (m_state)
    {
    case GameState::START:
        LoadImg::loadPNG(Img::landing1,&m_renderer,&m_backgroundSurface,&m_backgroundTexture);
        break;
    case GameState::END:
        LoadImg::loadPNG(Img::landing2,&m_renderer,&m_backgroundSurface,&m_backgroundTexture);
        break;
    case GameState::RUNNING:
        LoadImg::loadPNG(Img::landing3,&m_renderer,&m_backgroundSurface,&m_backgroundTexture);
        break;
    default:
        break;
    }
    SDL_RenderCopy(m_renderer,m_backgroundTexture, nullptr, nullptr);
    SDL_RenderPresent(m_renderer);
} 

void Game::mainloop(){
    uint32_t begin,end,time,delay;
    SDL_Event event;

    while(true){
        begin = SDL_GetTicks();
        render();
        if(SDL_PollEvent(&event)){
            // key down
            if(event.type == SDL_KEYDOWN){
                // key down
                switch (event.key.keysym.sym)
                {
                    case SDLK_SPACE:
                        // k_space
                        switch(m_state){
                            case GameState::RUNNING:
                                break;
                            default:
                                m_state = GameState::RUNNING;
                                break;
                        }
                        break;
                        // end k_space
                    
                    default:
                        break;
                }
            }// end keydown

            //quit
            if(event.type == SDL_QUIT){
                break;
            }
        }// end SDL_event
        end = SDL_GetTicks();
        time = end-begin;
        delay = FrameTime-time;
        if(delay>0){
            SDL_Delay(delay);
        }
    } // end loop
}

