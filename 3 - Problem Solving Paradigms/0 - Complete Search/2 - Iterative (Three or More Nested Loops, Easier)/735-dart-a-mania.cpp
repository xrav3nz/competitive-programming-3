#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

typedef std::vector<int> vi;

bool visited[151][151][151];
int combination, permutation, score;
vi dart(3);
char asterisk_line[71];

void generate_asterisk_line() {
    for (int i = 0; i < 70; ++i)
        asterisk_line[i] = '*';
    asterisk_line[70] = '\0';
    return ;
}

void record() {
    // for (int &i : dart)
    //     printf("%d ", i);
    // printf("\n");
    std::sort(dart.begin(), dart.end());
    if (!visited[ dart[0] ][ dart[1] ][ dart[2] ]) {
        visited[ dart[0] ][ dart[1] ][ dart[2] ] = true;
        ++combination;
    }
    ++permutation;

    return ;
}

bool not_valid(int a) {
    if (a > 60)
        return true;
    if ((a >= 0 && a <= 20) || a == 50)
        return false;
    else if ((a & 1) == 0 && a >> 1 <= 20)
        return false;
    else if (a % 3 == 0 && a / 3 <= 20)
        return false;
    return true;
}

int main (int argc, char const *argv[]) {
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    #endif

    generate_asterisk_line();
    while (scanf("%d", &score) != EOF && score > 0) {
        memset(visited, 0, sizeof(visited));
        permutation = combination = 0;
        for (int i = 0; i <= 60 && i <= score; ++i) {
            for (int j = 0; j <= 60 && i + j <= score; ++j) {
                int k = score - i - j;
                if (not_valid(k))
                    continue;
                else if (not_valid(j))
                    continue;
                else if (not_valid(i))
                    continue;
                dart[0] = i;
                dart[1] = j;
                dart[2] = score - i - j;
                record();
            }
        }
        if (!permutation && !combination)
            printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", score);
        else
            printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\nNUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", score, combination, score, permutation);
        printf("%s\n", asterisk_line);
    }
    printf("END OF OUTPUT\n");

    return 0;
}
