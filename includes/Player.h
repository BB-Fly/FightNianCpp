#ifndef GUARD_Player_h
#define GUARD_Player_h

#include <SDL.h>
#include "shares.h"

class Player
{
public:
protected:
    position pos;
    float speed;
    uint16_t last_shot_time;
    uint16_t shot_gap_time;

};


#endif //guard