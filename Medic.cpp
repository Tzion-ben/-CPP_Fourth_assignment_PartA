/**
 * Author: Tzion Beniaminov
 * Since : 2021-04
 */

#include "Medic.hpp"

using namespace std;
using namespace pandemic;

/*using father constractor*/
Medic:: Medic (Board& board, City city)
            : Player(board, city)
                {}

/*move from current city to the nearest city*/
Player& Medic::drive (City city){
    return *this;
}

/*move from the current city to the city of some card in his hand*/
Player& Medic::fly_direct (City city){
    return *this;
}

/*move from the current city to some city*/
Player& Medic::fly_charter (City city){
    return *this;
}

/*move from the current city to some city iff in current
  city exiset an */
Player& Medic::fly_shuttle (City city){
    return *this;
}

/*builds a research station*/
Player& Medic::build (){
    return *this;
}

/*discover a new cure for one of the disease*/
Player& Medic::discover_cure (Color color){
    return *this;
}

/*decrementing disease stage in the city*/
Player& Medic::treat (City city){
    return *this;
}

/*returns the rople of the player*/
std::string Medic::role (){
    return " ";
}

/*a player will take a card that belong to a certain city*/
Player& Medic::take_card (City city){
    return *this;
}

/*the current location of the player*/
City Medic::GetCity(){
    return this->_startCity;
}

/*all City cards of the plyer*/
set<City> Medic::GetCardSets(){
    return this->_playerCards;
}
