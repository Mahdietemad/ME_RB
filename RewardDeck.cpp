#include "RewardDeck.h"

RewardDeck::RewardDeck() {}

RewardDeck& RewardDeck::make_RewardDeck() {
	RewardDeck* rd = new RewardDeck();
	int n = 3;
	for (int i = 1; i < 5; i++) {
		for (int j = 0; j < n; i++) {
			Reward* r = new Reward(i);
			rd->deck.push_back(r);
		}
		if (n > 1) { n--; }
	}
	return *rd;
}