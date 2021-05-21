#include "Dispatcher.hpp"
using namespace pandemic;
using namespace std;
//if he in research station he can make fly_direct ot any town without droping no cards
Player& Dispatcher::fly_direct(City c){
    if(_c==c){
        throw out_of_range("you"+role()+"trying to fly from "+city_to_string.at(_c)+"to"+city_to_string.at(_c));
    }

    //asking if curr station is research station
if(_b.is_research_station(_c)){ //if iam in research station i can fly direct w/e i want
    _c = c;
    return *this;

}
//if hes not in research station he wont lose hes card that player function will ajastify it
    return Player::fly_direct(c);
}