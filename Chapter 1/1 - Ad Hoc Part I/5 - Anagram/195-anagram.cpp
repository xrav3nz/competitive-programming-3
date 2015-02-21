#include <iostream>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

map<char, int> dict;
string input;
int t, size;

void InitMap () {
	dict['A'] = 0;
	dict['a'] = 1;
	dict['B'] = 2;
	dict['b'] = 3;
	dict['C'] = 4;
	dict['c'] = 5;
	dict['D'] = 6;
	dict['d'] = 7;
	dict['E'] = 8;
	dict['e'] = 9;
	dict['F'] = 10;
	dict['f'] = 11;
	dict['G'] = 12;
	dict['g'] = 13;
	dict['H'] = 14;
	dict['h'] = 15;
	dict['I'] = 16;
	dict['i'] = 17;
	dict['J'] = 18;
	dict['j'] = 19;
	dict['K'] = 20;
	dict['k'] = 21;
	dict['L'] = 22;
	dict['l'] = 23;
	dict['M'] = 24;
	dict['m'] = 25;
	dict['N'] = 26;
	dict['n'] = 27;
	dict['O'] = 28;
	dict['o'] = 29;
	dict['P'] = 30;
	dict['p'] = 31;
	dict['Q'] = 32;
	dict['q'] = 33;
	dict['R'] = 34;
	dict['r'] = 35;
	dict['S'] = 36;
	dict['s'] = 37;
	dict['T'] = 38;
	dict['t'] = 39;
	dict['U'] = 40;
	dict['u'] = 41;
	dict['V'] = 42;
	dict['v'] = 43;
	dict['W'] = 44;
	dict['w'] = 45;
	dict['X'] = 46;
	dict['x'] = 47;
	dict['Y'] = 48;
	dict['y'] = 49;
	dict['Z'] = 50;
	dict['z'] = 51;
	return ;
}

bool MyCompare (char a, char b) {
	return dict[a] < dict[b];
}

int main (int argc, char const *argv[]) {
	
	ios_base::sync_with_stdio(false);

	#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	#endif

	cin >> t;

	InitMap ();

	while (t--) {
		cin >> input;
		sort (input.begin(), input.end(), MyCompare);

		do {
			cout << input << endl;
		} while (next_permutation (input.begin(), input.end(), MyCompare)) ;
	}	
	
	return 0;
}