/**
 * Author: Tzion Beniaminov
 * Since : 2021-04
 */
#pragma once

#include <iostream>
#include<map>
#include "City.hpp"
#include "Color.hpp"


namespace pandemic {
    class Board{

        private:
            int* _citiesList;
            int* _citiesDiseasesStage;
            bool* _citiesResearchStations;

            /*copt all the values, helps to create a copy constractor */
            void copyValues(const int* citiesList, const int* citiesDiseasesStage,const bool* citiesResearchStations);

        public:
            /*default empty constractor, will create an array of integers
            for every enum City, array of bool , false if num have a research station
            in coresponding city , true if there is*/
            Board();
            // Board(const Board& bord);/*copy constractor*/
            
            /*Distractor*/
            ~Board();

            /*returns true if all the board is empty*/
            bool is_clean();

            /****** IMPLEMENTED ONLY for tests ******/
            /*cleaning all the curesthat was found  */
            void remove_cures ();


            /******** operators overloading ********/
            /***************************************/
            
            // Board& operator=(const Board& Bboard);

            /*[] oerator : only get the value at specific index*/
            const int operator[](City city) const;

            /*[] oerator : acn get and set the value at specific index*/
            int& operator[](City city);

            /*return an output of the Board*/
            friend std::ostream& operator<<(std::ostream& output, const Board& b);

            /**get the arry that contains ehre is a research stations*/
            bool * const GetCitiesResearchStations();
    };
}