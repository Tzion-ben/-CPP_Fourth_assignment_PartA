/**
 * Author: Tzion Beniaminov
 * Since : 2021-04
 */

#include "Scientist.hpp"

using namespace std;
using namespace pandemic;

/*using father constractor*/
Scientist:: Scientist (Board& board, City city, int n)
            : Player(board, city), _n_cards_discover_cure(n)
                {}

/*move from current city to the nearest city*/
Player& Scientist::drive (City city){
    return *this;
}

/*move from the current city to the city of some card in his hand*/
Player& Scientist::fly_direct (City city){
    return *this;
}

/*move from the current city to some city*/
Player& Scientist::fly_charter (City city){
    return *this;
}

/*move from the current city to some city iff in current
  city exiset an */
Player& Scientist::fly_shuttle (City city){
    return *this;
}

/*builds a research station*/
Player& Scientist::build (){
    return *this;
}

/*discover a new cure for one of the disease*/
Player& Scientist::discover_cure (Color color){
    return *this;
}

/*decrementing disease stage in the city*/
Player& Scientist::treat (City city){
    return *this;
}

/*returns the rople of the player*/
std::string Scientist::role (){
    return " ";
}

/*a player will take a card that belong to a certain city*/
Player& Scientist::take_card (City city){
    return *this;
}

/*the current location of the player*/
City Scientist::GetCity(){
    return this->_startCity;
}

/*all City cards of the plyer*/
set<City> Scientist::GetCardSets(){
    return this->_playerCards;
}