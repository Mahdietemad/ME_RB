#include "cardDeck.h"

CardDeck* CardDeck::cardDeck = nullptr;

int CardDeck::size = 25;

CardDeck::CardDeck() {}

void CardDeck::shuffle() {
	random_shuffle(deck.begin(), deck.end());
}

Card* CardDeck::next() {
	if (isEmpty()) { return nullptr; }
	else {
		Card* item = deck.back();
		deck.pop_back();
		size--;
		return item;
	}
}

bool CardDeck::isEmpty() {
	if (deck.size() == 1) {
		return true;
	}
	else { return false; }
}

CardDeck& CardDeck::make_CardDeck() {
	if (cardDeck == nullptr) {
		cardDeck = new CardDeck();
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				Card* card = new Card(FaceAnimal(i), FaceBackground(j));
				cardDeck->deck.push_back(card);
			}
		}
		size = 25;
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