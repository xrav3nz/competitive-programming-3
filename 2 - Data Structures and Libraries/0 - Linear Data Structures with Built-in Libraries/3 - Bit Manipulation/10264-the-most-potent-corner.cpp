#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> c_weight, c_potent;
int n, total, max_potent, c;

int main (int argc, char const *argv[]) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    #endif

    while (cin >> n) {
        total = pow(2, n);
        c_weight.resize(total);
        c_potent.assign(total, 0);
        max_potent = 0;
        for (int i = 0; i < total; ++i) {
            cin >> c_weight[i];
            for (int j = 0; j < n; ++j) {
                c = i;
                c ^= (1 << j);      // toggle the bit at j to find a neighbouring corner
                c_potent[c] += c_weight[i];
            }
        }
        for (int i = 0; i < total; ++i) {
            for (int j = 0; j < n; ++j) {
                c = i;
                c ^= (1 << j);
                if (max_potent < c_potent[i] + c_potent[c]) {
                    max_potent = c_potent[i] + c_potent[c];
                }
            }
        }
        cout << max_potent << endl;
    }
    
    return 0;
}