#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string piece;
int t, row, col;

int main (int argc, char const *argv[]) {
	
	ios_base::sync_with_stdio(false);

	#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	#endif

	cin >> t;

	while (t--) {
		cin >> piece >> row >> col;

		if (piece == "r")
			cout << min (row, col) << endl;
		else if (piece == "K")
			cout << ((row + 1) / 2) * ((col + 1 ) / 2) << endl;
		else if (piece == "k")
			cout << (row * col + 1) / 2 << endl;	// http://mathworld.wolfram.com/KnightsProblem.html
		else if (piece == "Q")
			cout << min (row, col) << endl;
	}
	
	return 0;
}