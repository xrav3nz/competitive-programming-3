#include <cstdio>

int max_score, max_difference, t, n, score;
int higher_score(int a, int b) {
    return a > b ? a : b;
}

int main (int argc, char const *argv[]) {
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    #endif

    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        max_score = -1e9;
        max_difference = -1e9;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &score);
            max_difference = higher_score(max_difference, max_score - score);
            max_score = higher_score(max_score, score);
        }
        printf("%d\n", max_difference);
    }

    return 0;
}