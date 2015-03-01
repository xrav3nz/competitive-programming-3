#include <iostream>
#include <queue>

using namespace std;

int test, capacity, m, total_length, car_length, counter, side;
char waiting_side[6];

int main (int argc, char const *argv[]) {
    
    ios_base::sync_with_stdio(false);

    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    #endif

    cin >> test;

    while ( test-- ) {

        cin >> capacity >> m;
        capacity *= 100;

        queue<int> q[2];    // q[0] - left, q[1] - right

        while ( m-- ) {
            cin >> car_length >> waiting_side;
            q[ waiting_side[0] == 'r' ].push(car_length);
        }

        counter = 0;
        side = 0;

        while ( !q[0].empty() || !q[1].empty() ) {
            
            if (q[ side ].empty()) {
                side = 1 - side;
                ++counter;
            }

            total_length = 0;
            while ( !q[ side ].empty() ) {
                total_length += q[ side ].front();
                if ( total_length > capacity ) {
                    break;
                }
                q[ side ].pop();
            }

            ++counter;
            side = 1 - side;
        }

        cout << counter << endl;

    }
    
    return 0;
}