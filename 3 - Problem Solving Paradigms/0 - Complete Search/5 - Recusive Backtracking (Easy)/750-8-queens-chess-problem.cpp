#include <cstdio>

#define MAX_N 9

int T, row, col, count,
	temp[MAX_N], board[92][MAX_N];

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
		scanf("%d %d", &row, &col);


		printf("SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n\n");

		count = 0;

		for(int i = 0; i < 92; ++i){
			if(board[i][col] == row){
				printf("%2d     ", ++count);
				for(int j = 1; j < MAX_N; ++j){
					printf("%2d", board[i][j]);
				}
				printf("\n");
			}
		}
		if(T)
			printf("\n");
	}	

	return 0;
}