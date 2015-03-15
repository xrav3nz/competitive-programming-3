#include <cstdio>
#include <vector>
#include <cmath>
#include <climits>

int sq[20000], n, m, max, total;
std::vector< std::vector<int> > answer(9);

void generate_sqaure(){
    for (int i = 0; i < 20000; ++i) {
        sq[i] = i * i;
    }
    return ;
}

int main (int argc, char const *argv[]) {
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    #endif
    generate_sqaure();
    while (scanf("%d", &n) != EOF) {
        if (answer[n].size() == 0) {
            m = n >> 1;
            max = pow(10, m);
            for (int i = 0; i < max; ++i) {
                for (int j = 0; j < max; ++j) {
                    total = i * max + j;
                    if (sq[i + j] == total) {
                        answer[n].push_back(total);
                    }
                }
            }
        }
        for (int& i : answer[n]) {
            printf("%0*d\n", n, i);
        }
    }

    return 0;
}