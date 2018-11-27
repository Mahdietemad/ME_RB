#include "card.h"

Card::Card(FaceAnimal _animal, FaceBackground _background): animal(_animal), background(_background) {}

string Card::getAnimalChar() {
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

string Card::getBackgroundChar() {
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
