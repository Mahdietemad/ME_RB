#include "card.h"
#include "deck.h"

#ifndef CARDDECK
#define CARDDECK

class CardDeck : public Deck<Card> {
	// Private Constructor
	CardDeck();

public:
	// Public Class Methods
	static CardDeck& make_CardDeck();

	// Destructor
	~CardDeck();
};

#endif
