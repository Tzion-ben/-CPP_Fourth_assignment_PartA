/**
 * Author: Tzion Beniaminov
 * Since : 2021-04
 */

#include "doctest.h"
#include <vector>
#include <map>
#include <iostream>
#include <stdexcept>
#include <time.h>

#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"

#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"

using namespace std;
using namespace pandemic;

const int MAX_CITIES_NUM = 48;
const int MAX_DISEASE_STAGE = 4;

/*conatain all the lienks betwien tha cities*/
map<City,vector<City>> conections;
/*for every city we have a dufferent color, one fron the 4 :Black, Blue, Yellow, Red*/
map<Color,vector<City>>  diseases;

/*returns the coresponding n City enum depend ona given integer*/
City convert_INTvalue_to_enum(int randCity){

    // DEBUG
    // cout << "in functions to test" << randCity << endl;
    if(randCity == 0){return City::Algiers;}
    if(randCity == 1){return City::Madrid;}
    if(randCity == 2){return City::Paris;}
    if(randCity == 3){return City::Istanbul;}
    if(randCity == 4){return City::Cairo;}
    if(randCity == 5){return City::Atlanta;}
    if(randCity == 7){return City::Chicago;}
    if(randCity == 6){return City::Miami;}
    if(randCity == 8){return City::Washington;}
    if(randCity == 9){return City::Baghdad;}
    if(randCity == 10){return City::Tehran;}
    if(randCity == 11){return City::Riyadh;}
    if(randCity == 12){return City::Karachi;}
    if(randCity == 13){return City::Bangkok;}
    if(randCity == 14){return City::Kolkata;}
    if(randCity == 15){return City::Chennai;}
    if(randCity == 16){return City::Jakarta;}
    if(randCity == 17){return City::HoChiMinhCity;}
    if(randCity == 18){return City::HongKong;}
    if(randCity == 19){return City::Beijing;}
    if(randCity == 20){return City::Shanghai;}
    if(randCity == 21){return City::Seoul;}
    if(randCity == 22){return City::Bogota;}
    if(randCity == 23){return City::MexicoCity;}
    if(randCity == 24){return City::Lima;}
    if(randCity == 25){return City::SaoPaulo;}
    if(randCity == 26){return City::BuenosAires;}
    if(randCity == 27){return City::Khartoum;}
    if(randCity == 28){return City::Mumbai;}
    if(randCity == 29){return City::Delhi;}
    if(randCity == 30){return City::SanFrancisco;}
    if(randCity == 31){return City::LosAngeles;}
    if(randCity == 32){return City::Montreal;}
    if(randCity == 33){return City::Essen;}
    if(randCity == 34){return City::London;}
    if(randCity == 35){return City::Milan;}
    if(randCity == 36){return City::StPetersburg;}
    if(randCity == 37){return City::Manila;}
    if(randCity == 38){return City::Taipei;}
    if(randCity == 39){return City::Moscow;}
    if(randCity == 40){return City::Sydney;}
    if(randCity == 41){return City::Johannesburg;}
    if(randCity == 42){return City::Kinshasa;}
    if(randCity == 43){return City::Lagos;}
    if(randCity == 44){return City::Santiago;}
    if(randCity == 45){return City::NewYork;}
    if(randCity == 46){return City::Osaka;}

    /*if(randCity == 47)*/
    return City::Tokyo;
}

TEST_CASE("init ") {
    conections[City::Algiers] = {City::Madrid, City::Paris, City::Istanbul, City::Cairo};
    conections[City::Atlanta] = {City::Chicago, City::Miami, City::Washington};
    conections[City::Baghdad] = {City::Tehran, City::Istanbul, City::Cairo, City::Riyadh, City::Karachi};
    conections[City::Bangkok] = {City::Kolkata, City::Chennai, City::Jakarta, City::HoChiMinhCity, City::HongKong};
    conections[City::Beijing] = {City::Shanghai, City::Seoul};
    conections[City::Bogota] = {City::MexicoCity, City::Lima, City::Miami, City::SaoPaulo, City::SaoPaulo, City::BuenosAires};
    conections[City::BuenosAires] = {City::Bogota, City::SaoPaulo};
    conections[City::Cairo] = {City::Algiers, City::Istanbul, City::Baghdad, City::Khartoum, City::Riyadh};
    conections[City::Chennai] = {City::Mumbai, City::Delhi, City::Kolkata, City::Bangkok, City::Jakarta};
    conections[City::Chicago] = {City::SanFrancisco, City::LosAngeles, City::MexicoCity, City::Atlanta, City::Montreal};
    conections[City::Delhi] = {City::Tehran, City::Karachi, City::Mumbai, City::Chennai, City::Kolkata};
    conections[City::Essen] = {City::London, City::Paris, City::Milan, City::StPetersburg};
    conections[City::HoChiMinhCity] = {City::Jakarta, City::Bangkok, City::HongKong, City::Manila};
    conections[City::HongKong] = {City::Bangkok, City::Kolkata, City::HoChiMinhCity, City::Shanghai, City::Manila, City::Taipei};
    conections[City::HongKong] = {City::Bangkok, City::Kolkata, City::HoChiMinhCity, City::Shanghai, City::Manila, City::Taipei};
    conections[City::Istanbul] = {City::Milan, City::Algiers, City::StPetersburg, City::Cairo, City::Baghdad, City::Moscow};
    conections[City::Jakarta] = {City::Chennai, City::Bangkok, City::HoChiMinhCity, City::Sydney};
    conections[City::Johannesburg] = {City::Kinshasa, City::Khartoum};
    conections[City::Karachi] = {City::Tehran, City::Baghdad, City::Riyadh, City::Mumbai, City::Delhi};
    conections[City::Khartoum] =  {City::Cairo, City::Lagos, City::Kinshasa, City::Johannesburg};
    conections[City::Kinshasa] = {City::Lagos, City::Khartoum, City::Johannesburg};
    conections[City::Kolkata] = {City::Delhi, City::Chennai, City:: Bangkok, City:: HongKong};
    conections[City::Lagos] =  {City::SaoPaulo, City::Khartoum, City::Kinshasa};
    conections[City::Lima] =  {City::MexicoCity, City::Bogota, City::Santiago};
    conections[City::London] =  {City::NewYork, City::Madrid, City::Essen, City::Paris};
    conections[City::LosAngeles] =  {City::SanFrancisco, City::Chicago, City::MexicoCity, City::Sydney};
    conections[City::Madrid] =  {City::London, City::NewYork, City::Paris, City::SaoPaulo, City::Algiers};
    conections[City::Manila] =  {City::Taipei, City::SanFrancisco, City::HoChiMinhCity, City::Sydney};
    conections[City::MexicoCity] =  {City::LosAngeles, City::Chicago, City::Miami, City::Lima, City::Bogota};
    conections[City::Miami] =  {City::Atlanta, City::MexicoCity, City::Washington, City::Bogota};
    conections[City::Milan] =  {City::Essen, City::Paris, City::Istanbul};
    conections[City::Montreal] =  {City::Chicago, City::Washington, City::NewYork};
    conections[City::Moscow] = {City::StPetersburg, City::Istanbul, City::Tehran};
    conections[City::Mumbai] = {City::Karachi,  City::Delhi,  City::Chennai};
    conections[City::NewYork] =  {City::Montreal,  City::Washington,  City::London,  City::Madrid};
    conections[City::Osaka] =  {City::Taipei, City::Tokyo};
    conections[City::Paris ] = {City::Algiers,  City::Essen, City::Madrid,  City::Milan ,City::London};
    conections[City::Riyadh] =  {City::Baghdad,  City::Cairo,  City::Karachi};
    conections[City::SanFrancisco] =  {City::LosAngeles,  City::Chicago, City::Tokyo, City::Manila};
    conections[City::Santiago ] = {City::Lima};
    conections[City::SaoPaulo] =  {City::Bogota, City::BuenosAires, City::Lagos, City::Madrid};
    conections[City::Seoul] =  {City::Beijing, City::Shanghai, City::Tokyo};
    conections[City::Shanghai] =   {City::Beijing, City::HongKong, City::Taipei, City::Seoul, City::Tokyo};
    conections[City::StPetersburg] =  {City::Essen,  City::Istanbul,  City::Moscow};
    conections[City::Sydney] =   {City::Jakarta,  City::Manila, City::LosAngeles};
    conections[City::Taipei] =   {City::Shanghai, City::HongKong, City::Osaka, City::Manila};
    conections[City::Tehran] =  {City::Baghdad, City::Moscow, City::Karachi, City::Delhi};
    conections[City::Tokyo] = {City::Seoul, City::Shanghai, City::Osaka, City::SanFrancisco};
    conections[City::Washington] =  {City::Atlanta, City::NewYork, City::Montreal, City::Miami};
    /*****************************************************************************************************/
    diseases[Color::Black] = {City::Algiers , City::Cairo, City::Istanbul,City::Baghdad,City::Moscow,
    City::Tehran, City::Karachi,City::Riyadh, City::Mumbai, City::Delhi, City::Kolkata, City::Chennai};
    diseases[Color::Red] = {City::Shanghai, City::HongKong, City::Bangkok, City::Jakarta, City::HongKong,
    City::Manila, City::Sydney, City::Taipei, City::Osaka, City::Tokyo, City::Seoul,  City::Beijing};
    diseases[Color::Yellow] = {City::Khartoum, City::Kinshasa, City::Johannesburg, City::Lagos, 
    City::SaoPaulo, City::BuenosAires, City::Santiago, City::Lima, City::Bogota, City::Miami,
    City::MexicoCity, City::LosAngeles};
    diseases[Color::Blue] = {City::SanFrancisco, City::Chicago, City::Atlanta, City::Montreal,
    City::NewYork, City::Washington, City::Madrid, City::London, City::Paris, City::Essen,
    City::Milan, City::StPetersburg};
}
/**************************************** The Tests ****************************************/
/*assignment of random disease levels in random cities
and thatn clean them*/
TEST_CASE("Board isClean tests") 
{
    Board board;/*init new empty board*/

    /**********************************/
    /**********init Randomaly**********/
    /**********************************/
    int rand_City , rand_disease_state;
    /*initialize random generator*/
    srand (time(NULL));

    for(int i=0 ;i < 50 ; i++){
        /* generate number between 0 and 47 for each City enum*/
            /* generate number between 0 and 4 for each disease state*/
        rand_disease_state = rand() % MAX_DISEASE_STAGE;
        board[convert_INTvalue_to_enum(rand_City)] = rand_disease_state;
        CHECK_FALSE(board.is_clean() == false);
    }
    /**********************************/
    /*******clean the board auto*******/
    /**********************************/
    for(int i = 0; i<MAX_CITIES_NUM ; i++){
        board[convert_INTvalue_to_enum(i)] = 0;
    }
    CHECK(board.is_clean() == true);

    /**********************************/
    /***********init manualy***********/
    /**********************************/
    board[City::BuenosAires] = 2;
    CHECK_FALSE(board.is_clean() == false);
    board[City::Delhi] = 4;
    CHECK_FALSE(board.is_clean() == false);
    board[City::HoChiMinhCity] = 3;
    CHECK_FALSE(board.is_clean() == false);
    board[City::Kinshasa] = 3;
    CHECK_FALSE(board.is_clean() == false);
    board[City::Paris] = 5;
    CHECK_FALSE(board.is_clean() == false);
    board[City::Paris] = 3;
    CHECK_FALSE(board.is_clean() == false);
    board[City::SaoPaulo] = 1;
    CHECK_FALSE(board.is_clean() == false);
    board[City::Cairo] = 3;
    CHECK_FALSE(board.is_clean() == false);
    board[City::Moscow] = 2;
    CHECK_FALSE(board.is_clean() == false);
    board[City::Lima] = 1;
    CHECK_FALSE(board.is_clean() == false);

    /**********************************/
    /******clean the board manualy*****/
    /**********************************/
    board[City::BuenosAires] = 0;
    CHECK_FALSE(board.is_clean() == false);
    board[City::Delhi] = 0;
    CHECK_FALSE(board.is_clean() == false);
    board[City::HoChiMinhCity] = 0;
    CHECK_FALSE(board.is_clean() == false);
    board[City::Kinshasa] = 0;
    CHECK_FALSE(board.is_clean() == false);
    board[City::Paris] = 0;
    CHECK_FALSE(board.is_clean() == false);
    board[City::Paris] = 0;
    CHECK_FALSE(board.is_clean() == false);
    board[City::SaoPaulo] = 0;
    CHECK_FALSE(board.is_clean() == false);
    board[City::Cairo] = 0;
    CHECK_FALSE(board.is_clean() == false);
    board[City::Moscow] = 0;
    CHECK_FALSE(board.is_clean() == false);
    board[City::Lima] = 0;

    /*have to be clean*/
    CHECK(board.is_clean() == true);
}

TEST_CASE("Board [] operators") 
{
    Board board;/*init new empty board*/
    // cout << "bug" ;
    /**********************************/
    /**********init Randomaly**********/
    /**********************************/

   int rand_City , rand_disease_state;
    /*initialize random generator*/
    srand (time(NULL));

    for(int i=0 ;i < 100 ; i++){
        /* generate number between 0 and 47 for each City enum*/
            /* generate number between 0 and 4 for each disease state*/
        rand_disease_state = rand() % MAX_DISEASE_STAGE;
        board[convert_INTvalue_to_enum(rand_City)] = rand_disease_state;
        CHECK_FALSE(board[convert_INTvalue_to_enum(rand_City)] != (rand_disease_state-1));
        }
}

/////////////////////////////////////////////////////////
////////////////////|               |////////////////////
////////////////////|    Players    |////////////////////
////////////////////|     Tests     |////////////////////
////////////////////|               |////////////////////
/////////////////////////////////////////////////////////

TEST_CASE("drive methos tests") 
{
    Board board;/*init new empty board*/
    Player* allPlayers[8];
    int rand_City , rand_disease_state;
    /*initialize random generator*/
    srand (time(NULL));
    
    /************************************************************/
    /**********init Randomaly locations for the players**********/
    /************************************************************/
    vector <City>_canMoveTo, _cantMoveTo;
    bool rigthMove = false, badMove = true;
    /////////////////////////////////////////////////////////////
    allPlayers [0] = new Dispatcher(board,City::Algiers); 
    allPlayers[0]->drive(City::Madrid);
    _canMoveTo = conections[City::Madrid];
    for(const auto& it : _canMoveTo){
        if(it == City::Algiers){rigthMove = true;}
    }
    CHECK(rigthMove == true);

    allPlayers[0]->drive(City::Montreal );
    _cantMoveTo = conections[City::Montreal ];
    for(const auto& it : _cantMoveTo){
        if(it == City::Algiers){badMove = false;}
    }
    CHECK(badMove == true);
    /////////////////////////////////////////////////////////////
    allPlayers [1] = new OperationsExpert(board,City::MexicoCity ); 
    rigthMove = false, badMove = true;
    allPlayers[1]->drive(City::Chicago );
    _cantMoveTo = conections[City::Chicago ];
    for(const auto& it : _canMoveTo){
        if(it == City::MexicoCity){rigthMove = true;}
    }
    CHECK(rigthMove == true);

    allPlayers[1]->drive(City::Tehran);
    _cantMoveTo = conections[City::Tehran];
    for(const auto& it : _cantMoveTo){
        if(it == City::Chicago){badMove = false;}
    }
    CHECK(badMove == true);
    /////////////////////////////////////////////////////////////
    allPlayers [2] = new Scientist(board,City::Delhi ,4); 
    rigthMove = false, badMove = true;
    allPlayers[2]->drive(City::Karachi  );
    _canMoveTo = conections[City::Karachi  ];
    for(const auto& it : _canMoveTo){
        if(it == City::Delhi){rigthMove = true;}
    }
    CHECK(rigthMove == true);

    allPlayers[2]->drive(City::Lagos );
    _cantMoveTo = conections[City::Lagos];
    for(const auto& it : _cantMoveTo){
        if(it == City::Karachi){badMove = false;}
    }
    CHECK(badMove == true);
    /////////////////////////////////////////////////////////////
    allPlayers [3] = new Researcher(board,City::London ); 
    rigthMove = false, badMove = true;
    allPlayers[3]->drive(City::Madrid   );
    _canMoveTo = conections[City::Madrid   ];
    for(const auto& it : _canMoveTo){
        if(it == City::London){rigthMove = true;}
    }
    CHECK(rigthMove == true);

    allPlayers[3]->drive(City::Taipei  );
    _cantMoveTo = conections[City::Taipei ];
    for(const auto& it : _cantMoveTo){
        if(it == City::Madrid){badMove = false;}
    }
    CHECK(badMove == true);
    /////////////////////////////////////////////////////////////
    allPlayers [4] = new Medic(board,City::Lima ); 
    rigthMove = false, badMove = true;
    allPlayers[4]->drive(City::MexicoCity    );
    _canMoveTo = conections[City::MexicoCity    ];
    for(const auto& it : _canMoveTo){
        if(it == City::Lima){rigthMove = true;}
    }
    CHECK(rigthMove == true);

    allPlayers[4]->drive(City::Washington   );
    _cantMoveTo = conections[City::Washington  ];
    for(const auto& it : _cantMoveTo){
        if(it == City::MexicoCity){badMove = false;}
    }
    CHECK(badMove == true);
    /////////////////////////////////////////////////////////////
    allPlayers [5] = new Virologist(board,City::Khartoum  ); 
     rigthMove = false, badMove = true;
    allPlayers[5]->drive(City::Lagos    );
    _canMoveTo = conections[City::Lagos    ];
    for(const auto& it : _canMoveTo){
        if(it == City::Khartoum){rigthMove = true;}
    }
    CHECK(rigthMove == true);

    allPlayers[5]->drive(City::Kolkata    );
    _cantMoveTo = conections[City::Kolkata   ];
    for(const auto& it : _cantMoveTo){
        if(it == City::Lagos){badMove = false;}
    }
    CHECK(badMove == true);
    /////////////////////////////////////////////////////////////
    allPlayers [6] = new GeneSplicer(board,City::Johannesburg  ); 
    rigthMove = false, badMove = true;
    allPlayers[6]->drive(City::Khartoum    );
    _canMoveTo = conections[City::Khartoum    ];
    for(const auto& it : _canMoveTo){
        if(it == City::Johannesburg){rigthMove = true;}
    }
    CHECK(rigthMove == true);

    allPlayers[6]->drive(City::Madrid     );
    _cantMoveTo = conections[City::Madrid    ];
    for(const auto& it : _cantMoveTo){
        if(it == City::Khartoum){badMove = false;}
    }
    CHECK(badMove == true);
    /////////////////////////////////////////////////////////////
    allPlayers [7] = new FieldDoctor(board,City::Cairo  ); 
    rigthMove = false, badMove = true;
    allPlayers[7]->drive(City::Istanbul     );
    _canMoveTo = conections[City::Istanbul     ];
    for(const auto& it : _canMoveTo){
        if(it == City::Cairo){rigthMove = true;}
    }
    CHECK_FALSE(rigthMove == false);

    allPlayers[7]->drive(City::Istanbul);
    _cantMoveTo = conections[City::Istanbul ];
    for(const auto& it : _cantMoveTo){
        if(it == City::HoChiMinhCity ){badMove = false;}
    }
    CHECK(badMove == true);
    /////////////////////////////////////////////////////////////
    for(int i=0 ; i<8 ; i ++){
        delete allPlayers[i];
    }    
  }

TEST_CASE("fly_direct methos tests") 
{
    Board board;/*init new empty board*/
    Player* allPlayers [3];
    int rand_City , rand_disease_state;
    /*initialize random generator*/
    srand (time(NULL));
    
    bool canFly = false;
    /************************************************************/
    /**********init Randomaly locations for the players**********/
    /************************************************************/
    allPlayers [0] = new Dispatcher(board,City::Algiers);
    allPlayers[0]->fly_direct(City::Cairo);
    if(board.GetCitiesResearchStations()[static_cast<int>(City::Algiers)] == true){
        canFly = true;
    }
    else if(allPlayers[0]->GetCardSets().find(City::Cairo) != allPlayers[0]->GetCardSets().end()){
        canFly = true;
    }
    if(canFly == true){
        CHECK(allPlayers [0]->GetCity() == City::Cairo);
    }else{
        CHECK(allPlayers [0]->GetCity() != City::Cairo);
    }
    /////////////////////////////////////////////////////////////
    allPlayers [1] = new OperationsExpert(board,City::Paris);
    allPlayers[1]->fly_direct(City::Miami);
    if(allPlayers[1]->GetCardSets().find(City::Miami) != allPlayers[1]->GetCardSets().end()){
        canFly = true;
    }
    if(canFly == true){
        CHECK(allPlayers [1]->GetCity() == City::Miami);
    }else{
        CHECK(allPlayers [1]->GetCity() != City::Miami);
    }
    /////////////////////////////////////////////////////////////
    allPlayers [2] = new Virologist(board,City::Moscow);
    allPlayers[2]->fly_direct(City::Riyadh);
    if(allPlayers[2]->GetCardSets().find(City::Riyadh) != allPlayers[2]->GetCardSets().end()){
        canFly = true;
    }
    if(canFly == true){
        CHECK(allPlayers [2]->GetCity() == City::Riyadh);
    }else{
        CHECK(allPlayers [2]->GetCity() != City::Riyadh);
    }
    /////////////////////////////////////////////////////////////
    for(int i=0 ; i<3 ; i ++){
        delete allPlayers[i];
    }  
  }
  TEST_CASE("fly_charter methos tests") 
{
    Board board;/*init new empty board*/
    Player* allPlayers [3];
    int rand_City , rand_disease_state;
    /*initialize random generator*/
    srand (time(NULL));
    
    bool canFly = false;
    /************************************************************/
    /**********init Randomaly locations for the players**********/
    /************************************************************/
    allPlayers [0] = new Dispatcher(board,City::Algiers);
    allPlayers[0]->fly_direct(City::Cairo);
    if(allPlayers[0]->GetCardSets().find(City::Algiers) != allPlayers[0]->GetCardSets().end()){
        canFly = true;
    }
    if(canFly == true){
        CHECK(allPlayers [0]->GetCity() == City::Cairo);
    }else{
        CHECK(allPlayers [0]->GetCity() != City::Cairo);
    }
    /////////////////////////////////////////////////////////////
    allPlayers [1] = new OperationsExpert(board,City::Paris);
    allPlayers[1]->fly_direct(City::Miami);
    if(allPlayers[1]->GetCardSets().find(City::Paris) != allPlayers[1]->GetCardSets().end()){
        canFly = true;
    }
    if(canFly == true){
        CHECK(allPlayers [1]->GetCity() == City::Miami);
    }else{
        CHECK(allPlayers [1]->GetCity() != City::Miami);
    }
    /////////////////////////////////////////////////////////////
    allPlayers [2] = new Virologist(board,City::Moscow);
    allPlayers[2]->fly_direct(City::Riyadh);
    if(allPlayers[2]->GetCardSets().find(City::Moscow) != allPlayers[2]->GetCardSets().end()){
        canFly = true;
    }
    if(canFly == true){
        CHECK(allPlayers [2]->GetCity() == City::Riyadh);
    }else{
        CHECK(allPlayers [2]->GetCity() != City::Riyadh);
    }
    /////////////////////////////////////////////////////////////
    for(int i=0 ; i<3 ; i ++){
        delete allPlayers[i];
    }  
  }

  TEST_CASE("fly_shuttle methos tests") 
{
    Board board;/*init new empty board*/
    Player* allPlayers [3];
    int rand_City , rand_disease_state;
    /*initialize random generator*/
    srand (time(NULL));
    
    bool canFly = false;
    /************************************************************/
    /**********init Randomaly locations for the players**********/
    /************************************************************/
    allPlayers [0] = new Dispatcher(board,City::Algiers);
    allPlayers[0]->fly_direct(City::Cairo);
    if(board.GetCitiesResearchStations()[static_cast<int>(City::Algiers)] == true){
        if(board.GetCitiesResearchStations()[static_cast<int>(City::Cairo)] == true){
            canFly = true;
        }
    }
    if(canFly == true){
        CHECK(allPlayers [0]->GetCity() == City::Cairo);
    }else{
        CHECK(allPlayers [0]->GetCity() != City::Cairo);
    }
    /////////////////////////////////////////////////////////////
    allPlayers [1] = new Medic(board,City::Baghdad);
    allPlayers[1]->fly_direct(City::SanFrancisco);
    if(board.GetCitiesResearchStations()[static_cast<int>(City::Baghdad)] == true){
        if(board.GetCitiesResearchStations()[static_cast<int>(City::SanFrancisco)] == true){
            canFly = true;
        }
    }
    if(canFly == true){
        CHECK(allPlayers [1]->GetCity() == City::SanFrancisco);
    }else{
        CHECK(allPlayers [1]->GetCity() != City::SanFrancisco);
    }
    /////////////////////////////////////////////////////////////
    allPlayers [2] = new Virologist(board,City::StPetersburg);
    allPlayers[2]->fly_direct(City::Riyadh);
   if(board.GetCitiesResearchStations()[static_cast<int>(City::StPetersburg)] == true){
        if(board.GetCitiesResearchStations()[static_cast<int>(City::Riyadh)] == true){
            canFly = true;
        }
    }
    if(canFly == true){
        CHECK(allPlayers [2]->GetCity() == City::Riyadh);
    }else{
        CHECK(allPlayers [2]->GetCity() != City::Riyadh);
    }
    /////////////////////////////////////////////////////////////
    for(int i=0 ; i<3 ; i ++){
        delete allPlayers[i];
    }  
  }

   TEST_CASE("fly_shuttle methos tests") 
{
    Board board;/*init new empty board*/
    Player* allPlayers [4];
    int rand_City , rand_disease_state;
    /*initialize random generator*/
    srand (time(NULL));
    
    bool canBuild = false;
    /************************************************************/
    /**********init Randomaly locations for the players**********/
    /************************************************************/
    int countBuild = 0;
    allPlayers [0] = new OperationsExpert(board,City::Cairo);
    allPlayers[0]->build();
    allPlayers [1] = new OperationsExpert(board,City::HoChiMinhCity);
    allPlayers[1]->build();
    allPlayers [2] = new OperationsExpert(board,City::Taipei);
    allPlayers[2]->build();
    if(board.GetCitiesResearchStations()[static_cast<int>(City::Baghdad)] == true){countBuild++;}
    if(board.GetCitiesResearchStations()[static_cast<int>(City::HoChiMinhCity)] == true){countBuild++;}
    if(board.GetCitiesResearchStations()[static_cast<int>(City::Taipei)] == true){countBuild++;}

    CHECK(countBuild == 3);
    
    /////////////////////////////////////////////////////////////
    allPlayers [3] = new Medic(board,City::Baghdad);
    canBuild = false;
    if(allPlayers[3]->GetCardSets().find(City::Baghdad) != allPlayers[3]->GetCardSets().end()){
       allPlayers[3]->build();  
       canBuild=true;
    }
    if(canBuild == true){
        CHECK(board.GetCitiesResearchStations()[static_cast<int>(City::Baghdad)] == true);
    }else{
        CHECK(board.GetCitiesResearchStations()[static_cast<int>(City::Baghdad)] == false);
    }
    /////////////////////////////////////////////////////////////
    for(int i=0 ; i<4 ; i ++){
        delete allPlayers[i];
    }  
  }