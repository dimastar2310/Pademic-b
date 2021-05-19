#include "Dispatcher.hpp"
using namespace pandemic;
using namespace std;
//if he in research station he can make fly_direct ot any town without droping no cards
Player& Dispatcher::fly_direct(City c){

    //asking if curr station is research station
if(_b.is_research_station(_c)){ //if iam in research station i can fly direct w/e i want
    _c = c;
    return *this;

}
//if hes not in research station he wont lose hes card that player function will ajastify it
    return Player::fly_direct(c);
}