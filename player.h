#include "reward.h"

#include <iostream>
#include <string>

using std::string;
using std::ostream;

#ifndef PLAYER
#define PLAYER

enum Side {top, bottom, left, right}; //class enumeration for Side

class Player {
	// Private Class Variables
	string name;
	Side side;
	int numRubies = 0;
	bool status = false;
	bool endOfGame = false;

	// Friend Accesses
	friend ostream& operator<<(ostream& _os, const Player& _player);

public:
	// Public Class Methods
	Player(string _name, Side _side);
	string getName() const;
	void setActive(bool _activity);
	bool isActive();
	int getNRubies();
	void addReward(const Reward& _reward);
	void setDisplayMode(bool _endOfGame);
	Side getSide() const;
	void setSide(Side _side);
	
};

#endif