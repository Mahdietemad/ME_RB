#include <algorithm>
#include <vector>

using std::random_shuffle;
using std::vector;

#ifndef DECK
#define DECK

template <class C>
class Deck {
protected:
	vector<C*> deck;

public:

	// Public Class Functions
	void shuffle() {
		random_shuffle(deck.begin(), deck.end());
	}
	
	C* next() {
		if (deck.isEmpty()) { return nullptr; }
		else {
			C* item = deck.back();
			deck.pop_back_back();
			return item;
		}
	}

	bool isEmpty() {
		return deck.empty();
	}

};

#endif
