#include "board.h"

#include <stdexcept>
#include <iostream>

using std::out_of_range;
using std::cerr;
using std::endl;

bool Board::isFaceUp(const Letter& letter, const Number number) const {
	try {
		if (int(letter) == 2 && int(number) == 2) {
			throw out_of_range("C3 is not a valid selection");
		}
		return boolBoard[int(letter)][int(number)];
	}
	catch (const out_of_range& error) {
		cerr << "Out of range error: " << error.what() << endl;
	}
}

bool Board::turnFaceUp(const Letter& letter, const Number number) {
	if (isFaceUp(letter, number)) {	return false; }
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
			if (expertBoard[i] != nullptr) {
				if (expertBoard[i] == cardBoard[int(letter)][int(number)]) {
					expertBoard[i] = nullptr;
				}
			}
		}
		return true;
	}
}

Card* Board::getCard(const Letter& letter, const Number number) {
	try {
		if (int(letter) == 2 && int(number) == 2) {
			throw out_of_range("C3 is not a valid selection");
		}
		return cardBoard[int(letter)][int(number)];
	}
	catch (const out_of_range& error) {
		cerr << "Out of range error: " << error.what() << endl;
	}
}

void Board::setCard(const Letter& letter, const Number& number, Card* card) {
	try {
		if (int(letter) == 2 && int(number) == 2) {
			throw out_of_range("C3 is not a valid selection");
		}
		cardBoard[int(letter)][int(number)] = card;
		for (int i = 0; i < expertBoard.size(); i++) {
			if (expertBoard[i] != nullptr) {
				if (expertBoard[i] == card) {
					expertLetter[i] = letter;
					expertNumber[i] = number;
				}
			}
		}
	}
	catch (const out_of_range& error) {
		cerr << "Out of range error: " << error.what() << endl;
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
				if (_board.expertBoard[j] != nullptr) {
					_os << _board.expertBoard[j]->operator()(i);
					if (j != _board.expertBoard.size() - 1) {
						_os << " ";
					}
				}
			}
			_os << endl;
		}
		for (int i = 0; i < _board.expertBoard.size(); i++) {
			if (_board.expertBoard[i] != nullptr) {
				_os << _board.expertLetter[i] << _board.expertNumber[i];
				if (i != _board.expertBoard.size() - 1) {
					_os << " ";
				}
			}
		}
		_os << endl;
	}
	// Normal Display
	else {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 3; j++) {
				if (j = 1) {
					_os << Letter(i) << " ";
				}
				else {
					_os << "  ";
				}
				for (int k = 0; k < 5; k++) {
					if (j == 2 & k == 2) {
						_os << "   ";
					}
					else {
						_os << _board.cardBoard[i][j]->operator()(j);
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