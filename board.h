#include "cardDeck.h"

#include <string>

using std::string;

#ifndef BOARD
#define BOARD

enum Letter {A, B, C, D, E};
enum Number {One, Two, Three, Four, Five};

class Board {

	Card* cardBoard[5][5];
	bool boolBoard[5][5];


	void updateNormalBoard();
	void updateExpertBoard();

	friend ostream& operator<<(ostream& _os, const Board& _board);
public:
	Board(bool expertDisplay, CardDeck& cardDeck);
	bool isFaceUp(const Letter& letter, const Number number) const;
	bool turnFaceUp(const Letter& letter, const Number number);
	bool turnFaceDown(const Letter& letter, const Number number);
	Card* getCard(const Letter& letter, const Number number);
	void setCard(const Letter& letter, const Number&, Card* card);
	void reset();
};



#endif
