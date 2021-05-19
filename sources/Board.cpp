
#include "Board.hpp"
using namespace pandemic;
using namespace std;


int& Board::operator[](City c){
    return disease_rate[c];
}

bool Board::is_clean(){
    for(auto& pair : disease_rate){
        if(pair.second > 0){
            return false;
        }
    }
    return true;
}

void Board::remove_cures(){ //moridim mihaluah et kol kubiot mahala for checkers
    cures.clear();
}
//be mekor rozim lishol haim hair hanohahit tahanat mihkar
bool Board::is_research_station(City c) { //shoalim haim anu be tahanat mihkar
     if(research_stations.find(c)==research_stations.end()){ //we dont have that research station
         return false;
     }
    return true;
}
void  Board::make_research_station(City c) {
    
        research_stations.insert(c); //nivne ahat
        
    }

void  Board::insert_cure(Color c) {
    cures.insert(c);
}
bool Board::cure_exist(Color c) {
    auto p = cures.find(c);
    auto d = cures.end();
    if(p!=d){
        return  true;
    }
    else
    {
        return false;
    }
}
ostream& pandemic::operator<<(ostream& out, const Board& b){
    out<<" "<<endl;
    return out;
}