#include <iostream>
#include <string>

using std::ostream;
using std::string;

#ifndef CARD
#define CARD

enum FaceAnimal {Crab, Penguin, Octopus, Turtle, Walrus};
enum FaceBackground {Red, Green, Purple, Blue, Yellow};

class Card {
	// Private Class Variables
	FaceAnimal animal;
	FaceBackground background;
	
	// Private Class Functions
	Card(FaceAnimal _animal, FaceBackground _background);
	string getAnimalChar() const;
	string getBackgroundChar() const;

	// Friend Accesses
	friend class CardDeck;

public:
	// Public Class Operators
	string operator()(int row) const ; // Not sure if this operator should be public or private
	operator FaceAnimal() const;
	operator FaceBackground() const;

	// Destructor
	~Card();
};

#endif
