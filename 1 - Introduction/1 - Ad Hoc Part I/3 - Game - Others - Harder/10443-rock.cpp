#include <cstdio>

int win[256], moves[4][2] = {
	1, 0,
	-1, 0,
	0, 1,
	0, -1
}, row, col, t, days;
char grid[102][102], new_grid[102][102], c;

int main (int argc, char const *argv[]) {

	#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	#endif

	win['R'] = 'P';
	win['P'] = 'S';
	win['S'] = 'R';

	scanf("%d\n", &t);
	
	for (int T = 0; T < t; ++T) {
		if (T) printf("\n");

		scanf("%d %d %d\n", &row, &col, &days);

		for (int i = 1; i <= row; ++i) {
			for (int j = 1; j <= col; ++j) 
				grid[i][j] = getchar();
			c = getchar();
		}

		while (days--) {
			for (int i = 1; i <= row; ++i)
				for (int j = 1; j <= col; ++j)
					for (int k = 0; k < 4; ++k) {
						if (win[grid[i][j]] == grid[i + moves[k][0]][j + moves[k][1]]) {
							new_grid[i][j] = win[grid[i][j]];
							break;
						} else
							new_grid[i][j] = grid[i][j];
					}

			for (int i = 1; i <= row; ++i)
				for (int j = 1; j <= col; ++j)
					grid[i][j] = new_grid[i][j];
		}

		for (int i = 1; i <= row; ++i){
			for (int j = 1; j <= col; ++j)
				printf("%c", grid[i][j]);
			printf("\n");
		}
	}

	return 0;
}