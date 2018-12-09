#include "reward.h"

Reward::Reward(int _rubies): rubies(_rubies) {}

ostream& operator<<(ostream& _os, const Reward& _reward) {
	_os << "The reward is " << int(_reward) << " rubies!";
	return _os;
}

Reward::operator int() const{
	return rubies;
}

Reward::~Reward() {}

#define TEST_REWARD (0)
#if TEST_REWARD
void main() {
	// // The public methods for Reward will be tested inside of rewardDeck.cpp
	cout << "The public methods for Reward will be tested inside of rewardDeck.cpp" << endl;
}
#endif