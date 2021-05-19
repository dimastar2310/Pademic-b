#include "Scientist.hpp"
using namespace pandemic;
using namespace std;
//with n cards only but we must see if we have 3 not(5) cards in that color <city,color>
Player& Scientist::discover_cure(Color c){ //nivdok mikrei kaze be mida ve niztareh im ein li maspik klafim beaya
    if(_b.cure_exist(c)){ //we already got this cure
        return *this;
    }
    int k = num_of_cards_to_discover;
    
    auto s = cards.end();
    //we need to make dicover cure too
    //we need that there will be research station in current city
    if(_b.is_research_station(_c)) { //yes iam in research station
        for (auto p = cards.begin(); p != s && num_of_cards_to_discover < cards.size() && k ; p++) {
            if (colors_of_cities.at(*p) == c) { //<City,color>
                cards.erase(*p); //nimhak et haklaf
                k--;

            }
        }
    }
    if(k==0){ //azai beezrat 0 klafim negale o she avrnu tnai rishon
        _b.insert_cure(c); //gilinu et hatrufa [V]
    }
    if(num_of_cards_to_discover>cards.size()){
        out_of_range("you want to erase with too many cards");
    }
    return *this;
}
