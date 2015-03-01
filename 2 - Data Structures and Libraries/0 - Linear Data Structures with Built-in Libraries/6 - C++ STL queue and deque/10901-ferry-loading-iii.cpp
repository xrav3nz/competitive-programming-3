#include <iostream>
#include <queue>

using namespace std;

int test, n, t, m, arrival_time, global_time, side, counter;
char waiting_side[6];
int output[10001];

int main (int argc, char const *argv[]) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    #endif

    cin >> test;

    while (test--) {

        cin >> n >> t >> m;
        queue< pair<int, int> > q[2], ferry;    // q[0] left q, q[1] right q

        for (int i = 0; i < m; ++i) {
            cin >> arrival_time >> waiting_side;
            q[waiting_side[0] == 'r'].push(make_pair(arrival_time, i));
        }

        global_time = 0;
        side = 0;

        while (!q[0].empty() || !q[1].empty()) {
            counter = 0;
            int temp;
            if (q[0].empty()) {
                temp = q[1].front().first;
            } else if (q[1].empty()) {
                temp = q[0].front().first;
            } else {
                temp = min(q[0].front().first, q[1].front().first);
            }
            global_time = max (global_time, temp);
            while (!q[side].empty() && q[side].front().first <= global_time && counter < n) {
                ++counter;
                output[q[side].front().second] = global_time + t;
                q[side].pop();
            }
            global_time += t;
            side = 1 - side;
        }

        for (int i = 0; i < m; ++i) {
            cout << output[i] << endl;
        }

        if (test) {
            cout << endl;
        }
    }
    
    return 0;
}