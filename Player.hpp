/**
 * Author: Tzion Beniaminov
 * Since : 2021-04
 */
#pragma once

#include "Color.hpp"
#include "Board.hpp"
#include <set>

// #include <map>

namespace pandemic {
    class Player {

        protected:
          Board& _board;
          City _startCity; 
          std::set <City> _playerCards; 

        public:

            /*a generic constractor*/
            Player (Board &board, City city);

            virtual ~Player();
            /******** Abstract Methods ********/
            /******** will implenemted in "child" class ********/

            /*move from current city to the nearest city*/
            virtual Player& drive (City city) = 0;

            /*move from the current city to the city of some card in his hand*/
            virtual Player& fly_direct (City city) = 0;

            /*move from the current city to some city*/
            virtual Player& fly_charter (City city) = 0;

            /*move from the current city to some city iff in current
              city exiset an */
            virtual Player& fly_shuttle (City city) =0;

            /*builds a research station*/
            virtual Player& build () = 0;

            /*discover a new cure for one of the disease*/
            virtual Player& discover_cure (Color color) = 0;

            /*decrementing disease stage in the city*/
            virtual Player& treat (City city) = 0;

            /*returns the rople of the player*/
            virtual std::string role () = 0;

            /*a player will take a card that belong to a certain city*/
            virtual Player& take_card (City city) = 0;

            /*the current location of the player*/
            virtual City GetCity() = 0;

            /*the current location of the player*/
            virtual std::set<City> GetCardSets() = 0;
    };
} 
