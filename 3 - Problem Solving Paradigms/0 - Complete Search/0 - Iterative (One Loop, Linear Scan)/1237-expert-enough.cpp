#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Data {
    string maker;
    int low, high;
    Data() {
        maker = "";
        low = high = 0;
    }
    bool operator< (const Data &b) const {
        if (low == b.low)
            return high < b.high;
        return low < b.low;
    }
};

vector< Data > aes;     // automobile expert system
int test_case, num_entry, num_query, query_price, car_id;

int perform_query(int &price) {
    car_id = -1;
    for (int i = 0; i < num_entry; ++i) {
        if (aes[i].low > price) {
            break;
        } else if (price <= aes[i].high){
            if (car_id == -1) {
                car_id = i;
            } else {
                car_id = -1;
                break;
            }
        }
    }
    return car_id;
}

int main (int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    #endif

    cin >> test_case;

    while (test_case--) {
        cin >> num_entry;
        aes.resize(num_entry);
        for (int i = 0; i < num_entry; ++i) {
            cin >> aes[i].maker >> aes[i].low >> aes[i].high;
        }
        sort(aes.begin(), aes.end());
        cin >> num_query;
        while (num_query--) {
            cin >> query_price;
            perform_query(query_price);
            if (car_id == -1) {
                cout << "UNDETERMINED\n";
            } else {
                cout << aes[car_id].maker << "\n";
            }
        }
        if (test_case) {
            cout << "\n";
        }
    }

    return 0;
}