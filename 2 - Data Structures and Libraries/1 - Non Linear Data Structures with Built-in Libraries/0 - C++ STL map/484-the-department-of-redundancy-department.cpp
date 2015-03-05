#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<int, int> int_count;
vector<int> order;
int n;

int main (int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    #endif

    while (cin >> n) {
        if (++int_count[n] == 1) {
            order.push_back(n);
        }
    }
    for (auto i : order) {
        cout << i << " " << int_count[i] << endl;
    }

    return 0;
}