#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> lights;
int temp, start;

bool Sync () {
	for (auto i : lights)
		if (start % (i * 2) >= i - 5)
			return false;
	return true;
}

int main (int argc, char const *argv[]) {

	// ios_base::sync_with_stdio(false);

	#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	#endif

	while (scanf("%d", &temp) != EOF && temp != 0) {

		lights.clear();

		lights.push_back(temp);
		while (scanf("%d", &temp) != EOF && temp != 0)
			lights.push_back(temp);

		sort (lights.begin(), lights.end());

		start = lights[0] - 5 + 1;

		while (!Sync() && start <= 18000)
			++start;

		if (start > 18000)
			printf("Signals fail to synchronise in 5 hours\n");
		else
			printf("%02d:%02d:%02d\n", start / 3600, start % 3600 / 60, start % 60);	
	}


	
	return 0;
}