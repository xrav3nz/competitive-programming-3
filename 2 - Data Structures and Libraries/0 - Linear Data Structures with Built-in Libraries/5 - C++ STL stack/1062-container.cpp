#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<char> s;
string input;
int min_diff, min_id, _g;

int main (int argc, char const *argv[]) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    #endif

    while (cin >> input && input != "end") {
        s.clear();
        ++_g;
        for (auto c : input) {
            min_id = -1;
            min_diff = 27;
            for (int i = 0; i < s.size(); ++i) {
                if (c <= s[i] && s[i] - c < min_diff) {
                    min_diff = s[i] - c;
                    min_id = i;
                }
            }
            if (min_id == -1) {
                s.push_back(c);
            } else {
                s[min_id] = c;
            }
        }
        cout << "Case " << _g <<  ": " << s.size() << "\n";
    }
    
    return 0;
}