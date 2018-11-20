#include "player.h"

Player::Player(string _name, Side _side): name(_name), side(_side) {}

string Player::getName() { return name; } //get name function

void Player::setActive(bool _activity) { activity = _activity; }

bool Player::isActive() { return activity; }

int Player::getNRubies() { return numRubies; }


// Fix/complete this function ///////////////////////////////////////
//void Player::addReward(const Reward& _reward) {
//	return;
//}
/////////////////////////////////////////////////////////////////////

void Player::setDisplayMode(bool _endOfGame) { endOfGame = _endOfGame; }

Side Player::getSide() { return side; }

void Player::setSide(Side _side) { side = _side; }

ostream& operator<<(ostream& _os, const Player& _player) {
	string status = "inactive";
	if (_player.activity) {
		status = "active";
	}
	string sideString;
	if (_player.side == top) { sideString = "top"; }
	else if (_player.side == bottom) { sideString = "bottom"; }
	else if (_player.side == left) { sideString = "left"; }
	else { sideString = "right"; }

	if (_player.endOfGame == false) {
		_os << _player.name << ": " << sideString << " (" << status << ")";
	};
	return _os;
}