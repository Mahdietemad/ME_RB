#include "cardDeck.h"

CardDeck* CardDeck::cardDeck = nullptr;

CardDeck::CardDeck() {}

CardDeck& CardDeck::make_CardDeck() {
	if (cardDeck == nullptr) {
		cardDeck = new CardDeck();
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				Card* card = new Card(FaceAnimal(i), FaceBackground(j));
				cardDeck->deck.push_back(card);
			}
		}
		cardDeck->shuffle();
		return *cardDeck;
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