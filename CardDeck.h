#include "deck.h"
#include "card.h"

#ifndef CARDDECK
#define CARDDECK

class CardDeck : public Deck<Card> {
	static CardDeck* cardDeck;

	CardDeck();
public:
	static CardDeck& make_CardDeck();
};

#endif
