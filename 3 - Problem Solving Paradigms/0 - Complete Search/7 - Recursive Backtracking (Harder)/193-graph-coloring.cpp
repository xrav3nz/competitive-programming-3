#include <vector>
#include <bitset>
#include <cstdio>
using namespace std;

#define COLORED 1
#define UNCOLORED 0

int t, n, k, best_count, a, b;
vector< vector<int> > graph;
vector<int> best_coloring;

void find_best_coloring(int cur_index, vector<int> coloring, bitset<101> state){
    if (cur_index > n) {
        if (coloring.size() > best_count) {
            best_count = coloring.size();
            best_coloring = coloring;
        }
        return ;
    }

    // do not color the current node
    find_best_coloring(cur_index + 1, coloring, state);

    // color the current node if possible
    if (state[cur_index] == UNCOLORED) {
        state[cur_index] = COLORED;
        coloring.push_back(cur_index);
        for (int& neighbour : graph[cur_index]) {
            state[neighbour] = COLORED;
        }
        find_best_coloring(cur_index + 1, coloring, state);
    }

    return ;
}

int main (int argc, char const *argv[]) {
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    #endif

    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &k);
        best_coloring.clear();
        best_count = 0;
        graph.clear();
        graph.resize(n + 1);
        while (k--) {
            scanf("%d %d", &a, &b);
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        find_best_coloring(1, vector<int>(0), bitset<101>(0));
        printf("%d\n", best_count);
        for (int i = 0; i < best_count; ++i) {
            printf("%d%c", best_coloring[i], " \n"[i == best_count - 1]);
        }
    }

    return 0;
}