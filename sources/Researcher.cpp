#include "Researcher.hpp"
using namespace pandemic;
using namespace std;

Player& Researcher::discover_cure(Color c){ //le hayav liot be tahanat mihkar
    if(_b.cure_exist(c)){ //we already got this cure
        return *this;
    }

    
    auto s = cards.end();
    auto k = total_numofcards; //we need 5 cards to discover
    //we need to make dicover cure too
    //we need that there will be research station in current city
     //dont have to be  in research station
     if(cards.size()<total_numofcards){
         throw out_of_range("cant do it");
     }

     int caunter = 0;
     unordered_set<City> temp;
        for (auto p = cards.begin(); p != s && k; p++) {
            if (colors_of_cities.at(*p) == c) { //<City,color>
            temp.insert(*p);
                //cards.erase(*p); //nimhak et haklaf
            k--; //mokodem k haya kama she rozim le scientist
            if(k==0){
                break;
            }
            }
        }
        if(k!=0){
            throw out_of_range("dont have 5 color cards");
        }
        
        for (auto p = temp.begin(); p!=temp.end(); p++)
        {
           cards.erase(*p);
        }
        
        

    
        _b.insert_cure(c); //gilinu et hatrufa [V]
    


    return *this;
}
