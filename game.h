#include "board.h"
#include "player.h"

using std::endl;
using std::cout;
using std::cin;

#ifndef GAME
#define GAME

class Game {
	// Private Class Variables
	Board board;
	int roundNum;
	Player* currPlayer = nullptr;
	Card const* prevCard = nullptr;
	Card const* currCard = nullptr;
	
	// Friend Accesses
	friend ostream& operator<<(ostream& _os, const Game& _game);

public:
	// Public Class Variables
	vector<Player*> players;

	// Public Class Methods
	Game();
	int getRound() const;
	void nextRound();
	void addPlayer( const Player&);
	Player& getPlayer(Side) const;
	const Card* getPreviousCard() const;
	const Card* getCurrentCard() const;
	void setCurrentCard(const Card*);
	const Card* getCard(const Letter&, const Number&);
	void setCard(const Letter&, const Number&, const Card*);

	// Destructor
	~Game();

	// Additional Public Class Methods
	void reset();

	// Public Class Methods for Expert Display
	void setExpertDisplay();

	// Public Class Methods for Expert Rules
	void octopus();
	void penguin();
	bool walrus(const Letter&, const Number&);

	bool crab();
	bool turtle();
	bool isOctopus();
	bool isPenguin();
	bool isWalrus();


	Letter stringtoLetter(char);
	Number stringtoNumber(char);
};


#endif
