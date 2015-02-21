// I think there is a mistake in the problem statement
// "Note that O (zero) and 0 (the letter) are considered the same character and therefore ONLY the letter "0" is a valid character."
// Apparently the author messed up the O and 0, I now couldn't tell which is which either...

#include <cstdio>
#include <cstring>

int reverse[256], size;
char input[22];
bool mirror, palin;

void InitReverse () {
	for (int i = 0; i < 256; ++i)
		reverse[i] = -1;

	reverse['A'] = 'A';
	reverse['E'] = '3';
	reverse['H'] = 'H';
	reverse['I'] = 'I';
	reverse['J'] = 'L';
	reverse['L'] = 'J';
	reverse['M'] = 'M';
	reverse['O'] = 'O';
	reverse['S'] = '2';
	reverse['T'] = 'T';
	reverse['U'] = 'U';
	reverse['V'] = 'V';
	reverse['W'] = 'W';
	reverse['X'] = 'X';
	reverse['Y'] = 'Y';
	reverse['Z'] = '5';
	reverse['1'] = '1';
	reverse['2'] = 'S';
	reverse['3'] = 'E';
	reverse['5'] = 'Z';
	reverse['8'] = '8';

	return ;
}

bool IsMirrored () {
	for (int i = 0; i < size; ++i) {
		if (reverse[input[i]] != input[size - 1 - i])
			return false;
	}
	return true;
}

bool IsPalindrome () {
	for (int i = 0, j = size - 1; i < j; ++i, --j) {
		if (input[i] != input[j])
			return false;
	}
	return true;
}

int main (int argc, char const *argv[]) {

	#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	#endif

	InitReverse();

	while (scanf("%s", input) != EOF) {

		size = strlen(input);
		palin = IsPalindrome();
		mirror = IsMirrored();

		if (palin && mirror)
			printf("%s -- is a mirrored palindrome.\n", input);
		else if (palin)
			printf("%s -- is a regular palindrome.\n", input);
		else if (mirror)
			printf("%s -- is a mirrored string.\n", input);
		else
			printf("%s -- is not a palindrome.\n", input);

		printf("\n");
	}
	
	return 0;
}