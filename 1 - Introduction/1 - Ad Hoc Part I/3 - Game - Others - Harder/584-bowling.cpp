#include <iostream>
#include <string>
#include <vector>

using namespace std;

string input;
vector<int> rolls, frame;
int score, sum;

int main (int argc, char const *argv[]) {
	
	ios_base::sync_with_stdio(false);

	#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	#endif

	while (getline(cin, input) && input != "Game Over") {

		rolls.clear();
		frame.clear();

		// parse input
		for (int i = 0; input[i]; ++i) {
			if (input[i] <= '9' && input[i] >= '0')
				rolls.push_back(input[i] - '0');
			else if (input[i] == '/')
				rolls.push_back(10);
			else if (input[i] == 'X')
				rolls.push_back(100);
		}

		// process the rolls from the end
		for (int i = rolls.size() - 1; i >= 0; --i) {
			score = 0;
			if (rolls[i] == 100) {			// strike
				if (i + 1 < rolls.size())
					score += (rolls[i + 1] > 10) ? 10 : rolls[i + 1];
				if (i + 2 < rolls.size()) {
					if (rolls[i + 2] == 10)
						score = 10;
					else
						score += (rolls[i + 2] > 10) ? 10 : rolls[i + 2];
				}
				score += 10;
				frame.push_back(score);
			} else if (rolls[i] == 10) {	// spare
				if (i + 1 < rolls.size())
					score = rolls[i + 1];
				if (score > 10)
					score = 10;
				--i;
				score += 10;
				frame.push_back(score);
			} else {
				score = rolls[i];
				if (rolls[i - 1] < 10){
					score += rolls[i - 1];
					--i;
				}
				frame.push_back(score);
			}
		}

		sum = 0;

		for (int i = frame.size() - 1, j = 0; i >= 0 && j < 10; --i, ++j) {
			// cout << frame[i] << " \n"[i == 0];
			sum += frame[i];
		}

		cout << sum << endl;
	}
	
	return 0;
}