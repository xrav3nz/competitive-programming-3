#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> input, no_space;
string temp;
int t;

string NoSpace (string &s) {
	string new_s = "";
	for (auto c : s)
		if (c != ' ')
			new_s += c;
	sort (new_s.begin(), new_s.end());
	return new_s;
}

int main (int argc, char const *argv[]) {
	
	// why does this line give me WA?
	// ios_base::sync_with_stdio(false);

	#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	#endif

	cin >> t;
	getline(cin, temp);
	getline(cin, temp);

	while (t--) {
		input.clear();
		no_space.clear();

		while (getline(cin, temp) && temp != "") 
			input.push_back(temp);
		

		sort(input.begin(), input.end());

		for (int i = 0; i < input.size(); ++i)
			no_space.push_back(NoSpace(input[i]));

		for (int i = 0; i + 1 < input.size(); ++i)
			for (int j = i + 1; j < input.size(); ++j)
				if (no_space[i] == no_space[j])
					cout << input[i] << " = " << input[j] << endl;

		if (t) printf("\n");
	}
	
	return 0;
}