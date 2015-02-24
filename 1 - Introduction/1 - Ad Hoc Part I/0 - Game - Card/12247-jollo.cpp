#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a(3), b(3);
bool used[53];
int answer;

bool DFS (vector<int> v1, vector<int> v2) {
	sort (v1.begin(), v1.end());
	sort (v2.begin(), v2.end());
	int win;
	do {
		do {
			win = 0;
			for (int i = 0; i < 3; ++i) {
				if (v1[i] < v2[i])
					++win;
			}
			if (win < 2)
				return false;
		} while (next_permutation(v2.begin(), v2.end()));
	} while (next_permutation(v1.begin(), v1.end()));
	return true;
}

int main (int argc, char const *argv[]) {
	
	ios_base::sync_with_stdio(false);

	#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	#endif

	while (cin >> a[0] >> a[1] >> a[2] >> b[0] >> b[1]) {
		if (!a[0] && !a[1] && !a[2] && !b[0] && !b[1])
			break;

		used[a[0]] = 1;
		used[a[1]] = 1;
		used[a[2]] = 1;
		used[b[0]] = 1;
		used[b[1]] = 1;

		answer = -1;

		for (int i = 1; i <= 52 && answer < 0; ++i) {
			if (!used[i]) {
				b[2] = i;
				if (DFS(a, b))
					answer = i;
			}
		}

		used[a[0]] = 0;
		used[a[1]] = 0;
		used[a[2]] = 0;
		used[b[0]] = 0;
		used[b[1]] = 0;

		printf("%d\n", answer);
	}
	
	return 0;
}