#pragma once
#include "Player.hpp"
#include "Board.hpp"
namespace pandemic {

    class Medic : public Player {
    public:
        Medic(Board b, City c) : Player(b, c, "Medic") {}

        Player& treat(City c) override;
        void treatWithCure();
    };
}