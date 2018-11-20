#include "player.h"

Player::Player(string _name, Side _side): name(_name), side(_side) {}

string Player::getName() { return name; } //get name function

void Player::setActive(bool _activity) { activity = _activity; }

bool Player::isActive() { return activity; }

int Player::getNRubies() { return numRubies; }


// Fix/complete this function ///////////////////////////////////////
void Player::addReward(const Reward& _reward) {
	return;
}
/////////////////////////////////////////////////////////////////////

void Player::setDisplayMode(bool _endOfGame) { endOfGame = _endOfGame; }

Side Player::getSide() { return side; }

void Player::setSide(Side _side) { side = _side; }
