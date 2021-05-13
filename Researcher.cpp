/**
 * Author: Tzion Beniaminov
 * Since : 2021-04
 */

#include "Researcher.hpp"

using namespace std;
using namespace pandemic;

/*using father constractor*/
Researcher:: Researcher (Board& board, City city)
            : Player(board, city)
                {}

/*move from current city to the nearest city*/
Player& Researcher::drive (City city){
    return *this;
}

/*move from the current city to the city of some card in his hand*/
Player& Researcher::fly_direct (City city){
    return *this;
}

/*move from the current city to some city*/
Player& Researcher::fly_charter (City city){
    return *this;
}

/*move from the current city to some city iff in current
  city exiset an */
Player& Researcher::fly_shuttle (City city){
    return *this;
}

/*builds a research station*/
Player& Researcher::build (){
    return *this;
}

/*discover a new cure for one of the disease*/
Player& Researcher::discover_cure (Color color){
    return *this;
}

/*decrementing disease stage in the city*/
Player& Researcher::treat (City city){
    return *this;
}

/*returns the rople of the player*/
std::string Researcher::role (){
    return " ";
}

/*a player will take a card that belong to a certain city*/
Player& Researcher::take_card (City city){
    return *this;
}

/*the current location of the player*/
City Researcher::GetCity(){
    return this->_startCity;
}

/*all City cards of the plyer*/
set<City> Researcher::GetCardSets(){
    return this->_playerCards;
}
