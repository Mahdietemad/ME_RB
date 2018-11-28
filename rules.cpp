#include "rules.h"

bool Rules::isValid(const Game& game) {
	Card const* prevCard = game.getPreviousCard();
	Card const* currCard = game.getCurrentCard();
	FaceAnimal prevAnimal = prevCard->operator FaceAnimal;
	FaceAnimal currAnimal = currCard->operator FaceAnimal;
	FaceBackground prevBackground = prevCard->operator FaceBackground;
	FaceBackground currBackground = currCard->operator FaceBackground;
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

}