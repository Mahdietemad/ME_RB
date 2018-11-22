#include "player.cpp"

using std::cout;
//tesing main

int main() {
	Side s = top;
	string n = "Reece";
	Player p = Player(n, s);
	cout << p;
	return 0;
}