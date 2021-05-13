/**
 * Author: Tzion Beniaminov
 * Since : 2021-04
 */

#include "FieldDoctor.hpp"

using namespace std;
using namespace pandemic;

/*using father constractor*/
FieldDoctor:: FieldDoctor (Board& board, City city)
            : Player(board, city)
                {}

/*move from current city to the nearest city*/
Player& FieldDoctor::drive (City city){
    return *this;
}

/*move from the current city to the city of some card in his hand*/
Player& FieldDoctor::fly_direct (City city){
    return *this;
}

/*move from the current city to some city*/
Player& FieldDoctor::fly_charter (City city){
    return *this;
}

/*move from the current city to some city iff in current
  city exiset an */
Player& FieldDoctor::fly_shuttle (City city){
    return *this;
}

/*builds a research station*/
Player& FieldDoctor::build (){
    return *this;
}

/*discover a new cure for one of the disease*/
Player& FieldDoctor::discover_cure (Color color){
    return *this;
}

/*decrementing disease stage in the city*/
Player& FieldDoctor::treat (City city){
    return *this;
}

/*returns the rople of the player*/
std::string FieldDoctor::role (){
    return " ";
}

/*a player will take a card that belong to a certain city*/
Player& FieldDoctor::take_card (City city){
    return *this;
}

/*the current location of the player*/
City FieldDoctor::GetCity(){
    return this->_startCity;
}

/*all City cards of the plyer*/
set<City> FieldDoctor::GetCardSets(){
    return this->_playerCards;
}