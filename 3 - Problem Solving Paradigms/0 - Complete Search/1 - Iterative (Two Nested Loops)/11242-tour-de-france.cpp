#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int num_front, num_rear;
vector<int> teeth_front, teeth_rear;
vector<double> ratios;
double max_spread;

int main (int argc, char const *argv[]) {
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    #endif

    while (scanf("%d", &num_front) != EOF && num_front && scanf("%d", &num_rear) != EOF) {
        teeth_front.resize(num_front);
        teeth_rear.resize(num_rear);
        ratios.clear();
        for (int& i : teeth_front) {
            scanf("%d", &i);
        }
        for (int& i : teeth_rear) {
            scanf("%d", &i);
        }
        for (int i : teeth_rear) {
            for (int j : teeth_front) {
                ratios.push_back(i * 1.0 / j);
            }
        }
        sort(ratios.begin(), ratios.end());
        max_spread = 0;
        for (int i = 1; i < ratios.size(); ++i) {
            max_spread = max(max_spread, ratios[i] / ratios[i - 1]);
        }
        printf("%.2f\n", max_spread);
    }

    return 0;
}