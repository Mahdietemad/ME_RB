#include "game.h"

Game::Game() {}

int Game::getRound() const { return roundNum; }

void Game::nextRound() {
	board.reset();
	roundNum++;
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
}

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

ostream& operator<<(ostream& _os, const Game& _game) {
	_os << _game.board << endl;
	for (int i = 0; i < _game.players.size(); i++) {
		_os << _game.players[i] << endl;
	}
	return _os;
}