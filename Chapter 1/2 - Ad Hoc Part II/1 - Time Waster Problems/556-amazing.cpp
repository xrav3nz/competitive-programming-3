#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector< string > maze;
vector< vector< int > > visited;
vector< int > v_count(5, 0);
// o - orientation
int col, row, c, r, o, new_o; 

int moves[4][2] = {
	1, 0,
	0, 1,
	-1, 0,
	0, -1
};

bool IsLegal (int i, int j) {
	return i >= 0 && j >= 0 && i < row && j < col && maze[i][j] == '0';
}

int main (int argc, char const *argv[]) {

	#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	#endif

	while (cin >> row >> col) {

		if (!row && !col)
			break;

		maze.resize(row);
		visited.assign(row, vector<int>(col, 0));

		for (int i = 0; i < row; ++i)
			cin >> maze[i];

		r = row - 1;
		c = 0;
		o = 1;
		do {
			new_o = o - 1;
			if (new_o < 0) new_o = 3;
			for (int i = 0; i < 4; ++i, ++new_o) {
				if (new_o > 3) new_o = 0;
				if (IsLegal(r + moves[new_o][0], c + moves[new_o][1])) {
					r += moves[new_o][0];
					c += moves[new_o][1];
					++visited[r][c];
					o = new_o;
					break;
				}
			}
		} while (r != row - 1 || c != 0);

		v_count.assign(5, 0);

		for (int i = 0; i < row; ++i)
			for (int j = 0; j < col; ++j)
				if (maze[i][j] == '0' && visited[i][j] < 5)
					++v_count[visited[i][j]];

		for (int i = 0; i < 5; ++i)
			printf("%3d", v_count[i]);
		printf("\n");
	}
	
	return 0;
}