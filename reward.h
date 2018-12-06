#include <iostream>
#include <string>

using std::ostream;
using std::string;

#ifndef REWARD
#define REWARD

class Reward {
	//Class Variables
	const int rubies;

	// Private Class Functions
	Reward(int _NumRubies);

	// Friend Accesses
	friend ostream& operator<<(ostream& _os, const Reward& _reward);
	friend class RewardDeck;

public:
	// Public Class Functions
	operator int() const;

	// Destructor
	~Reward();
};

#endif
