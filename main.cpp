#include "player.cpp"
#include "board.h"
#include "rules.h"
#include <iostream>
#include <string>

using namespace std;

using std::string;
using std::cin;

//tesing main

int main() {
	cout<<"------------1----------"<<endl; //ignore
	int expertDisplay;
	int expertRules;
	Game game;
	Rules rules;
	vector<Player*> players;

	cout << "Choose the display mode:" << endl;
	cout << "Enter '0' for Normal Display or '1' for Expert Display" << endl;
	cin >> expertDisplay;

	cout << "Choose your game mode:" << endl;
	cout << "Enter '0' for Normal Mode or '1' for Expert Mode" << endl;
	cin >> expertRules;
	

    string name1, name2, name3, name4;
    int numberOfPlayers;
    bool flag = true;

    // Enters the number of players
    while(flag){
         cout<<"Please enter the number of players"<<endl;
         cin>>numberOfPlayers;
         if (numberOfPlayers>4 || numberOfPlayers<2){
            if (numberOfPlayers<2){
                cout<<"Minimum of 2 players required";
                 }
             else if(numberOfPlayers>4){
                 cout<<"Maximum of 4 players required";
                }             
         } else {
             flag=false;
         }

    }

	// Create the Player and add them to the game
	for (int i = 0; i < numberOfPlayers; i++) {
		string name;
		cout << "Player " << i + 1 << ":";
		cin >> name;
		Player* player = new Player(name, Side(i));
		players.push_back(player);
		game.addPlayer(*player);
	}
    
	// Initialize the current player
	Player* currPlayer = players[0];

    while(rules.gameOver(game) == false) {
       // update status of cards in board as face down
       // update status of all players in game as active
		int numTurns = 0;
		Letter blockedLetter = C;
		Number blockedNumber = Three;
		while(rules.roundOver(game) == false){
             // next active player takes a turn
             // get selection of card to turn face up from active player 
             // update board in game
			flag = true;
			string userInput;
			while (flag) {
				cout << "Please select a card to turn face up" << endl;
				cin >> userInput;
				Letter userLetter = game.stringtoLetter(userInput[0]);
				Number userNumber = game.stringtoNumber(userInput[1]);

				if ((userLetter == C) && (userNumber == Three)) {
					cout << "C3 is not a valid selection" << endl;
				}
				else if (expertRules && (userLetter == blockedLetter) && (userNumber == blockedNumber)) {
					cout << "The location you selected is blocked. Please select another card." << endl;
				}
				else if (numTurns == 0) {
					game.setCurrentCard(userLetter, userNumber);
					numTurns++;
				}
				else {
					try {
						game.setCurrentCard(userLetter, userNumber);
						numTurns++;
						flag = false;
					}
					catch (exception e) {
						cerr << e.what();
					}
				}
			}
			if(rules.isValid(game)==false){ //rules.isvalid(card)??
				// player is no longer part of the current round
                // current player becomes inactive
				currPlayer->setActive(false);
			}
			
			if (expertRules && rules.isValid(game)){
				if (game.isOctopus()) {
					game.octopus();
					currPlayer = const_cast<Player*>(&rules.getNextPlayer(game));
					blockedLetter = C;
					blockedNumber = Three;
				}
				else if (game.isPenguin()) {
					game.penguin();
					currPlayer = const_cast<Player*>(&rules.getNextPlayer(game));
					blockedLetter = C;
					blockedNumber = Three;
				}
				else if (game.walrus()) {
					bool flag = true;
					string userInput;
					while (flag) {
						cout << "Please select a face down card to block" << endl;
						cin >> userInput;
						Letter userLetter = game.stringtoLetter(userInput[0]);
						Number userNumber = game.stringtoNumber(userInput[1]);
						if ((userLetter == C) && (userNumber == Three)) {
							cout << "C3 is not a valid selection" << endl;
						}
						else {

						}

					}
				}
				else if (game.crab()) {

				}
				else if (game.turtle()) {

				}
			}
			else {
				if (rules.roundOver(game) == false) { currPlayer = const_cast<Player*>(&rules.getNextPlayer(game)); }
				blockedLetter = C;
				blockedNumber = Three;
			}
			cout << game << endl;               
        }
          // Remaining active player receives reward (rubies) 
          
                         }
    
    string winnerName;

    if(numberOfPlayers==2){
    int player1Rubies=player1.getNRubies();
    name1=player1.getName();
    cout<<"name: "+name1<<" Rubies: " +player1Rubies<<endl;
    
     int player2Rubies=player2.getNRubies();
    name2=player2.getName();
    cout<<"name: "+name2<<" Rubies: " +player2Rubies<<endl;
   
    if(player1Rubies>player2Rubies){
        winnerName=name1;
    }
    else{
        winnerName=name3;

    }
    
            
    }
    else if(numberOfPlayers==3){
    int player1Rubies=player1.getNRubies();
    name1=player1.getName();
    cout<<"name: "+name1<<" Rubies: " +player1Rubies<<endl;
    
     int player2Rubies=player2.getNRubies();
    name2=player2.getName();
    cout<<"name: "+name2<<" Rubies: " +player2Rubies<<endl;  
          
     int player3Rubies=player3.getNRubies();
    name3=player3.getName();
    cout<<"name: "+name3<<" Rubies: " +player3Rubies<<endl;  
     
      if((player1Rubies>player2Rubies)&&(player1Rubies>player3Rubies)){
        winnerName=name1;
    }
    else if((player2Rubies>player1Rubies)&&(player2Rubies>player3Rubies)){
        winnerName=name2;
    }
    else{
        winnerName=name3;

    }
        
        
    }else{
        int player1Rubies=player1.getNRubies();
    name1=player1.getName();
    cout<<"name: "+name1<<" Rubies: " +player1Rubies<<endl;
    
     int player2Rubies=player2.getNRubies();
    name2=player2.getName();
    cout<<"name: "+name2<<" Rubies: " +player2Rubies<<endl;  
          
     int player3Rubies=player3.getNRubies();
    name3=player3.getName();
    cout<<"name: "+name3<<" Rubies: " +player3Rubies<<endl;  
    
     int player4Rubies=player4.getNRubies();
    name4=player4.getName();
    cout<<"name: "+name4<<" Rubies: " +player4Rubies<<endl;  
    
    
    
    if((player1Rubies>player2Rubies)&&(player1Rubies>player3Rubies)&&(player1Rubies>player4Rubies)){
        winnerName=name1;
    }
    else if((player2Rubies>player1Rubies)&&(player2Rubies>player3Rubies)&&(player2Rubies>player4Rubies)){
        winnerName=name2;
    }
     else if((player3Rubies>player1Rubies)&&(player3Rubies>player2Rubies)&&(player3Rubies>player4Rubies)){
        winnerName=name3;
    }
    else{
        winnerName=name4;

    }
        
    }
    
    cout<<"the winner is: "<<winnerName<<endl;
   
   
    
    return 0;
}
