#include "cardDeck.h"

#include <string>
#include <iostream>

using std::string;
using std::vector;

#ifndef BOARD
#define BOARD

enum Letter {A, B, C, D, E};
enum Number {One, Two, Three, Four, Five};

class Board {
	// Private Class Variables
	Card* cardBoard[5][5] = { nullptr };
	bool boolBoard[5][5] = { false };
	CardDeck* boardDeck;

	// Private Class Variables for Expert Display Mode
	bool expertDisplay = false;
	vector<Card*> expertBoard;
	vector<Letter> expertLetter;
	vector<Number> expertNumber;

	// Friend Accesses
	friend ostream& operator<<(ostream& _os, const Letter& _letter);
	friend ostream& operator<<(ostream& _os, const Number& _number);
	friend ostream& operator<<(ostream& _os, const Board& _board);

public:
	// Public Class Methods
	Board();
	bool isFaceUp(const Letter& letter, const Number number) const;
	bool turnFaceUp(const Letter& letter, const Number number);
	bool turnFaceDown(const Letter& letter, const Number number);
	Card* getCard(const Letter& letter, const Number number);
	void setCard(const Letter& letter, const Number& number, Card* card);
	void reset();

	// Public Class Method for Expert Display
	void setExpertDisplay();
};



#endif
