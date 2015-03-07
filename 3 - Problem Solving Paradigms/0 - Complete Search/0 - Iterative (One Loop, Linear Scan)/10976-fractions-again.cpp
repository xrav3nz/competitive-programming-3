#include <cstdio>
#include <vector>

using namespace std;

#define x first
#define y second

long long k, x, y;
vector< pair<long long, long long> > result;

int main (int argc, char const *argv[]) {
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    #endif

    while (scanf("%lld", &k) != EOF) {
        result.clear();
        y = x = k;
        while (x >= y) {
            ++y;
            x = (k * y) / (y - k);
            if (x * (y - k) == k * y) {
                result.push_back( make_pair(x, y) );
            }
        }
        printf("%ld\n", result.size());
        for (auto p : result) {
            printf("1/%lld = 1/%lld + 1/%lld\n", k, p.x, p.y);
        }
    }

    return 0;
}