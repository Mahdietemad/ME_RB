#include "game.h"

using std::cout;


#ifndef RULES
#define RULES

class Rules {
	Player const* currPlayer;
	
public:
	// Public Class Methods
	bool isValid(const Game&);
	bool gameOver(const Game&);
	bool roundOver(const Game&);
	const Player& getNextPlayer(const Game&);

	// Destructor
	~Rules();

};


#endif
