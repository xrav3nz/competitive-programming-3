#include <cstdio>
#include <set>

std::multiset<int> bills;
int n, k, in;
long long total;

int main (int argc, char const *argv[]) {
    
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    #endif

    while (scanf("%d", &n) != EOF && n != 0) {
        total = 0;
        bills.clear();
        while ( n-- ) {
            scanf("%d", &k);
            while ( k-- ) {
                scanf("%d", &in);
                bills.insert(in);
            }
            total += *(--bills.end()) - *(bills.begin());
            bills.erase(bills.begin());
            bills.erase(--bills.end());
        }
        printf("%lld\n", total);
    }
    
    return 0;
}