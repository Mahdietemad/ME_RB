#include "rules.h"

bool Rules::isValid(const Game& game) {
	Card const* prevCard = game.getPreviousCard();
	Card const* currCard = game.getCurrentCard();
	FaceAnimal prevAnimal = prevCard;
	
}