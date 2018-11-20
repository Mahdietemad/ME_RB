#include "reward.h"

Reward::Reward(int _numRubies): numRubies(_numRubies) {}

ostream& operator<<(ostream& _os, const Reward& _reward) {
	_os << "The reward is " << _reward.numRubies << " rubies!";
	return _os;
}

int Reward::getRubies() const { return numRubies; }