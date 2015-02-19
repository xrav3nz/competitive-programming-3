#include <cstdio>

int t, a, b;

int main(){

	scanf("%d", &t);

	while(t--){
		scanf("%d %d", &a, &b);
		if(a < b)
			printf("<\n");
		else if(a > b)
			printf(">\n");
		else
			printf("=\n");
	}

	return 0;

}