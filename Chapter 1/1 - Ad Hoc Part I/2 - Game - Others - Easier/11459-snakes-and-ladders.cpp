#include <iostream>
#include <vector>

using namespace std;

vector<int> players, portal(101, 0), dies;
int t, num_players, num_portals, die_rolls, x, y, p;

int main (int argc, char const *argv[]) {
	
	ios_base::sync_with_stdio(false);

	#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	#endif

	cin >> t;

	while (t--) {
		players.clear();
		portal.assign(101, 0);

		cin >> num_players >> num_portals >> die_rolls;

		players.assign(num_players, 1);
		dies.resize(die_rolls);

		while (num_portals--) {
			cin >> x >> y;
			portal[x] = y;
		}

		for (int i = 0; i < die_rolls; ++i) {
			cin >> dies[i];
		}

		for (int i = 0; i < die_rolls; ++i) {
			p = i % num_players;
			players[p] += dies[i];
			if (players[p] >= 100) {
				players[p] = 100;
				break;
			}
			if (portal[players[p]] != 0) {
				players[p] = portal[players[p]];
			}
			if (players[p] >= 100) {
				players[p] = 100;
				break;
			}
		}


		for (int i = 0; i < num_players; ++i) 
			printf("Position of player %d is %d.\n", (i + 1), players[i]);
		
	}

	
	return 0;
}