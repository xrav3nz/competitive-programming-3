#include <cstdio>

int n, a, b, c, x, y, z;
bool found;

int main (int argc, char const *argv[]) {
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    #endif

    scanf("%d", &n);
    while (n--) {
        scanf("%d %d %d", &a, &b, &c);
        found = false;
        for (x = -100; x <= 100 && !found; ++x) {
            for (y = x + 1; y <= 100 && !found; ++y) {
                if (x == 0 || y == 0)
                    continue;
                z = b / x / y;
                if (z > y && x + y + z == a && x * x + y * y + z * z == c) {
                    found = true;
                    printf("%d %d %d\n", x, y, z);
                    break;
                }
            }
        }
        if (!found) {
            printf("No solution.\n");
        }
    }

    return 0;
}