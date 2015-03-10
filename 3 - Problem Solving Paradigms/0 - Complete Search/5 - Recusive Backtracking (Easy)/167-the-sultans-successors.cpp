#include <cstdio>

#define MAX_N 9

int T, count, max, sum,
	temp[MAX_N], board[92][MAX_N], input[MAX_N][MAX_N];

int abs(int a){
	return a < 0 ? -a : a;
}

bool isLegal(int i, int j){
	for(int c = 1; c < j; ++c){
		if(temp[c] == i || abs(c - j) == abs(temp[c] - i)) return false;
	}
	return true;
}

void generateEightQueen(int startRow, int startCol){

	if(startCol == MAX_N){
		for(int i = 1; i < MAX_N; ++i){
			board[count][i] = temp[i];
		}
		++count;
		return ;
	}

	for(int i = startRow; i < MAX_N; ++i){
		if(isLegal(i, startCol)){
			temp[startCol] = i;
			generateEightQueen(1, startCol + 1);
			temp[startCol] = 0;
		}
	}

	return ;
}

int main(int argc, char const *argv[])
{
	freopen("input.in", "r", stdin);

	scanf("%d", &T);

	generateEightQueen(1, 1);

	while(T--){
		for(int i = 1; i < MAX_N; ++i){
			for(int j = 1; j < MAX_N; ++j){
				scanf("%d", &input[i][j]);
			}
		}
		max = -1;
		for(int k = 0; k < 92; ++k){
			sum = 0;
			for(int i = 0; i < 100000; ++i){

			}
			for(int j = 1; j < MAX_N; ++j){
				sum += input[board[k][j]][j];
			}
			if(sum > max) max = sum;
		}
		printf("%5d\n", max);
	}	

	return 0;
}