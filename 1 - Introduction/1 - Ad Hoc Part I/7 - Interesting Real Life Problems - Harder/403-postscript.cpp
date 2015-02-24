// ENJOYED THIS PROBLEM A LOT

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector< vector<string> > c5 {
	{
		".***..",
		"*...*.",
		"*****.",
		"*...*.",
		"*...*." 
	},
	{
		"****..",
		"*...*.",
		"****..",
		"*...*.",
		"****.." 
	},
	{
		".****.",
		"*...*.",
		"*.....",
		"*.....",
		".****." 
	},
	{
		"****..",
		"*...*.",
		"*...*.",
		"*...*.",
		"****.." 
	},
	{
		"*****.",
		"*.....",
		"***...",
		"*.....",
		"*****." 
	},
	{
		"*****.",
		"*.....",
		"***...",
		"*.....",
		"*....." 
	},
	{
		".****.",
		"*.....",
		"*..**.",
		"*...*.",
		".***.." 
	},
	{
		"*...*.",
		"*...*.",
		"*****.",
		"*...*.",
		"*...*." 
	},
	{
		"*****.",
		"..*...",
		"..*...",
		"..*...",
		"*****." 
	},
	{
		"..***.",
		"...*..",
		"...*..",
		"*..*..",
		".**..." 
	},
	{
		"*...*.",
		"*..*..",
		"***...",
		"*..*..",
		"*...*." 
	},
	{
		"*.....",
		"*.....",
		"*.....",
		"*.....",
		"*****." 
	},
	{
		"*...*.",
		"**.**.",
		"*.*.*.",
		"*...*.",
		"*...*." 
	},
	{
		"*...*.",
		"**..*.",
		"*.*.*.",
		"*..**.",
		"*...*." 
	},
	{
		".***..",
		"*...*.",
		"*...*.",
		"*...*.",
		".***.." 
	},
	{
		"****..",
		"*...*.",
		"****..",
		"*.....",
		"*....." 
	},
	{
		".***..",
		"*...*.",
		"*...*.",
		"*..**.",
		".****." 
	},
	{
		"****..",
		"*...*.",
		"****..",
		"*..*..",
		"*...*." 
	},
	{
		".****.",
		"*.....",
		".***..",
		"....*.",
		"****.." 
	},
	{
		"*****.",
		"*.*.*.",
		"..*...",
		"..*...",
		".***.." 
	},
	{
		"*...*.",
		"*...*.",
		"*...*.",
		"*...*.",
		".***.." 
	},
	{
		"*...*.",
		"*...*.",
		".*.*..",
		".*.*..",
		"..*..." 
	},
	{
		"*...*.",
		"*...*.",
		"*.*.*.",
		"**.**.",
		"*...*." 
	},
	{
		"*...*.",
		".*.*..",
		"..*...",
		".*.*..",
		"*...*." 
	},
	{
		"*...*.",
		".*.*..",
		"..*...",
		"..*...",
		"..*..." 
	},
	{
		"*****.",
		"...*..",
		"..*...",
		".*....",
		"*****." 
	},
	{
		"......",
		"......",
		"......",
		"......",
		"......" 
	}
};

vector<string> grid(60, string(60, '.'));

string command, font, input, s;
int row, col;

bool IsLegal (int i, int j) {
	return i >= 0 && i < 60 && j >= 0 && j < 60;
}

void PrintC5 (char ch, int r, int c) {
	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 6; ++j)
			if (c5[ch - 'A'][i][j] != '.' && IsLegal(i + r, j + c))
				grid[i + r][j + c] = c5[ch - 'A'][i][j];
	return ;
}

void ParseInput () {
	bool pipe_start = false;
	s = "";
	for (auto c : input) {
		if (c == '|' && pipe_start) 
			break;
		else if (c == '|' && !pipe_start)
			pipe_start = true;
		else if (pipe_start)
			s += c;
	}
	return ;
}

void PrintBoard () {
	for (int i = 0; i < 60; ++i)
		cout << grid[i] << endl;
	cout << endl << string(60, '-') << endl << endl;
	return ;
}

void Format () {
	if (command == ".L" || command == ".P") {
		if (command == ".L")
			col = 0;
		if (font == "C1") {
			for (auto c : s) {
				if (c != ' ') grid[row][col] = c;
				if (++col >= 60) break;
			}
		} else {
			for (auto c : s) {
				if (c != ' ') PrintC5(c, row, col);
				col += 6;
				if (col >= 60) break;
			}
		}
	} else if (command == ".R") {
		reverse(s.begin(), s.end());
		if (font == "C1") {
			col = 60 - 1;
			for (auto c : s) {
				if (c != ' ') grid[row][col] = c;
				if (--col < 0) break;
			}
		} else {
			col = 60 - 6;
			for (auto c : s) {
				if (c != ' ') PrintC5(c, row, col);
				col -= 6;
				if (col < 0) break;
			}
		}
	} else if (command == ".C") {
		int length = s.size();
		if (font == "C1") {
			col = (length % 2 == 0) ? ((60 - length) >> 1) : ((60 - length + 1) >> 1);
			for (auto c : s) {
				if (c != ' ') grid[row][col] = c;
				if (++col >= 60) break;
			}
		} else {
			length *= 6;
			col = (length % 2 == 0) ? ((60 - length) >> 1) : ((60 - length + 1) >> 1);
			for (auto c : s) {
				if (c != ' ') PrintC5(c, row, col);
				col += 6;
				if (col >= 60) break;
			}
		}
	}
	return ;
}

int main (int argc, char const *argv[]) {
	
	ios_base::sync_with_stdio(false);

	#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	#endif

	// PrintBoard();

	while (cin >> command) {

		if (command == ".EOP") {
			PrintBoard();
			grid.assign(60, string(60, '.'));
		} else {

			cin >> font >> row;
			if (command == ".P") cin >> col;
			--row, --col;
			getline(cin, input);
			ParseInput();
			Format();
		}
	}

	return 0;
}