#include "game.h"

int Game::getRound() { return roundNum; }

void Game::nextRound() {
	board.reset();
	roundNum++;
}

void Game::addPlayer(const Player& player) {
	for (int i = 0; i < 4; i++) {
		if (players[i]->getName() == player.getName()) {
			delete players[i];
		}
	}
	players[int(player.getSide())] = &player;
}

Player& Game::getPlayer(Side side) { return *players[int(side)]; }

const Card* Game::getPreviousCard() const { return prevCard; }

const Card* Game::getCurrentCard() const { return currCard; }

void Game::setCurrentCard(const Card* card) {
	prevCard = currCard;
	currCard = card;
}

Card* Game::getCard(const Letter& letter, const Number& number) {
	return board.getCard(letter, number); 
}

void Game::setCard(const Letter& letter, const Number& number, Card* card) {
	return board.setCard(letter, number, card);
}