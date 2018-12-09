#include "game.h"

Game::Game() {
	roundNum = 0;
}

int Game::getRound() const { return roundNum; }

void Game::nextRound() {
	board.reset();
	roundNum++;
	for (int i = 0; i < players.size(); i++) {
		players[i]->setActive(true);
	}
}

void Game::reset() {
	board.reset();
}

void Game::addPlayer(const Player& player) {
	for (int i = 0; i < players.size(); i++) {
		if (players[i]->getSide() == player.getSide()) {
			delete players[i];
			players.erase(players.begin()+ i);
		}	
	}
	players.push_back(const_cast<Player*>(&player));
	if (players.size() == 1) {
		currPlayer = players[0];
	}
}

Player& Game::getPlayer(Side side) const { 
	for (int i = 0; i < players.size(); i++) {
		if (players[i]->getSide() == side) {
			return *players[i];
		}
	}
	throw "There is no player to side entered";
}

const Card* Game::getPreviousCard() const { return prevCard; }

const Card* Game::getCurrentCard() const { return currCard; }

void Game::setCurrentCard(const Card* card) {
	const Letter& letter = board.getLetter(card);
	const Number& number = board.getNumber(card);
	if (board.turnFaceUp(letter, number) == false) {
		throw "This card is already face up";
	}
	prevCard = currCard;
	currCard = card;
}

const Card* Game::getCard(const Letter& letter, const Number& number) {
	return board.getCard(letter, number); 
}

void Game::setCard(const Letter& letter, const Number& number, const Card* card) {
	board.setCard(letter, number, card);
}

void Game::setExpertDisplay() {
	board.setExpertDisplay();
}

Game::~Game() {
	delete currPlayer;
	delete prevCard;
	delete currCard;
}

ostream& operator<<(ostream& _os, const Game& _game) {
	_os << _game.board << endl;
	for (int i = 0; i < _game.players.size(); i++) {
		_os << *(_game.players[i]) << endl;
	}
	return _os;
}

void Game::octopus() {
	Letter currLetter = board.getLetter(currCard);
	Number currNumber = board.getNumber(currCard);
	bool flag = true;
	string userInput;
	while (flag) {
		cout << "Please select a card in the same row or column to exhange positions" << endl;
		cout << "Ex: " << currLetter << "z or z" << currNumber << endl;
		cin >> userInput;
		Letter userLetter = stringtoLetter(userInput[0]);
		Number userNumber = stringtoNumber(userInput[1]);

		if (((currLetter == userLetter) && (currNumber != userNumber)) || ((currLetter != userLetter) && (currNumber == userNumber))) {
			setCard(userLetter, userNumber, currCard);
			flag = false;
		}
		else {
			cout << "The card you selected is invalid" << endl << endl;
		}
	}
}

void Game::penguin() {
	bool flag = true;
	string userInput;
	while (flag) {
		cout << "Please select a card to turn face down." << endl;
		cin >> userInput;
		Letter userLetter = stringtoLetter(userInput[0]);
		Number userNumber = stringtoNumber(userInput[1]);

		if (board.turnFaceDown(userLetter, userNumber)) {
			flag = false;
		}
		else {
			cout << "The card you selected is invalid" << endl << endl;
		}
	}
}

bool Game::isWalrus() {
	return FaceAnimal(*currCard) == Walrus;
}

bool Game::walrus(const Letter& letter, const Number& number) {
	return !board.isFaceUp(letter, number);
}

bool Game::crab() {
	return FaceAnimal(*currCard) == Crab;
}

bool Game::turtle() {
	return FaceAnimal(*currCard) == Turtle;
}

bool Game::isOctopus() {
	return FaceAnimal(*currCard) == Octopus;
}

bool Game::isPenguin() {
	return FaceAnimal(*currCard) == Penguin;
}

Letter Game::stringtoLetter(char c) {
	switch (c) {
	case 'A': return A;
	case 'B': return B;
	case 'C': return C;
	case 'D': return D;
	case 'E': return E;
	}
	throw "The entered char does not have a corresponding Letter";
}

Number Game::stringtoNumber(char c) {
	switch (c) {
	case '1': return One;
	case '2': return Two;
	case '3': return Three;
	case '4': return Four;
	case '5': return Five;
	}
	throw "The entered char does not have a corresponding Number";
}