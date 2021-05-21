#pragma once
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic {
    class Scientist : public Player {
    private:
        int num_of_cards_to_discover;
    public:
        Scientist(Board& b, City c,  int num) : Player(b, c), num_of_cards_to_discover(num) {
            _role = "Scientist";
        }

        Player& discover_cure(Color c) override;
    };
}