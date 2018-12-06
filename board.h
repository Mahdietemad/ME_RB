#include "cardDeck.h"

#include <string>
#include <iostream>
#include <stdexcept>

using std::out_of_range;
using std::cerr;
using std::endl;
using std::string;
using std::vector;

#ifndef BOARD
#define BOARD

enum Letter {A, B, C, D, E};
enum Number {One, Two, Three, Four, Five};

class Board {
	// Private Class Variables
	const Card* cardBoard[5][5];
	bool boolBoard[5][5];
	CardDeck* boardDeck;

	// Private Class Variables for Expert Display Mode
	bool expertDisplay = false;
	vector<const Card*> expertBoard;
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
	const Card* getCard(const Letter& letter, const Number number);
	void setCard(const Letter& letter, const Number& number, const Card* card);
	void reset();

	// Destructor
	~Board();
	
	// Additional Public Class Methods
	const Letter getLetter(const Card*);
	const Number getNumber(const Card*);

	// Public Class Method for Expert Display
	void setExpertDisplay();
};



#endif
