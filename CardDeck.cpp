#include "cardDeck.h"

CardDeck::CardDeck() {}

CardDeck& CardDeck::make_CardDeck() {
	CardDeck* cardDeck = new CardDeck;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			Card* card = new Card(FaceAnimal(i), FaceBackground(j));
			cardDeck->deck.push_back(card);
		}
	}
	return *cardDeck;	
}

CardDeck::~CardDeck() {
	for (int i = 0; i < deck.size(); i++) {
		delete deck[i];
	}
}

// Testing the public functions of CardDeck.cpp
#define TEST_CARDDECK (0)
#if TEST_CARDDECK
using std::cout;
using std::endl;
void main() {

}
#endif