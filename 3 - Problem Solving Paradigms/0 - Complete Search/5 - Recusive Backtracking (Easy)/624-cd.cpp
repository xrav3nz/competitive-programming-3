#include <cstdio>
#include <vector>

using namespace std;

int tape_length, num_cds, used, sum, max_sum, max_sum_used;
vector<int> cds;

void find_best_solution(int next_index){
    for (int i = next_index; i < num_cds; ++i) {
        sum += cds[i];
        used |= (1 << i);
        if (sum <= tape_length) {
            if (sum > max_sum) {
                max_sum = sum;
                max_sum_used = used;
            }
            find_best_solution(i + 1);
        }
        used &= ~(1 << i);
        sum -= cds[i];
    }
    return ;
}

int main (int argc, char const *argv[]) {
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    #endif

    while (scanf("%d %d", &tape_length, &num_cds) != EOF) {
        cds.resize(num_cds);
        for (int& cd : cds) {
            scanf("%d", &cd);
            sum += cd;
        }
        if (sum < tape_length) {
            for (int& cd : cds) {
                printf("%d ", cd);
            }
            printf("sum:%d\n", sum);
        } else {
            sum = used = 0;
            max_sum = 0;
            find_best_solution(0);
            for (int i = 0; i < num_cds; ++i) {
                if (max_sum_used & (1 << i)) {
                    printf("%d ", cds[i]);
                }
            }
            printf("sum:%d\n", max_sum);
        }
    }

    return 0;
}