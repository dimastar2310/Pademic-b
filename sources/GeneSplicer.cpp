#include "GeneSplicer.hpp"
using namespace pandemic;
using namespace std;

Player& GeneSplicer::discover_cure(Color c){ //we will go to player function and set does fields because we inherting does fields
    //can make discover_cure with any 5 cards
    if(!_b.is_research_station(_c)){
        throw out_of_range("you are = "+role() + "not in the research station");
    }
    int k = total_numofcards; //5
    //yaholiot esh kvar trufa le mahala
    if(_b.cure_exist(c)){ //if we have the cure we dont need to discover it
        //but we have to be in city of research station
        return *this;
    }
    else if(cards.size()>=total_numofcards){ //lets discovere it
        
        auto k = cards.end();
        for (auto p = cards.begin();  p!=k; p++) {
            cards.erase(*p); //erasing by iterator position
        }
       _b.insert_cure(c); // discovring new cure
    }
    else
    {
        throw out_of_range("you = "+role()+" dont have enough cards");
    }
    return *this;
}
