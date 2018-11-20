#include <iostream>
#include <string>

using std::ostream;
using std::string;

#ifndef CARD
#define CARD

enum FaceAnimal {Crab, Penguin, Octopus, Turtle, Walrus};
enum FaceBackground {Red, Green, Purple, Blue, Yellow};

class Card {
	FaceAnimal animal;
	FaceBackground background;
	
	Card(FaceAnimal _animal, FaceBackground _background);
	string getAnimalChar();
	string getBackgroundChar();
	string Row(int row);
};

#endif
