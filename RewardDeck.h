#include "reward.h"
#include "deck.h"

#ifndef REWARDDECK
#define REWARDDECK

class RewardDeck : public Deck<Reward> {
	// Private Constructor
	RewardDeck();

public:
	// Public Class Methods
	static RewardDeck& make_RewardDeck();

	// Destructor
	~RewardDeck();
};

#endif