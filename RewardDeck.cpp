#include "rewardDeck.h"

RewardDeck* RewardDeck::rewardDeck = nullptr;

RewardDeck::RewardDeck() {}

RewardDeck& RewardDeck::make_RewardDeck() {
	if (rewardDeck == nullptr) {
		rewardDeck = new RewardDeck();
		int n = 3;
		for (int i = 1; i < 5; i++) {
			for (int j = 0; j < n; i++) {
				Reward* r = new Reward(i);
				rewardDeck->deck.push_back(r);
			}
			if (n > 1) { n--; }
		}
	}
	rewardDeck->shuffle();
	return *rewardDeck;
}

// Testing the public functions of RewardDeck.cpp
#define TEST_REWARDDECK (0)
#if TEST_REWARDDECK
using std::cout;
using std::endl;
void main() {

}
#endif