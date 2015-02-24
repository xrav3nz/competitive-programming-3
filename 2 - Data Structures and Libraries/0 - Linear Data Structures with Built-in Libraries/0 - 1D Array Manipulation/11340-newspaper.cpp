#include <cstdio>
#include <cstring>

const int MAX = 10001;
int n, k, m, val[256], total;
char line[MAX], c[2];

int main (int argc, char const *argv[]) {

	#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	#endif

	scanf("%d", &n);

	while (n--) {

		memset(val, 0, sizeof(val));
		total = 0;

		scanf("%d", &k);

		while (k--) {
			scanf("%s", c);
			scanf("%d", &val[c[0]]);
		}

		scanf("%d\n", &m);

		while (m--) {
			fgets (line, sizeof(line), stdin);
			for (int i = 0; line[i]; ++i)
				total += val[line[i]];
		}

		printf("%.2lf$\n", total / 100.0);
	}
	
	return 0;
}