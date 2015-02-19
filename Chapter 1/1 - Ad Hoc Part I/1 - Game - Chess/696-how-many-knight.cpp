#include <iostream>
#include <algorithm>

using namespace std;

// http://stackoverflow.com/questions/14816239/how-many-chess-knightshorses-can-be-placed-on-board
int solve(int n, int m){
    if (n > m)
    	swap(n,m);

    if (n == 1)
    	return m;
    if (n == 2)
    	return m / 4 * 4 + (m % 4 == 1 ? 2 : (m % 4 >= 2 ? 4 : 0));

    return (n * m + 1) / 2;
}

int row, col, answer;

int main (int argc, char const *argv[]) {
	
	ios_base::sync_with_stdio(false);

	#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	#endif

	while (cin >> row >> col && row) {

		answer = solve(row, col);

		printf("%d knights may be placed on a %d row %d column board.\n", answer, row, col);	

	}

	return 0;
}