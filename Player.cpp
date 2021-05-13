/**
 * Author: Tzion Beniaminov
 * Since : 2021-04
 */

#include "Player.hpp"
#include <time.h>

const int MAX_CITIES_NUM = 48;

using namespace std;
using namespace pandemic;

/*ALL the others methods is asbstract*/
Player:: Player (Board& board , City city)
         :_board(board), _startCity(city)
         {
            // /*init set of cards for the player in the start of the game*/
            // int rand_City_card;
            // srand (time(NULL));/*initialize random generator*/
            // /* generate number between 0 and 47 for each City enum*/
            // rand_City_card = rand() % MAX_CITIES_NUM;
            // City city_card = static_cast<City>(rand_City_card);
            // _playerCards.insert(city_card);
         }
         Player::~Player(){}