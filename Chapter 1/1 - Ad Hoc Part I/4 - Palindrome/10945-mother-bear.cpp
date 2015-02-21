#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>

using namespace std;

string input;
char c;

bool IsPalindrome () {

	for (int i = 0, j = input.size() - 1; i < j; ++i, --j)
		if (input[i] != input[j])
			return false;

	return true;
}

int main (int argc, char const *argv[]) {
	
	ios_base::sync_with_stdio(false);

	#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	#endif

	while (true) {
		input.clear();

		do {
			c = getchar();
			if (c <= 'z' && c >= 'a')
				input.push_back(c);
			if (c <= 'Z' && c >= 'A')
				input.push_back(c - 'A' + 'a');
		} while (c != '\n' && c != EOF);

		if (input == "done")
			break;

		if (IsPalindrome())
			printf("You won't be eaten!\n");
		else
			printf("Uh oh..\n");

	}
	
	return 0;
}