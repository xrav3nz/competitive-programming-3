#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector< string > notebook;
vector< int > sequence;
string input;
int n, id, start, ending;

void OutputRange () {

	cout << notebook[start] << "-";

	for (int i = 0; notebook[start][i]; ++i)
		if (notebook[start][i] != notebook[ending][i]) {
			for (int j = i; notebook[ending][j]; ++j)
				cout << notebook[ending][j];
			break;
		}

	cout << endl;

	return ;
}

int main (int argc, char const *argv[]) {
	
	ios_base::sync_with_stdio(false);

	#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	#endif

	while (cin >> n && n) {
		++id;

		notebook.assign(n, "");
		sequence.assign(n + 1, 0);
		sequence[n] = -100;

		for (int i = 0; i < n; ++i) {
			cin >> notebook[i];
			sequence[i] = stoi(notebook[i]);
		}

		cout << "Case " << id << ":" << endl;

		for (int i = 0; i < n; ++i) {
			if (sequence[i] + 1 != sequence[i + 1])
				cout << notebook[i] << endl;
			else {
				start = i;
				ending = i + 1;
				for (int j = i + 1; j < n; ++j) 
					if (sequence[j] + 1 != sequence[j + 1]){
						ending = j;
						break;
					}
				i = ending;
				OutputRange();
			}
		}

		cout << endl;
	}
	
	return 0;
}