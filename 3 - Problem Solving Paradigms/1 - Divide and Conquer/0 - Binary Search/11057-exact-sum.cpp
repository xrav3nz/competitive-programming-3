#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> book_costs;
int n, money, half, temp, max_i;

int main (int argc, char const *argv[]) {
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    #endif

    while (scanf("%d", &n) != EOF) {
        book_costs.resize(n);
        for (int& cost : book_costs) {
            scanf("%d", &cost);
        }
        sort(book_costs.begin(), book_costs.end());
        scanf("%d", &money);
        half = money >> 1;
        max_i = 0;
        for (int& cost : book_costs) {
            if (cost > half) {
                break;
            } else if (cost > max_i) {
                temp = cost;
                cost = -1;
                if (binary_search(book_costs.begin(), book_costs.end(), (money - temp))) {
                    max_i = temp;
                    if (max_i == half)
                        break;
                }
                cost = temp;
            }
        }
        printf("Peter should buy books whose prices are %d and %d.\n\n", max_i, (money - max_i));
    }

    return 0;
}