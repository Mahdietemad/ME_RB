#include "card.h"

Card::Card(FaceAnimal _animal, FaceBackground _background): animal(_animal), background(_background) {}

string Card::getAnimalChar() const {
	string animalChar = "?"; //To check if there was an error
	switch (animal) {
	case Crab: animalChar = "C"; break;
	case Penguin: animalChar = "P"; break;
	case Octopus: animalChar = "O"; break;
	case Turtle: animalChar = "T"; break;
	case Walrus: animalChar = "W"; break;
	}
	return animalChar;
}

string Card::getBackgroundChar() const {
	string backgroundChar = "?"; //To check if there was an error
	switch (background) {
	case Red: backgroundChar = "r"; break;
	case Green: backgroundChar = "g"; break;
	case Purple: backgroundChar = "p"; break;
	case Blue: backgroundChar = "b"; break;
	case Yellow: backgroundChar = "y"; break;
	}
	return backgroundChar;
}

string Card::operator()(int row) const {
	if (row == 1) {
		return getBackgroundChar() + getAnimalChar() + getBackgroundChar();
	}
	else if (row == 0 || row == 2) {
		return getBackgroundChar() + getBackgroundChar() + getBackgroundChar();
	}
	else { return "The input int row must be 0, 1, or 2"; } // To check if there is any errors
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
	// Test Card::Card(FaceAnimal _animal, FaceBackground _background)
	cout << "Testing -> Card::Card(FaceAnimal _animal, FaceBackground _background)" << endl;
	// Card c = Card(Crab, Red);
	cout << "The Card constructor is private -> Not sure how to test this" << endl;
	
}
#endif