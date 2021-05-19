#include "Player.hpp"

using namespace pandemic;
using namespace std;
//& for lesharsher kriot
Player& Player::drive(City c){ //this is initilized already in corrent map
if(c==_c){
    throw out_of_range("you"+role()+"trying to drive from your city to your city"+city_to_string.at(c));
}
    auto k = neighbors.at(_c).find(c);
    auto end = neighbors.at(_c).end();
    if(k==end){//<current city ,given city> trying to find are they neighbors?
        //"these cities arent neighbors so you cant drive look at the char to find neighbos "
        throw out_of_range("YourCity = "+city_to_string.at(_c)+" ->drive to ->"+city_to_string.at(c)+" ,character = "+role() + " ,not Connected");
    }
    else
    {
        _c = c; //else just to move to this city
    }
    return *this;
}

Player& Player::fly_direct(City c){
    //auto k = neighbors.at(_c).find(c);
    //auto end = neighbors.at(_c).end();
    if(_c==c){ //trying to fly from same city to same city user want to fly to somewhere where he doesnt has a card for that city
        //"you cant fly from same city to same city"
        throw out_of_range("YourCity = "+city_to_string.at(_c)+" ->drive to ->"+city_to_string.at(c)+" ,character = "+role() + " ,same city");
    }
    //when you dont have the card when you want to fly to that city
    if(cards.find(c) == cards.end()){ //iterator is trying to find card and card.end() its like null for pointers
        //"you dont have that city your hands ,you may only fly to city if you have the card"
        throw out_of_range("you dont have "+city_to_string.at((c))+"in your hands ,"+"player "+role());

    }
    else {
        cards.erase(c);
        _c = c; //we made the direct fly
    }
    return *this;
}

Player& Player::fly_charter(City c){
    auto f= cards.find(_c); //not sure if it takes cast of *
    auto t = cards.end();
    if(_c==c){
        //"you cannot fly from same city to same city"
        throw out_of_range("your cant fly from"+city_to_string.at(c)+"to"+city_to_string.at(c)+"same city role()="+role());
    }
    if(f==t){
        //"you cannot fly from same city to same city"
        throw out_of_range("you dont have that card"+city_to_string.at(c)+"in your hands, "+role());
    }
    else
    {
        _c=c;
        cards.erase(_c);
    }
    return  *this;
}

Player& Player::fly_shuttle(City c){ //if in the current station ther is station it is possible to fly to evry other same station
    if(_c==c){
        throw out_of_range("you trying to fly from"+city_to_string.at(c)+"to"+city_to_string.at(c)+"role="+role());
    }
    //if in current city there is research station we might fly to everyvere where we have research station
    auto k = _b.is_research_station(c);//im esh bair hanohahit tahanat mihkar,haim gam be shnia
    cout<<k<<endl;
    //auto d = _b.is_research_stations.end();
    auto kk = _b.is_research_station(_c); //by this functions we can acces private members to
    cout<<kk<<endl;
    //this city and other city has tahanat mihkar
    if(k && kk){ //k = true ,kk=false if(k==false or kk==false)
        //"ok you have research station but where you trying to fly dont"
        _c=c;
    }
    // if(!k && kk){
    //     //"you dont have research station other city do, still not legal"
    //     throw out_of_range("you ="+role()+"trying to fly to "+city_to_string.at(c)+"you dont have rstation");
    // }
    else //evrything is cool we flying to that city my city and other city has research station
    {
        throw out_of_range("you"+role()+" tryin to fly from="+city_to_string.at(_c)+"->"+city_to_string.at(c)+"no research station");
        
    }


    return *this;
}
//if the player doesnt have current town card we throw exception exept one kind of job
Player& Player::build(){ //zarih gam livdok she esh li et hklaf be ir nohehit?
    auto f = cards.find(_c);
    auto  p = cards.end();
    if(_b.is_research_station(_c)){ //yaholiot esh po kvar tahanat mihkar
        return *this;
    }

    if(f==p){
        //"you dont have current town card so you cant build"
        throw out_of_range("you="+role()+"at"+city_to_string.at(_c)+"dont have curr town card");
    }
    cards.erase(_c);
    _b.make_research_station(_c);

    return *this;
}
//we need 5 cards of color cure we want and it has to be station
Player& Player::discover_cure(Color c){ //finding cure for some color of deasease
    bool b = _b.is_research_station(_c); //if true we in reseach station city
    if(!b){
        throw out_of_range("city="+city_to_string.at(_c)+ "dont have research station");
    }
    else if(cards.size()<total_numofcards) {//our amount of cards is less then 5
        throw out_of_range("you"+role()+ "dont have 5 cards at at all");
    }
    else if(b ){//we in research station ,iterator ze pointer she raz li unordered set
        unordered_set<City> temp;
        int caunt = 0;
        for ( auto it = cards.begin(); it != cards.end(); ++it ){ //i dont have acces to color of the city
            auto city = *it; //it holds city types
            if(colors_of_cities.at(city)==c){ //we got the color
                caunt++;
                temp.insert(city);//we temporarly getting the city we going to delete it after
            }
        }
        if(caunt<total_numofcards){ //if i have 5 cards of that colour we are ok
            throw out_of_range("you"+role()+" dont have enougth "+color_to_string.at(c)+ " you want to cure cards");
        }
        else //now we droping does cards from hand
        {
            //checking what cards i need to delete
            //po zarih letaken
            //i assueme that temp<cards
            auto p = cards.begin(); //pointing to start of p
            auto l = cards.end();
            //we will find the value in cards and ersase it
                for(auto k = temp.begin();k!=temp.end();k++){
                    p=cards.find(*k); // we searching in original cards

                    if(p!=l){ //nimhak bemida ve shavim be mida ve mazanu
                        cards.erase(*k);
                    }
                }
            }
            _b.insert_cure(c); //succesfully added the cure we got the 5 cards
        }

    return *this;
    }



//we have to be in that city to treat?
//board[City::Kinshasa] = 3 for example
Player& Player::treat(City c){
    if(_c!=c){
        throw out_of_range("you are not in that city that you want to cure,first you need to go there");
    }
        //now if the cure is found we setting board[city]=0
    else if(_b.cure_exist(colors_of_cities.at(c))){ // we referencing to colors_of_cities<City,colour> that in board.hpp
        _b[c] = 0;
    }
    else if(_b[c]>0){
        _b[c]--;
    }
    else if(_b[c]==0){
        throw out_of_range("there is 0 zero desease in this city");
    }
    else
    {
        throw out_of_range("this city has 0 cubes in it");
    }
    return *this;
}
//if we taking card that already exist in hands of player nothing happens
Player& Player::take_card(City c){
    cards.insert(c);
    return *this;
}

string Player::role(){ //every character has it own role so its ok to virtual it
    return _role;
}
void Player::remove_card() {cards.clear();} //method for checkerers