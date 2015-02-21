#include <cstdio>
#include <string>
#include <cmath>

using namespace std;

string input, temp;
int t, k;
char c, grid[100][100];

bool IsMagicSquare () {

	for (int i = 0; i < k; ++i)
		for (int j = 0; j < k; ++j)
			grid[i][j] = input[i * k + j];


	temp.clear();
	for (int j = 0; j < k; ++j)
		for (int i = 0; i < k; ++i)
			temp.push_back(grid[i][j]);
	if (temp != input)
		return false;

	temp.clear();
	for (int i = k - 1; i >= 0; --i)
		for (int j = k - 1; j >= 0; --j)
			temp.push_back(grid[i][j]);
	if (temp != input)
		return false;

	temp.clear();
	for (int j = k - 1; j >= 0; --j)
		for (int i = k - 1; i >= 0; --i)
			temp.push_back(grid[i][j]);
	if (temp != input)
		return false;

	return true;
}

int main (int argc, char const *argv[]) {

	#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	#endif

	scanf("%d\n", &t);

	for (int i = 1; i <= t; ++i) {

		printf("Case #%d:\n", i);

		input.clear();
		do {
			c = getchar();
			if (c >= 'a' && c <= 'z')
				input.push_back(c);
		} while (c != '\n' && c != EOF);

		k = sqrt(input.size());

		if (k * k != input.size() || !IsMagicSquare())
			printf("No magic :(\n");
		else
			printf("%d\n", k);

	}
	
	return 0;
}