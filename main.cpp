//
//  main.cpp
//  MemoryGame
//
//  Created by Mahdi Etemad on 2018-11-15.
//  Copyright © 2018 Mahdi Etemad. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "Player.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string gameVersion, numberOfPlayers, nameOfPlayers;
    vector<string> names;
    cout<<"Please choose the game version (Basic,Expert)"<<endl;
    cin>>gameVersion;
    cout<<"Please choose the number of players"<<endl;
    cin>>numberOfPlayers;
    cout<<"Please type the name of the players (ex: Alex,James)"<<endl;
    cin>>nameOfPlayers;
    
    cout<<"Game Version: " <<gameVersion<<endl;
    cout<<"Number of players: " <<numberOfPlayers<<endl;
    cout<<"Name of players: " <<nameOfPlayers<<endl;

    
    
    
    cout<<"-----------testing------------";
    //testing here:
    
    return 0;
}
