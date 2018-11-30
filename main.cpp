#include "player.cpp"
#include <iostream>
#include <string>
using namespace std;
//tesing main

int main() {
    cout<<"------------1----------"<<endl; //ignore
    
    string name1, name2, name3, name4;
    int numberOfPlayers;
    
    cout<<"Please enter the number of players"<<endl;
	cout << "Select 2, 3 or 4" << endl;
	cin >> numberOfPlayers;
	bool numPlayerBool = true;
	while (numPlayerBool) {
		if (numberOfPlayers < 2) {
			cout << "Minimum of 2 players required";
			cout << "Please enter the number of players" << endl;
			cout << "Select 2, 3 or 4" << endl;
			cin >> numberOfPlayers;
		}
		else if (numberOfPlayers > 4) {
			cout << "Maximum of 4 players required";
			cout << "Please enter the number of players" << endl;
			cout << "Select 2, 3 or 4" << endl;
			cin >> numberOfPlayers;
		}
		else {
			for (int i = 0; i < numberOfPlayers; i++) {
				if (i == 0) {
					cout << "Player 1: ";
					cin >> name1;
				}
				else if (i == 1) {
					cout << "Player 2: ";
					cin >> name2;
				}
				else if (i == 2) {
					cout << "Player 3: ";
					cin >> name3;

				}
				else {
					cout << "Player 4: ";
					cin >> name4;
				}
			}
		}
	}    
    return 0;
}