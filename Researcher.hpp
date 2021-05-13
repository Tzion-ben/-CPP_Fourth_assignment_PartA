/**
 * Author: Tzion Beniaminov
 * Since : 2021-04
 */
#pragma once

#include "Player.hpp"

namespace pandemic{

    /*Researcher extends Player*/
    class Researcher : public Player{

        public:
            /*inhereted constractor*/
            Researcher(Board& board, City city);
            
            /*move from current city to the nearest city*/
            virtual Player& drive (City city);

            /*move from the current city to the city of some card in his hand*/
            virtual Player& fly_direct (City city);

            /*move from the current city to some city*/
            virtual Player& fly_charter (City city);

            /*move from the current city to some city iff in current
              city exiset an */
            virtual Player& fly_shuttle (City city);

            /*builds a research station*/
            virtual Player& build ();

            /*discover a new cure for one of the disease*/
            virtual Player& discover_cure (Color color);

            /*decrementing disease stage in the city*/
            virtual Player& treat (City city);

            /*returns the rople of the player*/
            virtual std::string role ();

           /*a player will take a card that belong to a certain city*/
            virtual Player& take_card (City city);

            /*the current location of the player*/
            virtual City GetCity();

           /*all City cards of the plyer*/
            virtual std::set<City> GetCardSets();
    };
}