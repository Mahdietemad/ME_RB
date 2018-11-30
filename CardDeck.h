#include "deck.h"
#include "card.h"

#ifndef CARDDECK
#define CARDDECK

class CardDeck : public Deck<Card> {
	//Private Class Variables
	static CardDeck* cardDeck;
	static int size;
	vector<Card*> deck;

	// Private Constructor
	CardDeck();
public:
	// Public Class Methods
	void shuffle();
	Card* next();
	bool isEmpty();
	static CardDeck& make_CardDeck();
};

#endif
