#include "OperationsExpert.hpp"
using namespace pandemic;
using namespace std;
//can build research station w/e he want without droping the card of the city he in
Player& OperationsExpert::build(){ //lets do some overiding
   // Player::build();//ze amur leahzir li reference
    _b.make_research_station(_c);

    return *this;
}