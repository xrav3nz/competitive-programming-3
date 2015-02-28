#include <iostream>
#include <bitset>

using namespace std;

const int MAX = 1e6+1;

int n, m, a, b, r;
bitset<MAX> cal;
bool conflict;

int main (int argc, char const *argv[]) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    #endif

    while (cin >> n >> m) {
        if (!n && !m) {
            break;
        }
        conflict = false;
        cal.reset();
        while (n--) {
            cin >> a >> b;
            if (conflict) {
                continue;
            }
            for (int i = a; i < b && !conflict; ++i) {
                if (cal[i]) {
                    conflict = true;
                } else {
                    cal[i] = true;
                }
            }
        }

        while (m--) {
            cin >> a >> b >> r;
            do {
                for (int i = a; i < b && i < MAX && !conflict; ++i) {
                    if (cal[i]) {
                        conflict = true;
                    } else {
                        cal[i] = true;
                    }
                }
                a += r;
                b += r;
            } while (!conflict && a < MAX);
        }
        if (conflict) {
            cout << "CONFLICT\n";
        } else {
            cout << "NO CONFLICT\n";
        }
    }
    
    return 0;
}