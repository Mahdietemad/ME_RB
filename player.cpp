#include "player.h"

// Public Class Functions
Player::Player(string _name, Side _side): name(_name), side(_side) {}

string Player::getName() const { return name; }

void Player::setActive(bool _status) { status = _status; }

bool Player::isActive() { return status; }

int Player::getNRubies() { return numRubies; }

void Player::addReward(const Reward& _reward) { numRubies += _reward; }

void Player::setDisplayMode(bool _endOfGame) { endOfGame = _endOfGame; }

Side Player::getSide() const { return side; }

void Player::setSide(Side _side) { side = _side; }

// Outstream operator overload for Class Player
ostream& operator<<(ostream& _os, const Player& _player) {
	string activity = "inactive";
	if (_player.status) {
		activity = "active";
	}
	string sideString = "?"; // To check for an error
	switch(_player.side) {
	case top: sideString = "top"; break;
	case bottom: sideString = "bottom"; break;
	case left: sideString = "left"; break;
	case right: sideString = "right"; break;
	}
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
using std::cout;
using std::endl;
void main() {
	// Test Player::Player(string _name, Side _side)
	cout << "Testing -> Player::Player(string _name, Side _side)" << endl;
	Player p = Player("Reece", top);
	cout << "Above test complete" << endl;

	// Test ostream& operator<<(ostream& _os, const Player& _player)
	cout << "Testing -> ostream& operator<<(ostream& _os, const Player& _player)" << endl;
	cout << p << endl;

	// Test string Player::getName()
	cout << "Testing -> string Player::getName()" << endl;
	cout << p.getName() << endl;

	// Test bool Player::isActive()
	cout << "Testing -> bool Player::isActive()" << endl;
	cout << p.isActive() << endl;

	// Test void Player::setActive(bool _status)
	cout << "Testing -> void Player::setActive(bool _status)" << endl;
	p.setActive(false);
	cout << p << endl;

	// Test int Player::getNRubies()
	cout << "Testing -> int Player::getNRubies()" << endl;
	cout << p.getNRubies() << endl;

	// Test void Player::setSide(Side _side)
	cout << "Testing -> void Player::setSide(Side _side)" << endl;
	p.setSide(bottom);
	cout << p << endl;

	// Test void Player::setDisplayMode(bool _endOfGame)
	cout << "Testing -> void Player::setDisplayMode(bool _endOfGame)" << endl;
	p.setDisplayMode(true);
	cout << p << endl;

	// Test void Player::addReward(const Reward& _reward)
	cout << "Tesing -> void Player::addReward(const Reward& _reward)" << endl;

	cout << "The Reward contructor is private -> Not sure how to test this" << endl;
}
#endif