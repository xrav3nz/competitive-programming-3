#include <cstdio>
#include <bitset>

std::bitset<1000000001> jack;
int n, m, in, total;

int main (int argc, char const *argv[]) {

    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    #endif

    while (scanf("%d %d", &n, &m) != EOF) {
        if (!n  && !m) {
            break;
        } else if (!n || !m) {
            printf("0\n");
            continue;
        }
        jack.reset();
        total = 0;
        while ( n-- ) {
            scanf("%d", &in);
            jack[in] = true;
        }
        while ( m-- ) {
            scanf("%d", &in);
            if (jack[in]) {
                ++total;
            }
        }
        printf("%d\n", total);
    }
    
    return 0;
}