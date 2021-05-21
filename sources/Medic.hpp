#pragma once
#include "Player.hpp"
#include "Board.hpp"
namespace pandemic {

    class Medic : public Player {
    public:
        Medic(Board& b, City c) : Player(b, c) {
            _role = "Medic";
        }

        Player& treat(City c) override;
          virtual Player&  drive(City c) override;
          virtual Player& fly_direct(City c) override;
          virtual Player& fly_charter(City c) override;
           virtual Player&  fly_shuttle(City c) override;
    };
}