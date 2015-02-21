#include <cstdio>
#include <cstring>

int card[5][5], called[76], numbers[75], t, free, b;


bool BINGO () {

	bool bingo;

	// check every row
	for (int i = 0; i < 5; ++i) {
		bingo = true;
		for (int j = 0; j < 5; ++j) 
			if (!called[ card[i][j] ]) {
				bingo = false;
				break;
			}
		if (bingo) 
			return true;
	}

	// check every column
	for (int j = 0; j < 5; ++j) {
		bingo = true;
		for (int i = 0; i < 5; ++i) 
			if (!called[ card[i][j] ]) {
				bingo = false;
				break;
			}
		if (bingo)
			return true;
	}

	// check diagonals
	bingo = true;
	for (int i = 0, j = 0; i < 5; ++i, ++j)
		if (!called[ card[i][j] ]) {
			bingo = false;
			break;
		}
	if (bingo)
		return true;

	bingo = true;
	for (int i = 0, j = 4; i < 5; ++i, --j)
		if (!called[ card[i][j] ]) {
			bingo = false;
			break;
		}
	if (bingo)
		return true;

	return false;
}

int main (int argc, char const *argv[]) {

	#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	#endif

	scanf("%d\n", &t);

	for (int T = 0; T < t; ++T) {

		memset(called, 0, sizeof(called));

		card[2][2] = 0;
		called[0] = 1;

		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				if (i == 2 && j == 2)
					++j;
				scanf("%d", &card[i][j]);
			}
		}

		for (int i = 0; i < 75; ++i)
			scanf("%d", &numbers[i]);

		for (b = 0; b < 4; ++b) {
			called[ numbers[b] ] = 1;
		}

		while (!BINGO()) {
			called[ numbers[b] ] = 1;
			++b;
		}

		printf("BINGO after %d numbers announced\n", b);

	}
	
	return 0;
}