#include "Researcher.hpp"
using namespace pandemic;
using namespace std;

Player& Researcher::discover_cure(Color c){
    if(_b.cure_exist(c)){ //we already got this cure
        return *this;
    }

    
    auto s = cards.end();
    auto k = total_numofcards; //we need 5 cards to diskover
    //we need to make dicover cure too
    //we need that there will be research station in current city
     //dont have to be  in research station
        for (auto p = cards.begin(); p != s && k; p++) {
            if (colors_of_cities.at(*p) == c) { //<City,color>
                cards.erase(*p); //nimhak et haklaf
            k--; //mokodem k haya kama she rozim le scientist

            }
        }

    if(k==0){ //azai beezrat 0 klafim negale o she avrnu tnai rishon
        _b.insert_cure(c); //gilinu et hatrufa [V]
    }


    return *this;
}
