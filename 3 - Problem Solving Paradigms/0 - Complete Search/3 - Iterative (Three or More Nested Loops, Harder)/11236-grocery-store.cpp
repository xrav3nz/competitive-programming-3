#include <cstdio>

int a, b, c, d;
const long long int
    RATIO = 1000000,
    LIMIT = 2000;

int main (int argc, char const *argv[]) {
    #ifndef ONLINE_JUDGE
    freopen("output.out", "w", stdout);
    #endif

    for (a = 1; a <= LIMIT; ++a) {
        for (b = a; a + b <= LIMIT; ++b) {
            for (c = b; a + b + c * 2 <= LIMIT; ++c) {
                if ((a * b * c - RATIO) == 0)
                    continue;
                d = ((a + b + c) * RATIO / (a * b * c - RATIO));
                if (d >= c && a + b + c + d <= LIMIT && (a + b + c + d) * RATIO == a * b * c * d * 1LL) {
                    printf("%.2f %.2f %.2f %.2f\n", a / 100.0, b / 100.0, c / 100.0, d / 100.0);
                }
            }
        }
    }

    return 0;
}