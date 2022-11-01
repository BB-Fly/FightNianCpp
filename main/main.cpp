#include "game.h"

int Main(int argc, char* argv[]){
    Game game;
    game.init();
    game.mainloop();
    return 0; 
}