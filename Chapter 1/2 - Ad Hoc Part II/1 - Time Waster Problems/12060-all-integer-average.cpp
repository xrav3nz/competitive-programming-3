#include <cstdio>
#include <cmath>

int a, b, c, temp, id, gcd, a_length, b_length, c_length, offset;
bool neg;

int _gcd (int a, int b) {
   if (b==0) return a;
   a %= b;
   return _gcd(b, a);
}

int main (int argc, char const *argv[]) {
	
	#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	#endif

	while (scanf("%d", &c) != EOF && c) {
		printf("Case %d:\n", ++id);
		b = offset = 0;
		for (int i = 0; i < c; ++i) {
			scanf("%d", &temp);
			b += temp;
		}
		neg = (b < 0);
		gcd = _gcd(b, c);
		while (gcd != 1 && b != 0) {
			b /= gcd;
			c /= gcd;
			gcd = _gcd(b, c);
		}
		if (c < 0) c = -c;
		if (b < 0) b = -b;

		a = b / c;
		b = b % c;

		c_length = (int)log10(c * 1.0) + 1;
		b_length = (int)log10(b * 1.0) + 1;
		a_length = (int)log10(a * 1.0) + 1;

		if (b == 0) {
			if (neg)
				printf("- %d\n", a);
			else
				printf("%d\n", a);
		} else if (a != 0) {
			if (neg) {
				for (int i = 0; i < 2 + a_length + c_length - b_length; ++i) printf(" ");
				printf("%d", b);

				printf("\n");

				printf("- %d", a);
				for (int i = 0; i < c_length; ++i) printf("-");

				printf("\n");

				for (int i = 0; i < 2 + a_length; ++i) printf(" ");
				printf("%d", c);

				printf("\n");
			} else {
				for (int i = 0; i < a_length + c_length - b_length; ++i) printf(" ");
				printf("%d", b);

				printf("\n");

				printf("%d", a);
				for (int i = 0; i < c_length; ++i) printf("-");

				printf("\n");

				for (int i = 0; i < a_length; ++i) printf(" ");
				printf("%d", c);

				printf("\n");
			}
		} else {
			if (neg) {
				for (int i = 0; i < c_length - b_length; ++i) printf(" ");
				printf("  %d", b);

				printf("\n");

				printf("- ");
				for (int i = 0; i < c_length; ++i) printf("-");

				printf("\n");

				printf("  %d", c);

				printf("\n");
			} else {
				for (int i = 0; i < c_length - b_length; ++i) printf(" ");
				printf("%d", b);

				printf("\n");

				for (int i = 0; i < c_length; ++i) printf("-");

				printf("\n");

				printf("%d", c);

				printf("\n");
			}
		}
	}
	
	return 0;
}