#include "board.h"
#include "rules.h"
#include "rewardDeck.h"

#include <stdlib.h>

using std::string;
using std::exception;

// Method to clear screen for main
void clearScreen() {
	cout << "Press enter to continue";
	cin.ignore();
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

// Meromarrr! 
int main() {
	// Initialize game/rules and other variables
	int expertDisplay;
	int expertRules;
	Game game = Game();
	Rules rules = Rules();
	vector<Player*> players;

	// Introduces the game
	cout << "Welcome to the game of Meromarrr!" << endl;
	cout << "Please refer to the 'CSI 2372 Project Fall 2018' document for rules on how to play!" << endl;

	// Enter the display
	cout << "Choose the display mode:" << endl;
	cout << "Enter '0' for Normal Display or '1' for Expert Display" << endl;
	cin >> expertDisplay;
	cout << endl;
	if (expertDisplay) { game.setExpertDisplay(); }

	// Enter the difficulty
	cout << "Choose your game mode:" << endl;
	cout << "Enter '0' for Normal Mode or '1' for Expert Mode" << endl;
	cin >> expertRules;
	cout << endl;
	
	// Initialize player variables
    int numberOfPlayers;
    bool playerFlag = true;

    // Enters the number of players
    while (playerFlag) {
        cout<<"Please enter the number of players: "<<endl;
        cin>>numberOfPlayers;
		if (numberOfPlayers<2){
			cout<<"Minimum of 2 players required" << endl;
        }
        else if(numberOfPlayers>4){
			cout<<"Maximum of 4 players required" << endl;
        }             
		else {
			playerFlag = false;
		}
		cout << endl;
    }

	// Create the Players and add them to the game
	cout << "Please enter the name of each player" << endl;
	for (int i = 0; i < numberOfPlayers; i++) {
		string name;
		cout << "Player " << i + 1 << ": ";
		cin >> name;
		Player* player = new Player(name, Side(i));
		players.push_back(player);
		game.addPlayer(*player);
	}
	cout << endl;
	clearScreen();

	// Print the game
	if (expertDisplay) {
		cout << "The board will appear empty since you chose the expert display mode" << endl;
	}
	else {
		cout << "Below is the board and the players" << endl;
	}
	cout << game << endl;
	clearScreen();
    
	// Initialize the current player and reward deck
	Player* currPlayer = players[0];
	RewardDeck* rewardDeck;
	rewardDeck = &(rewardDeck->make_RewardDeck());
	rewardDeck->shuffle();

    while(rules.gameOver(game) == false) {
		// Temperarily reveals card in front of players
		if (game.getRound() == 0) {
			for (int i = 0; i < int(players.size()); i++) {
				const Card* card1;
				const Card* card2;
				const Card* card3;
				if (i == 0) {
					card1 = game.getCard(A, Two);
					card2 = game.getCard(A, Three);
					card3 = game.getCard(A, Four);
				}
				else if (i == 1) {
					card1 = game.getCard(E, Two);
					card2 = game.getCard(E, Three);
					card3 = game.getCard(E, Four);
				}
				else if (i == 2) {
					card1 = game.getCard(B, One);
					card2 = game.getCard(C, One);
					card3 = game.getCard(D, One);
				}
				else {
					card1 = game.getCard(B, Five);
					card2 = game.getCard(C, Five);
					card3 = game.getCard(D, Five);
				}
				game.setCurrentCard(card1);
				game.setCurrentCard(card2);
				game.setCurrentCard(card3);
				cout << "The cards are temperarily revealed below for " << players[i]->getName() << endl;
				cout << game << endl;
				clearScreen();
				game.reset();
			}
		}
		// Initalize game variables
		int numTurns = 1;
		Letter blockedLetter = C;
		Number blockedNumber = Three;
		while(rules.roundOver(game) == false){
			// Initlize round variables
			cout << "Round Number: " << game.getRound() << endl;
			cout << "Turn Number: " << numTurns << endl;
			cout << game << endl;
			cout << "Current turn: " + currPlayer->getName() << endl;
			bool inputFlag = true;
			while (inputFlag) {
				string userInput;
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
					game.setCurrentCard(game.getCard(userLetter, userNumber));
					numTurns++;
				}
				else {
					try {
						game.setCurrentCard(game.getCard(userLetter, userNumber));
						numTurns++;
						inputFlag = false;
					}
					catch (exception e) {
						cerr << e.what();
					}
				}
			}
			// Checks if player made a valid selection
			if(rules.isValid(game)==false){ 
				currPlayer->setActive(false);
			}
			// Expert Rules Section
			if (expertRules && currPlayer->isActive()){
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
				else if (game.isWalrus()) {
					bool walrusFlag = true;
					string userInput;
					while (walrusFlag) {
						cout << "Please select a face down card to block" << endl;
						cin >> userInput;
						Letter userLetter = game.stringtoLetter(userInput[0]);
						Number userNumber = game.stringtoNumber(userInput[1]);
						if ((userLetter == C) && (userNumber == Three)) {
							cout << "C3 is not a valid selection" << endl;
						}
						else if (game.walrus(userLetter, userNumber)) {
							blockedLetter = userLetter;
							blockedNumber = userNumber;
							walrusFlag = false;
						}
					}
					currPlayer = const_cast<Player*>(&rules.getNextPlayer(game));
				}
				else if (game.crab()) {
					bool crabFlag = true;
					string userInput;
					while (crabFlag) {
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
						else {
							try {
								game.setCurrentCard(game.getCard(userLetter, userNumber));
								numTurns++;
								crabFlag = false;
							}
							catch (exception e) {
								cerr << e.what();
							}
						}
					}
					currPlayer = const_cast<Player*>(&rules.getNextPlayer(game));
					blockedLetter = C;
					blockedNumber = Three;
				}
				else if (game.turtle()) {
					currPlayer = const_cast<Player*>(&rules.getNextPlayer(game));
					currPlayer = const_cast<Player*>(&rules.getNextPlayer(game));
					blockedLetter = C;
					blockedNumber = Three;
				}
			}
			// Normal 
			else {
				if (rules.roundOver(game) == false) { currPlayer = const_cast<Player*>(&rules.getNextPlayer(game)); }
				blockedLetter = C;
				blockedNumber = Three;
			}
			cout << game << endl;               
        }
        // Remaining active player receives reward (rubies) & next round
		Reward* reward = rewardDeck->next();
		currPlayer->addReward(*reward);
		delete reward;
		game.nextRound();
    }
	// Set each player to endOfGame
	for (int i = 0; i < int(players.size()); i++) {
		players[i]->setDisplayMode(true);
	}
	// Prints players
	Player* winner = nullptr;
	vector<Player*> copyPlayers = players;
	for (int i = 0; i < int(players.size()); i++) {
		Player* leastPlayer = nullptr;
		int leastRubies = -1;
		int position = -1;
		for (int j = 0; j < int(copyPlayers.size()); j++) {
			if (copyPlayers[j]->getNRubies() > leastRubies) {
				leastPlayer = copyPlayers[j];
				leastRubies = copyPlayers[j]->getNRubies();
				position = j;
			}
		}
		cout << *leastPlayer << endl;
		copyPlayers.erase(copyPlayers.begin() + position);
		winner = leastPlayer;
	}
	cout << "The winner is:" << endl;
	cout << winner->getName() << endl;

	delete rewardDeck;
	delete currPlayer;
	delete winner;

	return 0;
}


