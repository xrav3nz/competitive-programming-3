#include <iostream>
#include <string>
#include <sstream>
#include <set>

using namespace std;

stringstream ss;
string line, word;
set<string> dictionary;

int main (int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    #endif

    while (getline(cin, line)) {
        if (line == "")
            continue;
        for (char &c : line) {
            if (c >= 'A' && c <= 'Z') {
                c = c - 'A' + 'a';
            } else if (c < 'a' || c > 'z') {
                c = ' ';
            }
        }
        ss.clear();
        ss << line;
        while (ss >> word) {
            dictionary.insert(word);
        }
    }
    for (auto&& entry : dictionary) {
        cout << entry << endl;
    }

    return 0;
}