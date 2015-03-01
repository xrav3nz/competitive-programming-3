#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define GREEN 0
#define BLUE 1
#define green first
#define blue second

priority_queue< int > pq[2];
vector< pair< int, int > > battlefield;
int n, b, low_b, sg, sb, power, win, temp;

int _abs (const int &a) {
    return (a < 0) ? -a : a;
}

int main (int argc, char const *argv[]) {

    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("input.out", "w", stdout);
    #endif

    scanf("%d", &n);

    while ( n-- ) {
        scanf("%d %d %d", &b, &sg, &sb);
        battlefield.resize(b);
        while ( sg-- ) {
            scanf("%d", &power);
            pq[ GREEN ].push(power);
        }
        while ( sb-- ) {
            scanf("%d", &power);
            pq[ BLUE ].push(power);
        }
        while ( !pq[ BLUE ].empty() && !pq[ GREEN ].empty() ) {
            temp = min( pq[GREEN].size(), pq[BLUE].size() );
            low_b = min( b, temp );
            for ( int i = 0; i < low_b; ++i ) {
                battlefield[i].green = pq[ GREEN ].top();
                pq[ GREEN ].pop();
                battlefield[i].blue = pq[ BLUE ].top();
                pq[ BLUE ].pop();
            }
            for (int i = 0; i < low_b; ++i) {
                if (battlefield[i].green == battlefield[i].blue) {
                    continue;
                }
                win = battlefield[i].green > battlefield[i].blue ? GREEN : BLUE;
                pq[ win ].push( _abs( battlefield[i].green - battlefield[i].blue ) );
            }
        }
        if ( pq[BLUE].empty() && pq[GREEN].empty() ) {
            printf("green and blue died\n");
        } else {
            win = pq[BLUE].empty() ? GREEN : BLUE;
            printf("%s wins\n", (win == GREEN) ? "green" : "blue");
            while ( !pq[ win ].empty() ) {
                printf("%d\n", pq[ win ].top());
                pq[ win ].pop();
            }
        }
        if ( n ) {
            printf("\n");
        }
    }    
    
    return 0;
}