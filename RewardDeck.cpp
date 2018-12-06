#include "rewardDeck.h"

RewardDeck::RewardDeck() {}

RewardDeck& RewardDeck::make_RewardDeck() {
	RewardDeck* rewardDeck = new RewardDeck();
	Reward* reward1 = new Reward(1);
	Reward* reward2 = new Reward(1);
	Reward* reward3 = new Reward(1);
	Reward* reward4 = new Reward(2);
	Reward* reward5 = new Reward(2);
	Reward* reward6 = new Reward(3);
	Reward* reward7 = new Reward(4);
	rewardDeck->deck.push_back(reward1);
	rewardDeck->deck.push_back(reward2);
	rewardDeck->deck.push_back(reward3);
	rewardDeck->deck.push_back(reward4);
	rewardDeck->deck.push_back(reward5);
	rewardDeck->deck.push_back(reward6);
	rewardDeck->deck.push_back(reward7);
	return *rewardDeck;
}

RewardDeck::~RewardDeck() {
	for (int i = 0; i < deck.size(); i++) {
		delete deck[i];
	}
}

// Testing the public functions of RewardDeck.cpp
#define TEST_REWARDDECK (0)
#if TEST_REWARDDECK
using std::cout;
using std::endl;
void main() {

}
#endif