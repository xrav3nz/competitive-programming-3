#include <cstdio>

int size, r, c, dir;
long long p, cur;
bool found;

int moves[4][2] = {
    1, 0,       // up
    0, -1,      // left
    -1, 0,      // down
    0, 1        // right
};

int main (int argc, char const *argv[]) {

    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    #endif

    while (scanf("%d %lld", &size, &p) != EOF) {
        if (!size && !p)
            return 0;

        // could improve by setting up a mid-point, 
        // if p is less than mid-point, simulate from the start,
        // otherwise from the end

        r = c = (size >> 1) + 1;
        found = false;
        dir = 0;
        cur = 1;
        for (int i = 1; i < size && !found; ++i) {
            for (int j = 0; j < 2 && !found; ++j) {
                r += moves[dir][0] * i;
                c += moves[dir][1] * i;
                cur += i;

                if (cur >= p) {
                    found = true;
                    r -= (cur - p) * moves[dir][0];
                    c -= (cur - p) * moves[dir][1];
                }

                if (++dir > 3)
                    dir = 0;
            }
        }

        if (!found) {
            r += (p - cur) * moves[dir][0];
            c += (p - cur) * moves[dir][1];
        }

        printf("Line = %d, column = %d.\n", r, c);
    }
    
    return 0;
}