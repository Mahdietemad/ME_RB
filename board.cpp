#include "board.h"

Board::Board() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cardBoard[i][j] = nullptr;
			boolBoard[i][j] = false;
		}
	}
	if (boardDeck == nullptr){
		boardDeck = &(boardDeck->make_CardDeck());
		boardDeck->shuffle();
	}
	if (boardDeck->isEmpty() == false) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (i != 2 && j != 2) {
					cardBoard[i][j] = boardDeck->next();
				}
			}
		}
	}
	else {
		throw "No More Cards";
	}
}

void Board::setExpertDisplay() {
	expertDisplay = true;
}


bool Board::isFaceUp(const Letter& letter, const Number number) const {
	if (int(letter) == 2 && int(number) == 2) {
		throw "C3 in not a valid selection";
	}
	else { return boolBoard[int(letter)][int(number)]; }
}

bool Board::turnFaceUp(const Letter& letter, const Number number) {
	if (isFaceUp(letter, number)) { return false; }
	else {
		boolBoard[int(letter)][int(number)] = true;
		expertBoard.push_back(cardBoard[int(letter)][int(number)]);
		expertLetter.push_back(letter);
		expertNumber.push_back(number);
		return true;
	}
}

bool Board::turnFaceDown(const Letter& letter, const Number number) {
	if (isFaceUp(letter, number) == false) { return false; }
	else {
		boolBoard[int(letter)][int(number)] = false;
		for (int i = 0; i < expertBoard.size(); i++) {
			if (expertBoard[i] == cardBoard[int(letter)][int(number)]) {
				expertBoard.erase(expertBoard.begin() + i);
				expertLetter.erase(expertLetter.begin() + i);
				expertNumber.erase(expertNumber.begin() + i);
			}
		}
		return true;
	}
}

const Card* Board::getCard(const Letter& letter, const Number number) {
	if (int(letter) == 2 && int(number) == 2) {
		throw "C3 in not a valid selection";
	}
	else { return cardBoard[int(letter)][int(number)]; }
}

void Board::setCard(const Letter& letter, const Number& number, const Card* card) {
	Letter oldLetter;
	Number oldNumber;
	bool cardBool;
	if (int(letter) == 2 && int(number) == 2) {
		throw "C3 in not a valid selection";
	}
	else {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (cardBoard[i][j] == card) {
					oldLetter = Letter(i);
					oldNumber = Number(j);
					cardBool = boolBoard[i][j];
				}
			}
		}
		cardBoard[int(oldLetter)][int(oldNumber)] = cardBoard[int(letter)][int(number)];
		boolBoard[int(oldLetter)][int(oldNumber)] = boolBoard[int(letter)][int(number)];
		cardBoard[int(letter)][int(number)] = card;
		boolBoard[int(letter)][int(number)] = cardBool;
		for (int i = 0; i < expertBoard.size(); i++) {
			if (expertBoard[i] == card) {
				expertLetter[i] = letter;
				expertNumber[i] = number;
			}
			else if (expertBoard[i] == cardBoard[int(oldLetter)][int(oldNumber)]) {
				expertLetter[i] = oldLetter;
				expertNumber[i] = oldNumber;
			}	
		}
	}
}

void Board::reset() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j<5; j++) {
			boolBoard[i][j] = false;
		}
	}
	expertBoard.clear();
	expertLetter.clear();
	expertNumber.clear();
}

Board::~Board() {
	delete boardDeck;
	delete[] cardBoard;
	delete[] boolBoard;
	for (int i = 0; i < expertBoard.size(); i++) {
		delete expertBoard[i];
	}
}

ostream& operator<<(ostream& _os, const Letter& _letter) {
	switch (_letter) {
	case A: _os << "A"; break;
	case B: _os << "B"; break;
	case C: _os << "C"; break;
	case D: _os << "D"; break;
	case E: _os << "E"; break;
	}
	return _os;
}

ostream& operator<<(ostream& _os, const Number& _number) {
	switch (_number) {
	case One: _os << "1"; break;
	case Two: _os << "2"; break;
	case Three: _os << "3"; break;
	case Four: _os << "4"; break;
	case Five: _os << "5"; break;
	}
	return _os;
}

ostream& operator<<(ostream& _os, const Board& _board) {
	// Expert Display
	// Might need to be edited if the card don't fit on the screen
	if (_board.expertDisplay) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < _board.expertBoard.size(); j++) {
				_os << _board.expertBoard[j]->operator()(i);
				if (j != _board.expertBoard.size() - 1) {
					_os << " ";
				}

			}
			_os << endl;
		}
		for (int i = 0; i < _board.expertBoard.size(); i++) {
			_os << _board.expertLetter[i] << _board.expertNumber[i];
			if (i != _board.expertBoard.size() - 1) {
				_os << " ";
			}
		}
		_os << endl;
	}
	// Normal Display
	else {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 3; j++) {
				if (j == 1) {
					_os << Letter(i) << " ";
				}
				else {
					_os << "  ";
				}
				for (int k = 0; k < 5; k++) {
					if (j == 2 && k == 2) {
						_os << "   ";
					}
					else if (_board.boolBoard[i][k]){
						_os << _board.cardBoard[i][k]->operator()(j);
					}
					else {
						_os << "zzz";
					}
					if (k != 4) {
						_os << " ";
					}
				}
				_os << endl;
			}
			_os << endl;
		}
		_os << "  ";
		for (int i = 0; i < 5; i++) {
			_os << " " << Number(i) << " ";
			if (i != 4) {
				_os << " ";
			}
		}
		_os << endl;
	}
	return _os;
}

const Letter Board::getLetter(const Card* card) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (cardBoard[i][j] == card) {
				return Letter(i);
			}
		}
	}
	throw "Card not found";
}

const Number Board::getNumber(const Card* card) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (cardBoard[i][j] == card) {
				return Number(j);
			}
		}
	}
	throw "Card not found";
}
