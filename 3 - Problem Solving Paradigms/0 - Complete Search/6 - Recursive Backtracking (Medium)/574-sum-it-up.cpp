#include <cstdio>
#include <vector>

using namespace std;

int goal, n, counter, sum;
vector<int> numbers, sums;
vector< vector<int> > answers;

bool is_duplicate() {
    for (vector<int>& vi : answers) {
        if (vi.size() == sums.size() && vi == sums)
            return true;
    }
    return false;
}

void generate_sums(int next_index) {
    if (sum > goal) {
        return ;
    } else if (sum == goal) {
        if (!is_duplicate())
            answers.push_back(sums);
        return ;
    }
    for (int i = next_index; i < n; ++i) {
        sum += numbers[i];
        sums.push_back(numbers[i]);
        generate_sums(i + 1);
        sums.pop_back();
        sum -= numbers[i];
    }
}

int main (int argc, char const *argv[]) {
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    #endif

    while (scanf("%d %d", &goal, &n) != EOF) {
        if (!goal && !n)
            break;
        numbers.resize(n);
        sum = 0;
        for (int& i : numbers) {
            scanf("%d", &i);
            sum += i;
        }
        printf("Sums of %d:\n", goal);
        if (sum < goal) {
            printf("NONE\n");
        } else {
            sum = 0;
            answers.clear();
            generate_sums(0);
            counter = answers.size();
            if (counter) {
                for (vector<int>& vi : answers) {
                    for (int i = 0; i < vi.size(); ++i)
                        printf("%d%c", vi[i], "+\n"[i == vi.size() - 1]);
                }
            } else {
                printf("NONE\n");
            }
        }
    }

    return 0;
}