#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

int t, goal, n_bars, sum;
vector<int> bars;

bool can_achieve_goal(){
    int max_subset = pow(2, n_bars),
        subset_sum;
    for (int subset = 0; subset < max_subset; ++subset) {
        subset_sum = 0;
        for (int i = 0; i < n_bars; ++i) {
            if (subset & (1 << i)) {
                subset_sum += bars[i];
            }
        }
        if (subset_sum == goal || sum - subset_sum == goal) {
            return true;
        }
    }
    return false;
}

int main (int argc, char const *argv[]) {
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    #endif

    scanf("%d", &t);

    while (t--) {
        scanf("%d %d", &goal, &n_bars);
        bars.resize(n_bars);
        sum = 0;
        for (int& bar : bars){
            scanf("%d", &bar);
            sum += bar;
        }
        if (can_achieve_goal()) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}