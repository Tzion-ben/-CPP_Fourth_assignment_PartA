/**
 * Author: Tzion Beniaminov
 * Since : 2021-04
 */ 

#include "Board.hpp"
#include <iostream>
const int MAX_CITIES_NUM = 48;


using namespace std;
using namespace pandemic;

    /*default constractor*/
    Board::Board(){
        _citiesList = new int [MAX_CITIES_NUM];
        _citiesDiseasesStage = new int [MAX_CITIES_NUM];
        _citiesResearchStations = new bool [MAX_CITIES_NUM];
    }

    // /*implementaion copy constactor*/
    // Board::Board(const Board& board)
    //     :_citiesList(new int[MAX_CITIES_NUM]), _citiesDiseasesStage(new int[MAX_CITIES_NUM]),
    //     _citiesResearchStations(new bool[MAX_CITIES_NUM])
    // {
    //     copyValues(board._citiesList, board._citiesDiseasesStage,board._citiesResearchStations);
    // }

    /*private method*/
    /*copt all the values, helps to create a copy constractor */
    void Board::copyValues(const int* citiesList, const int* citiesDiseasesStage,
            const bool* citiesResearchStations){
        for(int i=0 ; i < MAX_CITIES_NUM ; i++){
            _citiesList[i] = citiesList[i];
            _citiesDiseasesStage[i] = citiesDiseasesStage[i];
            _citiesResearchStations[i] = citiesResearchStations[i];
        }
    }

    /*Distractor*/
    Board::~Board(){
        delete[] _citiesList;
        delete[] _citiesDiseasesStage;
        delete[] _citiesResearchStations;
    }

    /*returns true if all the board is empty*/
    bool Board::is_clean(){
        
        return false;
    }

    /*** IMPLEMENTED ONLY for tests***/
    /*cleaning all the cures that was found  */
    void Board::remove_cures (){

    }

    /******** operators overloading ********/
    /***************************************/
    /*[] oerator : only get the value at specific index*/
    const int pandemic::Board::operator[](City city) const{
        return _citiesList[1]; 
    }

    /*[] oerator : acn get and set the value at specific index*/
    int&  Board::operator[](City city){
        return _citiesList[0];
    }

    // // set a specific element in this _citiesList to value
    // void Board::operator=(int value){
    //     _citiesList[value]
    // }

    /*return an output of the Board*/
    ostream& pandemic::operator<< (ostream& output, const Board& b){
        for(int i =0 ;i<MAX_CITIES_NUM ; i++){
            output << "index " << i << ":" << b._citiesList[i] << "\n";
        }
        return output;
    }

    bool* const Board::GetCitiesResearchStations(){
        return _citiesResearchStations;
    }
