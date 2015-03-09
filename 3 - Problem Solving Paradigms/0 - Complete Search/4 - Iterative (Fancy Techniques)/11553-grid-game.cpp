#include <cstdio>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int t, n, min_num, temp;
vector< vector<int> > grid(8, vector<int>(8, 0));
vector<int> permutation;
int main (int argc, char const *argv[]) {
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    #endif

    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &grid[i][j]);
            }
        }
        min_num = INT_MAX;
        permutation = {0, 1, 2, 3, 4, 5, 6, 7};
        do {
            temp = 0;
            for (int i = 0; i < n; ++i) {
                temp += grid[i][ permutation[i] ];
            }
            min_num = min(temp, min_num);
        } while (next_permutation(permutation.begin(), permutation.begin() + n));
        printf("%d\n", min_num);
    }

    return 0;
}