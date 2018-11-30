#include <algorithm>
#include <vector>

using std::random_shuffle;
using std::vector;

#ifndef DECK
#define DECK

template <class C>
class Deck {
public:
	// Public Class Methods
	virtual void shuffle() = 0;	
	virtual C* next() = 0; 
	virtual bool isEmpty() = 0; 
};

#endif
