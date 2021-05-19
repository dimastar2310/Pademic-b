#include "Virologist.hpp"
using namespace pandemic;
using namespace std;

Player& Virologist::treat(City c){
    //c=_c can do all other stuff that regular player can do
    if(_c!=c){ //my city and other are different so...
        if(_b[c]==0){
            throw out_of_range("nothing to cure in that city its healthy");
        }
        if(cards.find(c)==cards.end()){
            throw out_of_range("you dont have that card the you want to treat");
        }
        if(_b.cure_exist(colors_of_cities.at(c))){ //that city has cure and now is my task
            //from father we can off all the cubes
            _b[c] =0;
        }
        //we dont have the cure for that city so we gonna just remove 1
        else if(_b[c]>0) {

            _b[c]--;
        }

    }
    return *this; //
}