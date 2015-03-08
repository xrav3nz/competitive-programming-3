#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

vector<int> polynomial;
int d, k, c, n, xd, p_size;
long long answer;

int main (int argc, char const *argv[]) {
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    #endif

    scanf("%d", &c);
    while (c--) {
        scanf("%d", &p_size);
        polynomial.resize(p_size + 1);
        for (int &i : polynomial) {
            scanf("%d", &i);
        }
        scanf("%d %d", &d, &k);
        xd = 1;
        for (int i = d; i < k ; ++xd, i += xd * d);
        answer = 0;
        for (int i = 0; i < polynomial.size(); ++i) {
            answer += polynomial[i] * pow(xd, i);
        }
        printf("%lld\n", answer);
    }

    return 0;
}