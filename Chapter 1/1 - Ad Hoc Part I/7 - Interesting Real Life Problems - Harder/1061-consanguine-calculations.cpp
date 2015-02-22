#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Inheritance {
	string mother, father, child;
	Inheritance (string _m, string _f, string _c) {
		mother = _m;
		father = _f;
		child = _c;
	}
};

vector<string> types {"O", "AB", "B", "A"};
string rh("+-"), p1, p2, ch, temp;
vector<Inheritance> combination;
vector<string> results;
int id;
char p1_rh, p2_rh, ch_rh;

void InitCombination () {
	string new_rh, c;
	for (auto f : types) for (auto m : types) {
		if (f == "A") {
			if (m == "A" || m == "O") {
				combination.push_back(Inheritance(m, f, "O"));
				combination.push_back(Inheritance(m, f, "A"));
			} else {
				if (m == "B") combination.push_back(Inheritance(m, f, "O"));
				combination.push_back(Inheritance(m, f, "AB"));
				combination.push_back(Inheritance(m, f, "B"));
				combination.push_back(Inheritance(m, f, "A"));
			}
		} else if (f == "B") {
			if (m == "B" || m == "O") {
				combination.push_back(Inheritance(m, f, "O"));
				combination.push_back(Inheritance(m, f, "B"));
			} else {
				if (m == "A") combination.push_back(Inheritance(m, f, "O"));
				combination.push_back(Inheritance(m, f, "AB"));
				combination.push_back(Inheritance(m, f, "B"));
				combination.push_back(Inheritance(m, f, "A"));
			}
		} else if (f == "AB") {
			if (m == "O") {
				combination.push_back(Inheritance(m, f, "B"));
				combination.push_back(Inheritance(m, f, "A"));
			} else {
				combination.push_back(Inheritance(m, f, "AB"));
				combination.push_back(Inheritance(m, f, "B"));
				combination.push_back(Inheritance(m, f, "A"));
			}
		} else if (f == "O") {
			if (m == "AB") {
				combination.push_back(Inheritance(m, f, "B"));
				combination.push_back(Inheritance(m, f, "A"));
			} else {
				combination.push_back(Inheritance(m, f, "O"));
				if (m != "O")
					combination.push_back(Inheritance(m, f, m));
			}
		}
	}
}

int main (int argc, char const *argv[]) {
	
	ios_base::sync_with_stdio(false);

	#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	#endif

	InitCombination();

	while (cin >> p1 >> p2 >> ch) {
		++id;
		if (p1 == "E" && p2 == "N" && ch == "D")
			break;
		results.clear();
		if (ch == "?") {
			p1_rh = p1[p1.size() - 1];
			p2_rh = p2[p2.size() - 1];
			p1.pop_back();
			p2.pop_back();

			for (auto in : combination) 
				if (in.father == p1 && in.mother == p2) {
					if (p1_rh == '-' && p2_rh == '-')
						results.push_back(in.child + "-");
					else {
						results.push_back(in.child + "-");
						results.push_back(in.child + "+");
					}
				}

			cout << "Case " << id << ": " << p1 + p1_rh << " " << p2 + p2_rh;
			if (results.size() == 0)
				cout << " IMPOSSIBLE" << endl;
			else if (results.size() == 1)
				cout << " " << results[0] << endl;
			else {
				cout << " {";
				for (int i = 0; i < results.size(); ++i) {
					cout << results[i];
					if (i < results.size() - 1)
						cout << ", ";
				}
				cout << "}" << endl;
			}
		} else if (p1 == "?") {

			p2_rh = p2[p2.size() - 1];
			ch_rh = ch[ch.size() - 1];
			p2.pop_back();
			ch.pop_back();

			for (auto in : combination) 
				if (in.father == p2 && in.child == ch) {
					if (!(p2_rh == '-' && ch_rh == '+'))
						results.push_back(in.mother + "-");
					results.push_back(in.mother + "+");
				}

			cout << "Case " << id << ": ";
			if (results.size() == 0)
				cout << "IMPOSSIBLE ";
			else {
				cout << "{";
				for (int i = 0; i < results.size(); ++i) {
					cout << results[i];
					if (i < results.size() - 1)
						cout << ", ";
				}
				cout << "} ";
			}
			cout << p2 + p2_rh << " " << ch + ch_rh << endl;

		} else {
			
			p1_rh = p1[p1.size() - 1];
			ch_rh = ch[ch.size() - 1];
			p1.pop_back();
			ch.pop_back();

			for (auto in : combination) 
				if (in.mother == p1 && in.child == ch) {
					if (!(p1_rh == '-' && ch_rh == '+'))
						results.push_back(in.father + "-");
					results.push_back(in.father + "+");
				}

			cout << "Case " << id << ": " << p1 + p1_rh;
			if (results.size() == 0)
				cout << " IMPOSSIBLE";
			else {
				cout << " {";
				for (int i = 0; i < results.size(); ++i) {
					cout << results[i];
					if (i < results.size() - 1)
						cout << ", ";
				}
				cout << "}";
			}
			cout << " " << ch + ch_rh << endl;
		}
	}
	
	return 0;
}