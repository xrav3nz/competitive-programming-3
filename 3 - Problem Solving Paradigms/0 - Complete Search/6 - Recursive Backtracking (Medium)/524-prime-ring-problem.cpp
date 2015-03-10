#include <vector>
#include <cmath>
#include <cstdio>
using namespace std;

#define is_on(S, j) (S & (1 << j))
#define set_bit(S, j) (S |= (1 << j))
#define clear_bit(S, j) (S &= ~(1 << j))

const int MAX_SUM = 16 + 16;
unsigned int prime, used;
int n, id, next_index;
vector<int> ring;

bool determine_prime(int x) {
    int sqrtx = sqrt(x);
    for (int i = 2; i <= sqrtx; ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

bool is_prime(int i) {
    return (prime & (1 << i));
}

void generate_prime() {
    prime = -1;
    for (int i = 2; i < MAX_SUM; ++i) {
        if (is_prime(i) && determine_prime(i)) {
            for (int j = i + i; j < MAX_SUM; j += i) {
                prime &= ~(1 << j);
            }
        }
    }
    return ;
}

void generate_ring() {
    if (next_index == n) {
        if (is_prime(ring[0] + ring[n - 1])) {
            for (int i = 0; i < n; ++i) {
                printf("%d%c", ring[i], " \n"[i == n - 1]);
            }
        }
        return ;
    }
    for (int i = 2; i <= n; ++i) {
        if (!is_on(used, i) && is_prime(ring[next_index - 1] + i)) {
            ring[next_index] = i;
            ++next_index;
            set_bit(used, i);
            generate_ring();
            clear_bit(used, i);
            --next_index;
        }
    }
}

int main (int argc, char const *argv[]) {
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);
    #endif

    generate_prime();
    while (scanf("%d", &n) != EOF) {
        ring.assign(n, 0);
        ring[0] = 1;
        used = 0;
        set_bit(used, 1);
        if (id)
            printf("\n");
        printf("Case %d:\n", ++id);
        next_index = 1;
        generate_ring();
    }

    return 0;
}