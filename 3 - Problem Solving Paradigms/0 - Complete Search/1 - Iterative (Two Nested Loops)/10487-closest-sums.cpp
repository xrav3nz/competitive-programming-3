#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int abs (int x) {
    return x < 0 ? -x : x;
}

int test_id, n, m, query, min_diff, min_id, temp_diff;
vector<int> integer_set, sums;

int main (int argc, char const *argv[]) {
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    #endif

    while (scanf("%d", &n) != EOF && n) {
        ++test_id;
        integer_set.resize(n);
        sums.clear();
        for (int i = 0; i < n; ++i) {
            scanf("%d", &integer_set[i]);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                sums.push_back(integer_set[i] + integer_set[j]);
            }
        }
        sort(sums.begin(), sums.end());
        printf("Case %d:\n", test_id);
        scanf("%d", &m);
        while (m--) {
            scanf("%d", &query);
            min_id = 0;
            min_diff = abs(sums[0] - query);
            for (int i = 1; i < sums.size(); ++i) {
                temp_diff = abs(sums[i] - query);
                if (temp_diff > min_diff) {
                    break;
                } else {
                    min_diff = temp_diff;
                    min_id = i;
                }
            }
            printf("Closest sum to %d is %d.\n", query, sums[min_id]);
        }
    }

    return 0;
}