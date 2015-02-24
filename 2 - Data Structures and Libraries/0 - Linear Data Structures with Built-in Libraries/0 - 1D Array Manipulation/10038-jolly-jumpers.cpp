#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>

using namespace std;

vector<int> seq;
bitset<3001> diff;
int n;

bool IsJolly () {
	if (n == 1)
		return true;

	diff.reset();

	for (int i = 0; i < n - 1; ++i) 
		diff[abs(seq[i] - seq[i + 1])] = true;

	for (int i = 1; i < n; ++i)
		if (diff[i] == false)
			return false;

	return true;
}

int main (int argc, char const *argv[]) {
	
	ios_base::sync_with_stdio(false);

	#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	#endif

	while (cin >> n) {
		seq.resize(n);
		for (int i = 0; i < n; ++i) 
			cin >> seq[i];
		if (IsJolly())
			cout << "Jolly" << endl;
		else
			cout << "Not jolly" << endl;
	}
	
	return 0;
}