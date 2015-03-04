#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <bitset>

using namespace std;

typedef vector<int> vi;

string input;
bitset<26> is_awake;
vi to_be_awaken;
vector< vi > graph;
map<char, int> c_to_id;
int n, m, a, b, answer, id = 1, awake_count;

int awake_neighbour(int j) {
    int total = 0;
    for (int i = 1; i <= n && total < 3; ++i) {
        if (graph[i][j] && is_awake[i])
            ++total;
    }
    return total;
}

bool all_awake() {
    for (int i = 1; i <= n; ++i)
        if (!is_awake[i])
            return false;
    return true;
}

int main (int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    #endif

    while (cin >> n >> m >> input) {
        graph.assign(n + 1, vi(n + 1, 0));
        c_to_id.clear();
        is_awake.reset();
        awake_count = 3;
        id = 1;
        answer = 0;
        for (auto c : input) {
            a = c_to_id[c] = id++;
            is_awake[a] = true;
        }
        for (int i = 0; i < m; ++i) {
            cin >> input;
            a = c_to_id[input[0]];
            b = c_to_id[input[1]];
            if (a == 0) {
                a = c_to_id[input[0]] = id++;
            }
            if (b == 0) {
                b = c_to_id[input[1]] = id++;
            }
            graph[a][b] = graph[b][a] = 1;
        }
        do {
            to_be_awaken.clear();
            for (int i = 1; i <= n; ++i) {
                if (is_awake[i])
                    continue;
                if (awake_neighbour(i) >= 3) {
                    to_be_awaken.push_back(i);
                }
            }
            for (auto i : to_be_awaken) {
                is_awake[i] = true;
            }
            if (!to_be_awaken.empty()) {
                ++answer;
                awake_count += to_be_awaken.size();
            }
        } while(!to_be_awaken.empty());
        if (awake_count == n) {
            cout << "WAKE UP IN, " << answer << ", YEARS" << endl;
        } else {
            cout << "THIS BRAIN NEVER WAKES UP" << endl;
        }
    }


    return 0;
}