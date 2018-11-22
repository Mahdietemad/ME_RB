#include "card.h"

Card::Card(FaceAnimal _animal, FaceBackground _background): animal(_animal), background(_background) {}

string Card::getAnimalChar() {
	string animalChar = "?"; //To check if there was an error
	if (animal == Crab) { animalChar = "C"; }
	else if (animal == Penguin) { animalChar = "P"; }
	else if (animal == Octopus) { animalChar = "O"; }
	else if (animal == Turtle) { animalChar = "T"; }
	else if (animal == Walrus) { animalChar = "W"; }
	return animalChar;
}

string Card::getBackgroundChar() {
	string backgroundChar = "?"; //To check if there was an error
	if (background == Red) { backgroundChar = "r"; }
	else if (background == Green) { backgroundChar = "g"; }
	else if (background == Purple) { backgroundChar = "p"; }
	else if (background == Blue) { backgroundChar = "b"; }
	else if (background == Yellow) { backgroundChar = "y"; }
	return backgroundChar;
}

string Card::operator()(int row) {
	if (row == 1) {
		return getBackgroundChar() + getAnimalChar() + getBackgroundChar();
	}
	else { // For row == (0 || 2)
		return getBackgroundChar() + getBackgroundChar() + getBackgroundChar();
	}
}

Card::operator FaceAnimal() {
	return animal;
}

Card::operator FaceBackground() {
	return background;
}
