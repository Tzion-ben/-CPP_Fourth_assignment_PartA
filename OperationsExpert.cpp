/**
 * Author: Tzion Beniaminov
 * Since : 2021-04
 */

#include "OperationsExpert.hpp"

using namespace std;
using namespace pandemic;

/*using father constractor*/
OperationsExpert:: OperationsExpert (Board& board, City city)
            : Player(board, city)
                {}

/*move from current city to the nearest city*/
Player& OperationsExpert::drive (City city){
    return *this;
}

/*move from the current city to the city of some card in his hand*/
Player& OperationsExpert::fly_direct (City city){
    return *this;
}

/*move from the current city to some city*/
Player& OperationsExpert::fly_charter (City city){
    return *this;
}

/*move from the current city to some city iff in current
  city exiset an */
Player& OperationsExpert::fly_shuttle (City city){
    return *this;
}

/*builds a research station*/
Player& OperationsExpert::build (){
    return *this;
}

/*discover a new cure for one of the disease*/
Player& OperationsExpert::discover_cure (Color color){
    return *this;
}

/*decrementing disease stage in the city*/
Player& OperationsExpert::treat (City city){
    return *this;
}

/*returns the rople of the player*/
std::string OperationsExpert::role (){
    return " ";
}

/*a player will take a card that belong to a certain city*/
Player& OperationsExpert::take_card (City city){
    return *this;
}

/*the current location of the player*/
City OperationsExpert::GetCity(){
    return this->_startCity;
}

/*all City cards of the plyer*/
set<City> OperationsExpert::GetCardSets(){
    return this->_playerCards;
}
