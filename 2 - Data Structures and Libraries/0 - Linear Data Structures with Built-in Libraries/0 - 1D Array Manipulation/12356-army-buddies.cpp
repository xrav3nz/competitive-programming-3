#include <cstdio>
#include <cstring>

const int MAX = 1e5+2;
// ln[x] gives the left neighbour of x
// rn[x] gives the right neighbour of x
int ln[MAX], rn[MAX];
int b, s, l, r, id;

int main (int argc, char const *argv[]) {

	#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	#endif

	while (scanf("%d %d", &s, &b)) {
		if (!s && !b)
			return 0;

		for (int i = 1; i <= s; ++i) {
			ln[i] = i - 1;
			rn[i] = i + 1;
		}

		while (b--) {
			scanf("%d %d", &l, &r);

			rn[ln[l]] = rn[r];
			ln[rn[r]] = ln[l];

			for (int i = l; i <= r; ++i) {
				ln[i] = ln[l];
				rn[i] = rn[r];
			}

			if (ln[l] < 1) printf("*");
			else printf("%d", ln[l]);

			if (rn[r] > s) printf(" *\n");
			else printf(" %d\n", rn[r]);
		}

		printf("-\n");

	}
	
	return 0;
}