#include <cstdio>

const int mode[5] = {2, 4, 6, 9, 12};
int s, d, k;

int main (int argc, char const *argv[]) {
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    #endif

    while (scanf("%d%d", &s, &d) != EOF) {
        k = 1;
        while( s*(5-k) - d*k > 0 ) k++;
        k = s * (12 - mode[k - 1]) - d * mode[k - 1];
        if(k < 0)
            printf("Deficit\n");
        else
            printf("%d\n", k);
    }

    return 0;
}
