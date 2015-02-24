#include <cstdio>
#include <algorithm>

int a[3], t;

int main(){

	freopen("input.in", "r", stdin);

	scanf("%d", &t);

	for(int i = 1; i <= t; ++i){
		for(int *j = a; j < a + 3; ++j)
			scanf("%d", j);
		std::sort(a, a + 3);
		printf("Case %d: %d\n", i, a[1]);
	}

	return 0;
}