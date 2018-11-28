#include "cardDeck.h"

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

// Testing the public functions of CardDeck.cpp
#define TEST_CARDDECK (0)
#if TEST_CARDDECK
using std::cout;
using std::endl;
void main() {

}
#endif