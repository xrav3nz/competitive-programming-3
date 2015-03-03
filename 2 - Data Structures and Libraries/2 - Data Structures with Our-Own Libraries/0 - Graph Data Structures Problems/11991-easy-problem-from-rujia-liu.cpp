#include <cstdio>
#include <vector>

using namespace std;

const int MAX = 1e6 + 1;

int n, m, k, v;
vector< vector<int> > kth_occurence;

int main (int argc, char const *argv[]) {

    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    #endif

    while(scanf("%d %d", &n, &m) != EOF) {
        kth_occurence.assign(MAX, vector<int>(0));
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &v);
            kth_occurence[v].push_back(i);
        }

        while (m--) {
            scanf("%d %d", &k, &v);
            if (kth_occurence[v].size() < k) {
                printf("0\n");
            } else {
                printf("%d\n", kth_occurence[v][k - 1]);
            }
        }
    }

    return 0;
}