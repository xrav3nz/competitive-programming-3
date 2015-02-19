#include <iostream>
#include <string>

using namespace std;

string line;
bool open;

int main (int argc, char const *argv[]) {
	
	ios_base::sync_with_stdio(false);

	#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	#endif

	while (getline(cin, line)) {
	
		for (auto i : line) {
			if (i == '"') {
				if (open) {
					cout << "''";
					open = false;
				} else {
					cout << "``";
					open = true;
				}
			} else {
				cout << i;
			}
		}

		cout << endl;
	}

	return 0;
}