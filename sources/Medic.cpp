#include "Medic.hpp"
using namespace pandemic;
using namespace std;

Player& Medic::treat(City c){
// if(c==_c){
//     throw out_of_range("you trying to treat your same city"+city_to_string.at(c));
// }
if(_c!=c){
    throw out_of_range("you cant treat in city that you not at");
}
if(_b[c]==0){ //board[honk_kong] = 0
    throw out_of_range("this city is healthy");
}
 _b[c] =0; //when he do treat he remove all the cubes
    return *this;
}
//Player::fly_direct(c);
Player& Medic::drive(City c){
    Player::drive(c);
    if(_b.cure_exist(colors_of_cities.at(c))){
        _b[c] =0; 
    }
return *this;

}
Player& Medic::fly_charter(City c){
    Player::fly_charter(c);
    if(_b.cure_exist(colors_of_cities.at(c))){
        _b[c] =0; 
    }
return *this;
}
Player& Medic::fly_direct (City c){
    Player::fly_direct(c);
    if(_b.cure_exist(colors_of_cities.at(c))){
        _b[c] =0; 
    }
return *this;
}
Player& Medic::fly_shuttle(City c){//
    Player::fly_shuttle(c);
    if(_b.cure_exist(colors_of_cities.at(c))){
        _b[c] =0; 
    }
return *this;
}