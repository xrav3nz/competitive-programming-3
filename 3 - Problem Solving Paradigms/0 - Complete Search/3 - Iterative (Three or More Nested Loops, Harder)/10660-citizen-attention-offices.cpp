#include <cstdio>
#include <vector>
#include <climits>

struct Cell {
    int row, col, population;
};

std::vector<Cell> non_null_population;
std::vector<int> temp, office, row, col;
int t, n, temp_distance, min_distance;

int abs(int x) {
    return x < 0 ? -x : x;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int calc_distance(Cell& r) {
    int min_dist = INT_MAX, temp_dist;
    for (int i = 0; i < 5; ++i) {
        temp_dist = abs(r.row - row[i]) + abs(r.col - col[i]);
        temp_dist *= r.population;
        min_dist = min(temp_dist, min_dist);
    }
    return min_dist;
}

int main (int argc, char const *argv[]) {
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    #endif

    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        non_null_population.resize(n);
        for (auto&& i : non_null_population) {
            scanf("%d %d %d", &i.row, &i.col, &i.population);
        }
        min_distance = INT_MAX;
        for (int a = 0; a < 25; ++a) {
            for (int b = a + 1; b < 25; ++b) {
                for (int c = b + 1; c < 25; ++c) {
                    for (int d = c + 1; d < 25; ++d) {
                        for (int e = d + 1; e < 25; ++e) {
                            temp_distance = 0;
                            row = {a / 5, b / 5, c / 5, d / 5, e / 5};
                            col = {a % 5, b % 5, c % 5, d % 5, e % 5};
                            for (auto&& i : non_null_population) {
                                temp_distance += calc_distance(i);
                            }
                            if (temp_distance < min_distance) {
                                min_distance = temp_distance;
                                office = {a, b, c, d, e};
                            }
                        }
                    }
                }
            }
        }
        for (int i = 0; i < 5; ++i) {
            printf("%d%c", office[i], " \n"[i == 4]);
        }
    }

    return 0;
}