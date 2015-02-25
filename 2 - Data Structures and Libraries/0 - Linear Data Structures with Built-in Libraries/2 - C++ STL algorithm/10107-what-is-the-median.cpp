#include <cstdio>
#include <algorithm>

using namespace std;

int size, n, mid, seq[10001];
int main (int argc, char const *argv[]) {

    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    #endif

    while (scanf("%d", &seq[size++]) != EOF) {

        if (size & 1) {
            mid = (size + 1) >> 1;
            nth_element(seq, seq + mid - 1, seq + size);
            printf("%d\n", seq[mid - 1]);
        } else {
            mid = size >> 1;
            nth_element(seq, seq + mid, seq + size);
            n = seq[mid];
            nth_element(seq, seq + mid - 1, seq + size);
            printf("%lld\n", (1LL * n + 1LL * seq[mid - 1]) >> 1);
        }
    }
    
    return 0;
}