#include "deck.h"
#include "reward.h"

#ifndef REWARDDECK
#define REWARDDECK

class RewardDeck : public Deck<Reward> {
	//Private Class Variables
	static RewardDeck* rewardDeck;
	vector<Reward*> deck;

	// Private Constructor
	RewardDeck();
public:
	// Public Class Methods
	void shuffle();
	Reward* next();
	bool isEmpty();
	static RewardDeck& make_RewardDeck();
};

#endif