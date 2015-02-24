#include <iostream>
#include <string>
#include <vector>

using namespace std;

int l;
string cur, bend;

int main (int argc, char const *argv[]) {
	
	ios_base::sync_with_stdio(false);

	#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	#endif

	while (cin >> l && l) {
		cur = "+x";
		for (int i = 1; i < l; ++i) {
			cin >> bend;
			if (bend == "No") continue;
			if (cur == "+x")
				cur = bend;
			else if (cur == "-x") {
				cur[1] = bend[1];
				cur[0] = (bend[0] == '-') ? '+' : '-';
			}
			else if (cur == "+y") {
				if (bend[1] == 'y') {
					cur[1] = 'x';
					cur[0] = (bend[0] == '-') ? '+' : '-';
				} else
					cur = "+y";
			} else if (cur == "-y") {
				if (bend[1] == 'y') {
					cur[1] = 'x';
					cur[0] = (bend[0] == '-') ? '-' : '+';
				} else
					cur = "-y";
			} else if (cur == "+z") {
				if (bend[1] == 'z') {
					cur[1] = 'x';
					cur[0] = (bend[0] == '-') ? '+' : '-';
				} else
					cur = "+z";
			} else if (cur == "-z") {
				if (bend[1] == 'z') {
					cur[1] = 'x';
					cur[0] = (bend[0] == '-') ? '-' : '+';
				} else
					cur = "-z";
			}
		}
		cout << cur << endl;
	} 
	
	return 0;
}