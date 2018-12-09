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

// Testing the public functions of CardDeck.cpp & card.cpp
#define TEST_CARDDECK (0)
#if TEST_CARDDECK
using std::cout;
using std::endl;
void main() {
	// Printing the non-shuffled CardDeck
	CardDeck* cardDeck;
	cardDeck = &(cardDeck->make_CardDeck());
	cout << "Printing cards of the non-suffled CardDeck" << endl;
	for (int i = 0; i < 25; i++) {
		Card* card = cardDeck->next();
		for (int j = 0; j < 3; j++) {
			(*card)(j);
		}
		cout << endl;
		delete card;
	}
	if (cardDeck->isEmpty()) {
		cout << "This CardDeck is now empty" << endl;
	}
	delete cardDeck;

	// Printing a shuffled CardDeck
	CardDeck* cardDeck;
	cardDeck = &(cardDeck->make_CardDeck());
	cardDeck->shuffle();
	cout << "Printing cards of a suffled CardDeck" << endl;
	for (int i = 0; i < 25; i++) {
		Card* card = cardDeck->next();
		for (int j = 0; j < 3; j++) {
			(*card)(j);
		}
		cout << endl;
		delete card;
	}
	delete cardDeck;

}
#endif