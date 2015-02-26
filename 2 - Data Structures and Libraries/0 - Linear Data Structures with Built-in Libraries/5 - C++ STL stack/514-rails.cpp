#include <cstdio>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

stack<int> station;
vector<int> order;
int n, a, side;

void clear( stack<int> &s ) {
   stack<int> empty;
   swap( s, empty );
}

int main (int argc, char const *argv[]) {

    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    #endif

    while (scanf("%d", &n) != EOF && n != 0) {
        while (scanf("%d", &a) != EOF && a != 0) {
            order.resize(n);
            order[0] = a;
            for (int i = 1; i < n; ++i) {
                scanf("%d", &order[i]);
            }
            clear(station);
            side = 1;
            for (auto i : order) {
                if (i >= side) {
                    while (side <= i) {
                        station.push(side);
                        ++side;
                    }
                }
                if (!station.empty() && station.top() == i) {
                    station.pop();
                }
            }
            if (station.empty()) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
        printf("\n");
    }
    
    return 0;
}