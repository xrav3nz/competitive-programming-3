#include <cstdio>
#include <cmath>

int hour, minute;
double angle;

int main (int argc, char const *argv[]) {

	#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	#endif

	while (scanf("%d:%d", &hour, &minute) != EOF) {
		if (!hour && !minute)
			break;
		angle = fabs(hour * 30.0 + minute / 2.0 - minute * 6.0);
		if (angle > 180)
			angle = fabs(360 - angle);
		printf("%.3lf\n", angle);
	}
	
	return 0;
}