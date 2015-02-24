#include <iostream>
#include <string>
#include <vector>

using namespace std;

int t, y, x, pointer;
vector<string> pile(52);

int GetValue (char c) {
	if (c < '9' && c > '2')
		return (c - '0');
	return 10;
}

int main (int argc, char const *argv[]) {
	
	ios_base::sync_with_stdio(false);

	#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	#endif

	cin >> t;

	for (int i = 1; i <= t; ++i) {

		for (int j = 0; j <= 51; ++j) {
			cin >> pile[j];
		}
		y = 0;

		// taking out the first 25
		pointer = 51 - 25;

		for (int k = 0; k < 3; ++k) {
			x = GetValue(pile[pointer][0]);
			y += x;
			pointer -= 1 + (10 - x);
		}

		if (pointer + 1 >= y)
			printf("Case %d: %s\n", i, pile[y].c_str());
		else
			printf("Case %d: %s\n", i, pile[y - (pointer + 1) + (51 - 25)].c_str());
	}
	
	return 0;
}