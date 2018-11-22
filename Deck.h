#include <random>

using std::shuffle;

#ifndef DECK
#define DECK

template <class C>
class Deck<C> {

public:
	// Public Class Functions
	virtual void shuffle() = 0;
	virtual C* next() = 0;
	virtual bool isEmpty() = 0;

};



#endif
