#include "reward.h"

Reward::Reward(int _rubies): rubies(_rubies) {}

ostream& operator<<(ostream& _os, const Reward& _reward) {
	_os << "The reward is " << _reward << " rubies!";
	return _os;
}

Reward::operator int() const{
	return rubies;
}