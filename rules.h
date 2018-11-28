#include "game.h"


#ifndef RULES
#define RULES

class Rules {

public:
	bool isValid(const Game&);
	bool gameOver(const Game&);
	bool roundOver(const Game&);
	const Player& getNextPlayer(const Game&);
};


#endif
