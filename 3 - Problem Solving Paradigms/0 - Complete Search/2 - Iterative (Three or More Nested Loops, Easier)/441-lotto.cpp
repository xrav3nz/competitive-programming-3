#include <cstdio>
#include <vector>

#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))

using namespace std;

const int TOTAL_SELECTION = 6;
vector<int> set_s, combination;
int used, k, current_index, next_index, global_id;

void print_combination() {
    if (current_index == TOTAL_SELECTION) {
        for (int i = 0; i < TOTAL_SELECTION; ++i) {
            printf("%d%c", combination[i], " \n"[i == TOTAL_SELECTION - 1]);
        }
        return ;
    }

    ++current_index;
    for (int i = next_index; i < k; ++i) {
        if (!isOn(used, i)) {
            setBit(used, i);
            combination[current_index - 1]  = set_s[i];
            next_index = i + 1;
            print_combination();
            clearBit(used, i);
        }
    }
    --current_index;
    return ;
}

int main (int argc, char const *argv[]) {
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    #endif

    while (scanf("%d", &k) != EOF && k) {
        if (global_id++)
            printf("\n");
        set_s.resize(k);
        combination.resize(TOTAL_SELECTION);
        for (int &i : set_s) {
            scanf("%d", &i);
        }
        used = 0;
        current_index = 0;
        next_index = 0;
        print_combination();
    }

    return 0;
}