#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <bitset>

using namespace std;

int t, a, b, tree_count, acorn_count;
bitset<26> visited;
string line;

int main (int argc, char const *argv[]) {

    ios_base::sync_with_stdio(false);

    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    #endif

    cin >> t;

    while (t--) {
        visited.reset();
        tree_count = acorn_count = 0;
        while (cin >> line && line[0] != '*') {
            a = line[1] - 'A';
            b = line[3] - 'A';
            visited[a] = visited[b] = true;
            --tree_count;
        }

        cin >> line;
        for (auto node : line) {
            if (node != ',') {
                a = node - 'A';
                if (!visited[a]) {
                    ++acorn_count;
                }
                ++tree_count;
            }
        }

        tree_count -= acorn_count;

        cout << "There are " << tree_count << " tree(s) and " << acorn_count << " acorn(s).\n";
    }

    return 0;
}