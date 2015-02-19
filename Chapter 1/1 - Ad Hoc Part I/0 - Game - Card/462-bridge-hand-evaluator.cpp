#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>

using namespace std;

string card, suits = "SHDC", buffer;
istringstream iss;
int max_suit_count, points;
char max_suit;
map< char, vector<char> > hand;

bool Stopped (vector<char> &cards) {
	int size = cards.size();
	for (auto card : cards)
		if (card == 'A' || (card == 'K' && size > 1) || (card == 'Q' && size > 2))
			return true;
	return false;
}

int main (int argc, char const *argv[]) {
	
	ios_base::sync_with_stdio(false);

	#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	#endif

	while (getline(cin, buffer)) {

		hand.clear();
		iss.clear();
		iss.str(buffer);

		for (auto suit : suits)
			hand[suit] = vector<char>(0);

		while (iss >> card) {
			hand[card[0]].push_back(card[1]);
			hand[card[1]].push_back(card[0]);
		}

		points = 0;

		// rule 1
		points += hand['A'].size() * 4;
		points += hand['K'].size() * 3;
		points += hand['Q'].size() * 2;
		points += hand['J'].size() * 1;

		// rule 2 to 4
		for (auto suit : hand['K']) 
			points -= (hand[suit].size() == 1);

		for (auto suit : hand['Q'])
			points -= (hand[suit].size() <= 2);

		for (auto suit : hand['J'])
			points -= (hand[suit].size() <= 3);

		if (points >= 16) {
			bool all_stopped = true;

			for (auto suit : suits)
				if (!Stopped(hand[suit]))
					all_stopped = false;

			if (all_stopped) {
				cout << "BID NO-TRUMP" << endl;
				continue;
			}
		} 

		// rule 5, 6, 7
		for (auto suit : suits) {
			if (hand[suit].size() == 2)
				points += 1;
			else if (hand[suit].size() <= 1) 
				points += 2;
		}

		if (points >= 14) {
			max_suit_count = 0;
			for (auto suit : suits)
				if (hand[suit].size() > max_suit_count){
					max_suit = suit;
					max_suit_count = hand[suit].size();
				}
			
			printf("BID %c\n", max_suit);

		} else {
			printf("PASS\n");
		}
	}
	
	return 0;
}