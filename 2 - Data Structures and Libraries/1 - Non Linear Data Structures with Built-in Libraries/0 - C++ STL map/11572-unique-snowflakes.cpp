#include <cstdio>
#include <map>
#include <climits> 

using namespace std;

int t, n, snowflake, max_total, start;
map< int, int > last_index;
map< int, int >::iterator it;

int main (int argc, char const *argv[]) {
    
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    #endif

    scanf("%d", &t);

    while ( t-- ) {
        max_total = 0;
        last_index.clear();
        start = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &snowflake);
            it = last_index.find(snowflake);
            if ( it == last_index.end() || it->second < start) {
                last_index[snowflake] = i;
            } else {
                if ( i - start > max_total ) {
                    max_total = i - start;
                }
                start = it->second + 1;
                it->second = i;
            }
        }
        if ( n - start > max_total ) {
            max_total = n - start;
        }
        printf("%d\n", max_total);
    }    
    
    return 0;
}