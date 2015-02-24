// My brute-force solution, I'm quite sure there exists a better solution

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Weigh {
	string a, b, m;
	Weigh(string &_a, string &_b, string &_m) {
		a = _a;
		b = _b;
		m = _m;
	}
};

int n, c, wa, wb;
string a, b, m;
vector<Weigh> vw;
bool found, light;

int main (int argc, char const *argv[]) {
	
	ios_base::sync_with_stdio(false);

	#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	#endif

	cin >> n;

	while (n--) {

		vw.clear();

		for (int i = 0; i < 3; ++i) {
			cin >> a >> b >> m;
			vw.push_back(Weigh(a, b, m));
		}

		found = false;

		for (c = 0; c < 12; ++c) {

			for (auto w : vw) {
				found = true;
				light = false;
				wa = wb = 0;

				for (auto ch : w.a)
					if (ch - 'A' == c) ++wa;

				for (auto ch : w.b)
					if (ch - 'A' == c) ++wb;

				if (wa == wb && w.m != "even") {
					found = false;
					break;
				} else if (wa > wb && w.m != "up") {
					found = false;
					break;
				} else if (wa < wb && w.m != "down") {
					found = false;
					break;
				}
			}

			if (found) break;

			for (auto w : vw) {
				found = true;
				light = true;
				wa = wb = 0;

				for (auto ch : w.a)
					if (ch - 'A' == c) --wa;

				for (auto ch : w.b)
					if (ch - 'A' == c) --wb;

				if (wa == wb && w.m != "even") {
					found = false;
					break;
				} else if (wa > wb && w.m != "up") {
					found = false;
					break;
				} else if (wa < wb && w.m != "down") {
					found = false;
					break;
				}
			}

			if (found) break;
		}

		cout << char(c + 'A') << " is the counterfeit coin and it is " << (light ? "light" : "heavy") << "." << endl;
	}
	
	return 0;
}