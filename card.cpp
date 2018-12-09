#include "card.h"

Card::Card(FaceAnimal _animal, FaceBackground _background): animal(_animal), background(_background) {}

string Card::getAnimalChar() const {
	switch (animal) {
	case Crab: return "C";
	case Penguin: return "P";
	case Octopus: return "O";
	case Turtle: return "T";
	case Walrus: return "W";
	}
	throw "For some reason this card has no animal"; // To check if there was an error
}


string Card::getBackgroundChar() const {
	switch (background) {
	case Red: return "r";
	case Green: return "g";
	case Purple: return "p";
	case Blue: return "b";
	case Yellow: return "y";
	}
	throw "For some reason this card has no background"; //To check if there was an error
}

string Card::operator()(int row) const {
	if (row == 1) {
		return getBackgroundChar() + getAnimalChar() + getBackgroundChar();
	}
	else if (row == 0 || row == 2) {
		return getBackgroundChar() + getBackgroundChar() + getBackgroundChar();
	}
	else { throw "The input int row must be 0, 1, or 2"; } // To check if there is any errors
}

Card::operator FaceAnimal() const {
	return animal;
}

Card::operator FaceBackground() const {
	return background;
}

Card::~Card() {}

// Testing the public functions of card.cpp
#define TEST_CARD (0)
#if TEST_CARD
using std::cout;
using std::endl;
void main() {
	// The public methods for Card will be tested inside of CardDeck.cpp
	cout << "The public methods for Card will be tested inside of cardDeck.cpp" << endl;

}
#endif