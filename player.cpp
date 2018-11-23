#include "player.h"

// Public Class Functions
Player::Player(string _name, Side _side): name(_name), side(_side) {}

string Player::getName() { return name; }

void Player::setActive(bool _status) { status = _status; }

bool Player::isActive() { return status; }

int Player::getNRubies() { return numRubies; }


void Player::addReward(const Reward& _reward) { numRubies += _reward; }

void Player::setDisplayMode(bool _endOfGame) { endOfGame = _endOfGame; }

Side Player::getSide() { return side; }

void Player::setSide(Side _side) { side = _side; }

// Outstream operator overload for Class Player
ostream& operator<<(ostream& _os, const Player& _player) {
	string activity = "inactive";
	if (_player.status) {
		activity = "active";
	}
	string sideString = "?"; // To check for an error
	if (_player.side == top) { sideString = "top"; }
	else if (_player.side == bottom) { sideString = "bottom"; }
	else if (_player.side == left) { sideString = "left"; }
	else if (_player.side == right) { sideString = "right"; }

	if (_player.endOfGame == false) {
		_os << _player.name << ": " << sideString << " (" << activity << ")";
	}
	else {
		_os << _player.name << ": " << _player.numRubies << " rubies";
	}
	return _os;
}

// Testing the public functions of player.cpp
#define TEST_PLAYER (0)
#if TEST_PLAYER
void main() {
	;
}
#endif
