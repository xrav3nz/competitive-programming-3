#include <iostream>
#include <string>

using namespace std;

string name, requirement;

int n, p, global_count, highest_compliance, requirements_met;
double lowest_price, price;
string compliance_name;

int main (int argc, char const *argv[]) {
	
	ios_base::sync_with_stdio(false);

	#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	#endif

	while (cin >> n >> p && (n || p)) {

		if (global_count)
			printf("\n");

		++global_count;

		highest_compliance = -1;
		lowest_price = 0;

		getline(cin, requirement);
		for (int i = 0; i < n; ++i)
			getline(cin, requirement);

		for (int i = 0; i < p; ++i) {
			getline(cin, name);
			cin >> price >> requirements_met;
			if (requirements_met > highest_compliance) {
				highest_compliance = requirements_met;
				lowest_price = price;
				compliance_name = name;
			} else if (requirements_met == highest_compliance && price < lowest_price) {
				lowest_price = price;
				compliance_name = name;
			}
			getline(cin, requirement);
			for (int j = 0; j < requirements_met; ++j)
				getline(cin, requirement);
		}

		printf("RFP #%d\n", global_count);
		printf("%s\n", compliance_name.c_str());
	}
	
	return 0;
}