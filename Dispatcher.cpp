/**
 * Author: Tzion Beniaminov
 * Since : 2021-04
 */

#include "Dispatcher.hpp"

using namespace std;
using namespace pandemic;

/*using father constractor*/
Dispatcher:: Dispatcher (Board& board, City city)
            : Player(board, city)
                {}

/*move from current city to the nearest city*/
Player& Dispatcher::drive (City city){
    return *this;
}

/*move from the current city to the city of some card in his hand*/
Player& Dispatcher::fly_direct (City city){
    return *this;
}

/*move from the current city to some city*/
Player& Dispatcher::fly_charter (City city){
    return *this;
}

/*move from the current city to some city iff in current
  city exiset an */
Player& Dispatcher::fly_shuttle (City city){
    return *this;
}

/*builds a research station*/
Player& Dispatcher::build (){
    return *this;
}

/*discover a new cure for one of the disease*/
Player& Dispatcher::discover_cure (Color color){
    return *this;
}

/*decrementing disease stage in the city*/
Player& Dispatcher::treat (City city){
    return *this;
}

/*returns the rople of the player*/
std::string Dispatcher::role (){
    return " ";
}

/*a player will take a card that belong to a certain city*/
Player& Dispatcher::take_card (City city){
    return *this;
}

/*the current location of the player*/
City Dispatcher::GetCity(){
    return this->_startCity;
}

/*all City cards of the plyer*/
set<City> Dispatcher::GetCardSets(){
    return this->_playerCards;
}
