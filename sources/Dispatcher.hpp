#pragma once
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic {
    class Dispatcher : public Player {
    public:
        Dispatcher(Board &b, City c) : Player(b, c)  {
            _role = "Dispatcher";
        }

        Player &fly_direct(City c) override;
    };
}