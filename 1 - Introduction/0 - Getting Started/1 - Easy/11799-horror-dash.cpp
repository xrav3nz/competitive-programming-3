#include <cstdio>

int t, n, a, max;

int main(){
	freopen("input.in", "r", stdin);

	scanf("%d", &t);

	for(int i = 1; i <= t; ++i){
		scanf("%d", &n);
		max = 0;
		while(n--){
			scanf("%d", &a);
			if(a > max) max = a;
		}
		printf("Case %d: %d\n", i, max);
	}

	return 0;
}