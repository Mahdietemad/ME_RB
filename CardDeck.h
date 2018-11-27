#include "Deck.h"
#include "card.h"

#ifndef CARDDECK
#define CARDDECK

class CardDeck : public Deck<Card> {
	CardDeck();
public:
	static CardDeck& make_CardDeck();
};

#endif
