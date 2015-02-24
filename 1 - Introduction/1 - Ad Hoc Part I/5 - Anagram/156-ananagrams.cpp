#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

map<string, int> cnt;
vector<string> input, output;
string temp;

string LowerAndOrder (string s) {
	for (int i = 0; s[i]; ++i)
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] = s[i] - 'A' + 'a';
	sort(s.begin(), s.end());
	return s;
}

int main (int argc, char const *argv[]) {
	
	ios_base::sync_with_stdio(false);

	#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	#endif

	while (cin >> temp && temp[0] != '#') {
		input.push_back(temp);
		temp = LowerAndOrder(temp);
		++cnt[temp];
	}

	for (auto s : input) {
		if (cnt[LowerAndOrder(s)] == 1)
			output.push_back(s);
	}

	sort(output.begin(), output.end());

	for (auto s : output)
		cout << s << endl;
	
	return 0;
}