#include <iostream>
#include <string>

using namespace std;

string equation;

int main (int argc, char const *argv[]) {
	
	ios_base::sync_with_stdio(false);

	#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	#endif

	while (getline(cin, equation)) 
		cout << equation << endl;
	
	return 0;
}