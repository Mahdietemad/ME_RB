#include "deck.h"
#include "reward.h"

#ifndef REWARDDECK
#define REWARDDECK

class RewardDeck : public Deck<Reward> {
	static RewardDeck* rewardDeck;

	RewardDeck();
public:
	static RewardDeck& make_RewardDeck();
};

#endif