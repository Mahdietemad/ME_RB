#include <iostream>
#include <string>

using std::ostream;
using std::string;

#ifndef REWARD
#define REWARD

class Reward {
	int numRubies;

	Reward(int _NumRubies);

	friend ostream& operator<<(ostream& _os, const Reward& _reward);

public:
	int getRubies() const;
};

#endif
