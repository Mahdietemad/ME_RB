#include "board.h"
#include "player.h"

#ifndef GAME
#define GAME

class Game {
	// Private Class Variables
	Board board;
	int roundNum = 0;
	Player* players[4] = { nullptr };
	Player currPlayer;
	Card const* prevCard = nullptr;
	Card const* currCard = nullptr;
	
	// Friend Accesses
	friend ostream& operator<<(ostream& _os, const Game& _game);

public:
	// Public Class Methods
	int getRound() const;
	void nextRound();
	void addPlayer( const Player&);
	Player& getPlayer(Side) const;
	const Card* getPreviousCard() const;
	const Card* getCurrentCard() const;
	void setCurrentCard(const Card*);
	Card* getCard(const Letter&, const Number&);
	void setCard(const Letter&, const Number&, Card*);
};


#endif
