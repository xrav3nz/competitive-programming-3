#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int total, strike, t, c[26];
string answer, guess;

int main (int argc, char const *argv[]) {
	
	ios_base::sync_with_stdio(false);

	#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	#endif

	while (cin >> t) {
		if (t == -1)
			break;

		getline(cin, answer);
		getline(cin, answer);
		getline(cin, guess);

		total = strike = 0;
		memset(c, 0, sizeof(c));

		for (int i = 0; answer[i]; ++i) {
			if (answer[i] < 'a' || answer[i] > 'z')
				continue;
			if (c[answer[i] - 'a'] == 0) {
				c[answer[i] - 'a'] = 1;
				++total;
			}
		}

		for (int i = 0; guess[i] && total && strike < 7; ++i) {
			if (guess[i] < 'a' || guess[i] > 'z' || c[guess[i] - 'a'] == 2)
				continue;
			if (c[guess[i] - 'a'] == 0) 
				++strike;
			else if (c[guess[i] - 'a'] == 1)
				--total;
			c[guess[i] - 'a'] = 2;
		}

		printf("Round %d\n", t);
		if (total == 0)
			printf("You win.\n");
		else if (strike >= 7)
			printf("You lose.\n");
		else
			printf("You chickened out.\n");
	}
	
	
	return 0;
}