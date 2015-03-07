#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define r first
#define c second

int abs(const int x) {
    return x < 0 ? (-x) : x;
}

int temp_distance, m;
vector<string> grid;
vector< pair<int, int> > ones, threes;
vector<int> min_distance;

int main (int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    #endif

    while (cin >> m) {
        grid.resize(m);
        ones.clear();
        threes.clear();
        for (auto&& row : grid) {
            cin >> row;
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '1') {
                    ones.push_back(make_pair(i, j));
                } else if (grid[i][j] == '3') {
                    threes.push_back(make_pair(i, j));
                }
            }
        }
        min_distance.assign(ones.size(), 1e9);
        for (int i = 0; i < ones.size(); ++i) {
            for (int j = 0; j < threes.size(); ++j) {
                temp_distance = abs(ones[i].r - threes[j].r) + abs(ones[i].c - threes[j].c);
                if (temp_distance < min_distance[i])
                    min_distance[i] = temp_distance;
            }
        }
        cout << *max_element(min_distance.begin(), min_distance.end()) << "\n";
    }

    return 0;
}