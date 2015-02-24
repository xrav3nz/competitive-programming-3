#include <cstdio>
#include <vector>

using namespace std;

struct Sheet {
	pair<int, int> front, back;
	Sheet() {
		front.first = 0;
		front.second = 0;
		back.first = 0;
		back.second = 0;
	}
};

vector<Sheet> booklet;
int total, n;

int main (int argc, char const *argv[]) {

	#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	#endif

	while (scanf("%d", &n) != EOF && n) {
		if (n % 4 == 0)
			total = n / 4;
		else
			total = n / 4 + 1;

		booklet.clear();
		booklet.resize(total);

		for (int i = 0, j = 1; i < total && j <= n; ++i, ++j) {
			booklet[i].front.second = j++;
			if (j <= n)
				booklet[i].back.first = j;
		}

		for (int i = total - 1, j = total * 2 + 1; j <= n && i >= 0; --i, ++j) {
			booklet[i].back.second = j++;
			if (j <= n)
				booklet[i].front.first = j;
		}

		printf("Printing order for %d pages:\n", n);
		for (int i = 0; i < total; ++i) {
			if (booklet[i].front.first > 0 || booklet[i].front.second > 0) {
				printf("Sheet %d, front: ", i + 1);
				if (booklet[i].front.first > 0)
					printf("%d, ", booklet[i].front.first);
				else
					printf("Blank, ");

				if (booklet[i].front.second > 0)
					printf("%d\n", booklet[i].front.second);
				else
					printf("Blank\n");

			}

			if (booklet[i].back.first > 0 || booklet[i].back.second > 0){
				printf("Sheet %d, back : ", i + 1);
				if (booklet[i].back.first > 0)
					printf("%d, ", booklet[i].back.first);
				else
					printf("Blank, ");

				if (booklet[i].back.second > 0)
					printf("%d\n", booklet[i].back.second);
				else
					printf("Blank\n");

			}
			
		}
	}
	
	return 0;
}