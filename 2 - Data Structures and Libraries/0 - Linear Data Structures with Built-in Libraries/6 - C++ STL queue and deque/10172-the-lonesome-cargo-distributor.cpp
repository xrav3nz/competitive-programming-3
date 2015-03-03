#include <cstdio>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

int t, n, capacity, qsize, Q, cargo, total_time, cur;
bool is_done;
vector< queue<int> > station;
stack< int > carrier;

int main (int argc, char const *argv[]) {

    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    #endif

    scanf("%d", &t);

    while (t--) {
        scanf("%d %d %d", &n, &capacity, &qsize);
        station.resize(n);

        for (int i = 0; i < n; ++i) {
            scanf("%d", &Q);
            if (Q == 0) {
                continue;
            }
            while (Q--) {
                scanf("%d", &cargo);
                station[i].push(cargo - 1);
            }
        }

        total_time = 0;
        cur = 0;

        while (true) {

            // unload
            while (!carrier.empty()) {
                if (carrier.top() == cur) {
                    carrier.pop();
                } else if (station[cur].size() < qsize) {
                    station[cur].push(carrier.top());
                    carrier.pop();
                } else {
                    break;
                }
                ++ total_time;
            }

            // loading
            while (!station[cur].empty() && carrier.size() < capacity) {
                carrier.push(station[cur].front());
                station[cur].pop();
                ++ total_time;
            }

            is_done = carrier.empty();

            for (int i = 0; i < n; ++i) {
                is_done &= station[i].empty();
            }

            if (is_done) {
                break;
            }

            cur = (cur + 1) % n;
            total_time += 2;
        }

        printf("%d\n", total_time);
    }

    return 0;
}