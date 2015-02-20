// I kept getting WA with my last code, so I deleted everything and re-code the following solution up, AC the first time - -''

#include <iostream>
#include <cstring>

using namespace std;

char field[101][101];
int t, row, col;

int moves[8][2] = {
	-1, -1,
	-1, 0,
	-1, 1,
	0, -1,
	0, 1,
	1, -1,
	1, 0,
	1, 1
};

bool IsLegal (int r, int c) {
	return r >= 0 && c >= 0 && r < row && c < col && field[r][c] != '*';
}

int main (int argc, char const *argv[]) {
	
	ios_base::sync_with_stdio(false);

	#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	#endif

	while (scanf("%d %d", &row, &col) != EOF && (row || col)) {
		for (int i = 0; i < row; ++i)
			scanf("%s", field[i]);

		for (int i = 0; i < row; ++i)
			for (int j = 0; j < col; ++j) 
				if (field[i][j] != '*')
					field[i][j] = '0';

		for (int i = 0; i < row; ++i)
			for (int j = 0; j < col; ++j) 
				if (field[i][j] == '*')
					for (int k = 0; k < 8; ++k) 
						if (IsLegal(i + moves[k][0], j + moves[k][1]))
							++field[i + moves[k][0]][j + moves[k][1]];
					
		if (t++)
			printf("\n");

		printf("Field #%d:\n", t);
		for (int i = 0; i < row; ++i) {
			printf("%s\n", field[i]);
		}
	}
	
	return 0;
}