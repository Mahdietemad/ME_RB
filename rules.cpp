#include "rules.h"

#include <iterator>

using std::iterator;

bool Rules::isValid(const Game& game) {
	Card const* prevCard = game.getPreviousCard();
	Card const* currCard = game.getCurrentCard();
	FaceAnimal prevAnimal = *prevCard;
	FaceAnimal currAnimal = *currCard;
	FaceBackground prevBackground = *prevCard;
	FaceBackground currBackground = *currCard;
	if (prevAnimal == currAnimal || prevBackground == currBackground) {
		return true;
	}
	else { return false; }
}

bool Rules::gameOver(const Game& game) {
	if (game.getRound() > 6) { return true; }
	else { return false; }
}

bool Rules::roundOver(const Game& game) {
	int activePlayers = 0;
	for (int i = 0; i < 4; i++) {
		if (&game.getPlayer(Side(i)) != nullptr) {
			Player* p = &game.getPlayer(Side(i));
			if (p->isActive()) { activePlayers++; }
		}
	}
	if (activePlayers < 2) { return true; }
	else { return false; }
}

const Player& Rules::getNextPlayer(const Game& game) {
	vector<Player*>::iterator it = game.players.begin;
	while (*it != currPlayer) {
		it++;
	}
	for (int i = 0; i < game.players.size() - 1 ; i++) {
		if (it == game.players.end()) { it = game.players.begin; }
		else { it++; }
		if ((*it)->isActive()) { 
			currPlayer = *it;
			return *(*it);
		}
	}
	return *currPlayer;
}