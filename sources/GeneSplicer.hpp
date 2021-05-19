#pragma once
#include "Player.hpp"
#include "Board.hpp"

using namespace pandemic;

class GeneSplicer:public Player{
public:
    GeneSplicer(Board b, City c):Player(b,c,"GeneSplicer"){} //initializing father inherating its fields so its ok
    Player&  discover_cure(Color c);
};
