#include <iostream>
#include <cmath>
#include <stack>
#include <vector>

using namespace std;

#define isOn(S, j) (S & (1 << j))

int n, a, b, length;
vector<int> ones;

int main (int argc, char const *argv[]) {
    
    ios_base::sync_with_stdio(false);

    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    #endif

    while (cin >> n && n != 0) {
        a = b = 0;
        ones.clear();
        length = (int)((log((double)n) / log(2.0)) + 0.5);
        for (int i = 0; i <= length; ++i) {
            if (isOn(n, i)) {
                ones.push_back(i);
            }
        }
        for (int i = 0; i < ones.size(); i += 2) {
            a |= (1 << ones[i]);
        }
        for (int i = 1; i < ones.size(); i += 2) {
            b |= (1 << ones[i]);
        }
        cout << a << " " << b << endl;
    }
    
    return 0;
}
