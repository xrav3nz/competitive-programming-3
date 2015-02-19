#include <iostream>
#include <cstring>

using namespace std;

int num_month, m, depre_records;
double down_payment, loan, depre_percent[101], d, monthly_pay, car_value;

int main(int argc, char const *argv[])
{
	// freopen("input.in", "r", stdin);
	
	while (cin >> num_month >> down_payment >> loan >> depre_records) {

		if (num_month < 0)
			break;

		for (int i = 0; i < depre_records; ++i) {
			cin >> m >> d;
			for (int j = m; j <= num_month; ++j)
				depre_percent[j] = d;
		} 

		car_value = 1.0 * (loan + down_payment) * (1 - depre_percent[0]);
		monthly_pay = loan / num_month;


		for (int i = 1; i <= num_month; ++i) {
			if (i == 1 && loan < car_value) {
				printf("0 months\n");
				break;
			}
			loan -= monthly_pay;
			car_value *= (1 - depre_percent[i]);
			if (loan < car_value) {
				printf("%d month%s\n", i, (i == 1) ? "" : "s");
				break;
			}
		}
	}

	return 0;
}