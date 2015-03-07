#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> sales;
vector<int>::iterator it;
int test_case, n, a, total;

int main (int argc, char const *argv[]) {
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    #endif

    scanf("%d", &test_case);

    while (test_case--) {
        scanf("%d", &n);
        total = 0;
        sales.clear();
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a);
            it = lower_bound(sales.begin(), sales.end(), a);
            sales.insert(it, a);
            if (i) {
                total += upper_bound(sales.begin(), sales.end(), a) - sales.begin() - 1;
            }
        }
        printf("%d\n", total);
    }

    return 0;
}