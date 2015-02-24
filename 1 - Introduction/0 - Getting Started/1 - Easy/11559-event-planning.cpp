#include <iostream>

#define MAX_WEEKS 15
#define MAX_HOTELS 20

using namespace std;

int num_participants, budget, num_hotels, num_weeks, min_cost;

struct Hotel
{
	int price, weeks[MAX_WEEKS];
	void read(){
		cin >> price;
		for(int i = 0; i < num_weeks; ++i)
			cin >> weeks[i];
		return ;
	}
} hotels[MAX_HOTELS];

int main(){

	freopen("input.in", "r", stdin);

	ios_base::sync_with_stdio(false);

	while(cin >> num_participants >> budget >> num_hotels >> num_weeks){

		for(int i = 0; i < num_hotels; ++i)	
			hotels[i].read();

		min_cost = budget + 1;

		for(int i = 0; i < num_hotels; ++i){
			if(hotels[i].price * num_participants > budget)
				continue;
			for(int j = 0; j < num_weeks; ++j)
				if(hotels[i].weeks[j] >= num_participants && hotels[i].price * num_participants < min_cost)
					min_cost = hotels[i].price * num_participants;
		}

		if(min_cost > budget)
			cout << "stay home" << endl;
		else
			cout << min_cost << endl;
	}

	return 0;
}