#include <iostream>
#include <cmath>

using namespace std;

const int DEG_PER_NUM = 360 / 40;
const int FULL_TURN = 40;

int init, a, b, c, total;

int main (int argc, char const *argv[]) {
	
	ios_base::sync_with_stdio(false);

	#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	#endif

	while (cin >> init >> a >> b >> c) {
		if (!init && !a && !b && !c)
			break;

		total = 3 * FULL_TURN;
		total += (init - a < 0) ? (init - a + FULL_TURN) : (init - a);
		total += (b - a < 0) ? (b - a + FULL_TURN) : (b - a);
		total += (b - c) < 0 ? (b - c+ FULL_TURN) : (b - c);

		cout << total * DEG_PER_NUM << endl;
	}
	
	return 0;
}