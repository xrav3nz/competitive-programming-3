#include <cstdio>

#define MAX_N 9

int T, count, min, sum,
	temp[MAX_N], board[92][MAX_N], input[MAX_N];

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

	generateEightQueen(1, 1);

	while(scanf("%d %d %d %d %d %d %d %d", &input[1], &input[2], &input[3], &input[4], &input[5], &input[6], &input[7], &input[8]) != EOF){
		min = 9;
		for(int k = 0; k < 92; ++k){
			sum = 0;
			for(int j = 1; j < MAX_N; ++j){
				sum += (input[j] != board[k][j]);
			}
			if(sum < min) min = sum;
		}
		printf("Case %d: %d\n", ++T, min);
	}	

	return 0;
}