#pragma once
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic{
    class Virologist:public Player{
    public:
        Virologist(Board& b, City c):Player(b,c){
            _role = "Virologist";
        }
        Player& treat(City c) override;
    };
}