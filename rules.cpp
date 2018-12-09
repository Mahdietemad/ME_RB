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
	for (int i = 0; i < int(game.players.size()); i++) {
		if (&game.getPlayer(Side(i)) != nullptr) {
			Player* p = &game.getPlayer(Side(i));
			if (p->isActive()) { activePlayers++; }
		}
	}
	if (activePlayers < 2) { return true; }
	else { return false; }
}

const Player& Rules::getNextPlayer(const Game& game) {
	int temp = 0;
	while (game.players[temp] != currPlayer) {
		temp++;
	}
	for (int i = 0; i < int(game.players.size()) - 1; i++) {
		if (temp == int(game.players.size()) - 1) { temp = 0; }
		else { temp++; }
		if (game.players[temp]->isActive()) {
			currPlayer = game.players[temp];
			return *currPlayer;
		}
	}
	return *currPlayer;
}

Rules::~Rules() {
	delete currPlayer;
}