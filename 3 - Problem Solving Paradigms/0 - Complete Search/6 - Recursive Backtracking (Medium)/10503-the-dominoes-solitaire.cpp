#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector< pair<int, int> > dominoes, solution;
int n, m, used, current_index;

void read_domino(pair<int, int>& piece) {
    scanf("%d %d", &piece.first, &piece.second);
}

bool is_legal(pair<int, int> &a, pair<int, int> &b){
    return a.second == b.first;
}

bool solution_exist() {
    if (current_index == n + 1) {
        if (is_legal(solution[n], solution[n + 1])) {
            return true;
        }
        return false;
    }
    for (int i = 0; i < m; ++i) {
        if (used & (1 << i)) {
            continue;
        }
        for (int j = 0; j < 2; ++j) {
            if (j) swap(dominoes[i].first, dominoes[i].second);
            if (is_legal(solution[current_index - 1], dominoes[i])) {
                used |= (1 << i);
                solution[current_index] = dominoes[i];
                ++current_index;
                if (solution_exist()) {
                    return true;
                }
                --current_index;
                used &= ~(1 << i);
            }
            if (j) swap(dominoes[i].first, dominoes[i].second);
        }
    }
    return false;
}

int main (int argc, char const *argv[]) {
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    #endif

    while (scanf("%d", &n) != EOF && n) {
        scanf("%d", &m);
        solution.resize(n + 2);
        dominoes.resize(m);
        read_domino(solution[0]);
        read_domino(solution[n + 1]);
        for (auto&& piece : dominoes) {
            read_domino(piece);
        }
        used = 0;
        current_index = 1;
        if (solution_exist()) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}