// enjoyed this problem :)

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string line;
vector<string> board;
int row, col, answer;

int moves[4][2] = {
	-1, 0,
	0, 1,
	0, -1,
	1, 0
};

int diag[4][2] = {
	-1, -1,
	-1, +1,
	+1, -1,
	+1, +1
};

int knight[8][2] = {
	-1, -2,
	-2, -1,
	-2, 1,
	-1, 2,
	1, 2,
	2, 1,
	2, -1,
	1, -2
};

bool IsLegal (int i, int j) {
	return i >= 0 && j >= 0 && i < 8 && j < 8;
}

void GoWild (int i, int j, char piece) {

	if (piece == 'R' || piece == 'r' || piece == 'Q' || piece == 'q') {
		for (int k = 0; k < 4; ++k) 
			for (int start_i = i + moves[k][0], start_j = j + moves[k][1]; IsLegal(start_i, start_j); start_i += moves[k][0], start_j += moves[k][1]) {
				if (board[start_i][start_j] == ' ' || board[start_i][start_j] == 'x')
					board[start_i][start_j] = 'x';
				else
					break;
			}
	}

	if (piece == 'P') { // white pawn
		if (i - 1 >= 0 && j + 1 < 8 && board[i - 1][j + 1] == ' ')
			board[i - 1][j + 1] = 'x';
		if (i - 1 >= 0 && j - 1 >= 0 && board[i - 1][j - 1] == ' ')
			board[i - 1][j - 1] = 'x';
	}

	if (piece == 'p') { // black pawn
		if (i + 1 < 8 && j + 1 < 8 && board[i + 1][j + 1] == ' ')
			board[i + 1][j + 1] = 'x';
		if (i + 1 < 8 && j - 1 >= 0 && board[i + 1][j - 1] == ' ')
			board[i + 1][j - 1] = 'x';
	}

	if (piece == 'B' || piece == 'b' || piece == 'Q' || piece == 'q') {
		for (int k = 0; k < 4; ++k) {
			int start_i = i + diag[k][0];
			int start_j = j + diag[k][1];
			for (; IsLegal(start_i, start_j); start_i += diag[k][0], start_j += diag[k][1]) {
				if (board[start_i][start_j] == ' ' || board[start_i][start_j] == 'x')
					board[start_i][start_j] = 'x';
				else
					break;
			}
		}
	}

	if (piece == 'n' || piece == 'N') 
		for (int k = 0; k < 8; ++k)
			if (IsLegal(i + knight[k][0], j + knight[k][1]) && board[i + knight[k][0]][j + knight[k][1]] == ' ')
				board[i + knight[k][0]][j + knight[k][1]] = 'x';

	if (piece == 'k' || piece == 'K') {
		for (int k = 0; k < 4; ++k)
			if (IsLegal(i + moves[k][0], j + moves[k][1]) && board[i + moves[k][0]][j + moves[k][1]] == ' ')
				board[i + moves[k][0]][j + moves[k][1]] = 'x';
		for (int k = 0; k < 4; ++k)
			if (IsLegal(i + diag[k][0], j + diag[k][1]) && board[i + diag[k][0]][j + diag[k][1]] == ' ')
				board[i + diag[k][0]][j + diag[k][1]] = 'x';
	}

	return ;
	
}

void PrintBoard () {
	for (int i = 0; i < 8; ++i) 
		for (int j = 0; j < 8; ++j) 
			cout << board[i][j] << " \n"[j == 7];

	return ;
}

int main (int argc, char const *argv[]) {
	
	ios_base::sync_with_stdio(false);

	#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	#endif

	while (getline(cin, line)) {
		board.clear();
		board.assign(8, string(8, ' '));
		row = col = 0;
		for (auto i : line) {
			if (i >= '1' && i <= '9') {
				col += (i - '0');
			} else if (i == '/') {
				++row;
				col = 0;
			} else {
				board[row][col] = i;
				++col;
			}
		}
		for (int i = 0; i < 8; ++i) 
			for (int j = 0; j < 8; ++j) 
				if (board[i][j] != ' ' && board[i][j] != 'x')
					GoWild(i, j, board[i][j]);
		answer = 0;
		for (int i = 0; i < 8; ++i) 
			for (int j = 0; j < 8; ++j) 
				answer += (board[i][j] == ' ');


		cout << answer << endl;
		// PrintBoard();
		// cout << endl;
	}

	return 0;
}