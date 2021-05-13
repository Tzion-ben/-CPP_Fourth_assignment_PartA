/**
 * Author: Tzion Beniaminov
 * Since : 2021-04
 */

#include "GeneSplicer.hpp"

using namespace std;
using namespace pandemic;

/*using father constractor*/
GeneSplicer:: GeneSplicer (Board& board, City city)
            : Player(board, city)
                {}

/*move from current city to the nearest city*/
Player& GeneSplicer::drive (City city){
    return *this;
}

/*move from the current city to the city of some card in his hand*/
Player& GeneSplicer::fly_direct (City city){
    return *this;
}

/*move from the current city to some city*/
Player& GeneSplicer::fly_charter (City city){
    return *this;
}

/*move from the current city to some city iff in current
  city exiset an */
Player& GeneSplicer::fly_shuttle (City city){
    return *this;
}

/*builds a research station*/
Player& GeneSplicer::build (){
    return *this;
}

/*discover a new cure for one of the disease*/
Player& GeneSplicer::discover_cure (Color color){
    return *this;
}

/*decrementing disease stage in the city*/
Player& GeneSplicer::treat (City city){
    return *this;
}

/*returns the rople of the player*/
std::string GeneSplicer::role (){
    return " ";
}

/*a player will take a card that belong to a certain city*/
Player& GeneSplicer::take_card (City city){
    return *this;
}

/*the current location of the player*/
City GeneSplicer::GetCity(){
    return this->_startCity;
}

/*all City cards of the plyer*/
set<City> GeneSplicer::GetCardSets(){
    return this->_playerCards;
}