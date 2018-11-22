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

	friend ostream& operator<<(ostream& _os, const Reward& _reward);

public:
	// Public Class Functions
	operator int() const;
};

#endif
