/**
 * Author: Tzion Beniaminov
 * Since : 2021-04
 */

#include "Virologist.hpp"

using namespace std;
using namespace pandemic;

/*using father constractor*/
Virologist:: Virologist (Board& board, City city)
            : Player(board, city)
                {}

/*move from current city to the nearest city*/
Player& Virologist::drive (City city){
    return *this;
}

/*move from the current city to the city of some card in his hand*/
Player& Virologist::fly_direct (City city){
    return *this;
}

/*move from the current city to some city*/
Player& Virologist::fly_charter (City city){
    return *this;
}

/*move from the current city to some city iff in current
  city exiset an */
Player& Virologist::fly_shuttle (City city){
    return *this;
}

/*builds a research station*/
Player& Virologist::build (){
    return *this;
}

/*discover a new cure for one of the disease*/
Player& Virologist::discover_cure (Color color){
    return *this;
}

/*decrementing disease stage in the city*/
Player& Virologist::treat (City city){
    return *this;
}

/*returns the rople of the player*/
std::string Virologist::role (){
    return " ";
}

/*a player will take a card that belong to a certain city*/
Player& Virologist::take_card (City city){
    return *this;
}

/*the current location of the player*/
City Virologist::GetCity(){
    return this->_startCity;
}

/*all City cards of the plyer*/
set<City> Virologist::GetCardSets(){
    return this->_playerCards;
}