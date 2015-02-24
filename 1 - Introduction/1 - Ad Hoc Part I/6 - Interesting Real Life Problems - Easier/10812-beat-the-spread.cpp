#include <cstdio>
#include <algorithm>

using namespace std;

int sum, diff, a, b, t;

int main (int argc, char const *argv[]) {

	#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	#endif

	scanf("%d", &t);

	while (t--) {
		scanf("%d %d", &sum, &diff);
		b = (sum - diff) / 2;
		a = sum - b;
		if (a < 0 || b < 0) {
			b = (sum + diff) / 2;
			a = sum - b;
		}
		if (a < b)
			swap(a, b);
		if (a + b == sum && a - b == diff && a >= 0 && b >= 0)
			printf("%d %d\n", a, b);
		else
			printf("impossible\n");
	}
	
	return 0;
}