#include "CardDeck.h"

CardDeck::CardDeck() { }

CardDeck& CardDeck::make_CardDeck() {
	CardDeck* cd = new CardDeck();
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			Card* c = new Card(FaceAnimal(i), FaceBackground(j));
			cd->deck.push_back(c);
		}
	}
	cd->shuffle();
	return *cd;
}




