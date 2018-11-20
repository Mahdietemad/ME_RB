//#include "reward.h"

#include <iostream>
#include <string>

using std::string;
using std::istream;
using std::ostream;
using std::cout;
using std::cin;



#ifndef PLAYER
#define PLAYER

enum Side {top, bottom, left, right}; //class enumeration for Side

class Player {
	string name;
	Side side;
	int numRubies = 0;
	bool activity = false;
	bool endOfGame = false;

	friend ostream& operator<<(ostream& _os, const Player& _player);

public:
	Player(string _name, Side _side);
	string getName();
	void setActive(bool _activity);
	bool isActive();
	int getNRubies();
//	void addReward(const Reward& _reward);
	void setDisplayMode(bool _endOfGame);
	Side getSide();
	void setSide(Side _side);
	
};

#endif