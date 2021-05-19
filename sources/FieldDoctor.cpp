#include "FieldDoctor.hpp"
using namespace pandemic;
using namespace std;

Player& FieldDoctor::treat(City c){
    if(_c == c){
        throw out_of_range("city ="+city_to_string.at(c)+"is same city");
    }
    if(neighbors.at(_c).find(c)!=neighbors.at(_c).end()) { //we need them to be neighbos
    throw out_of_range("curr city = "+city_to_string.at(c)+"other city"+city_to_string.at(_c)+"not connected");
    }


        if (_b.cure_exist( colors_of_cities.at(c))) { // we referencing to colors_of_cities<City,colour> that in board.hpp
            _b[c] = 0;
        } else if (_b[c] > 0) {
            _b[c]--;
        } else if (_b[c] == 0) {
            throw out_of_range("there is 0 zero desease in="+city_to_string.at(c));
       
        }
    return *this;
}