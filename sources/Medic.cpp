#include "Medic.hpp"
using namespace pandemic;
using namespace std;

Player& Medic::treat(City c){
if(c==_c){
    throw out_of_range("you trying to treat your same city"+city_to_string.at(c));
}
if(_c!=c){
    throw out_of_range("you cant treat in city that you not at");
}
if(_b[c]==0){ //board[honk_kong] = 0
    throw out_of_range("this city is healthy");
}
 _b[c] =0; //when he do treat he remove all the cubes
    return *this;
}
void Medic::treatWithCure() {
    if(_b.cure_exist(colors_of_cities.at(_c))){ //if there is cure in that city
        _b[_c] =0; //i came to city and i see that that we have cure for that city i do remove all the cubes
    }
}