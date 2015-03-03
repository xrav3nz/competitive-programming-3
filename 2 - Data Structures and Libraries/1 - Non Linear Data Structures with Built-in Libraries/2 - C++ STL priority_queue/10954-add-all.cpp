#include <iostream>
#include <queue>
#include <functional>
#include <vector>

using namespace std;

int n, temp, sum;
long long total;

int main (int argc, char const *argv[]) {

    ios_base::sync_with_stdio(false);

    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    #endif

    while ( cin >> n && n ) {
        priority_queue< int, vector<int>, greater<int> > numbers;
        for ( int i = 0; i < n; ++i ) {
            cin >> temp;
            numbers.push( temp );
        }
        total = 0;
        while ( numbers.size() > 1 ) {
            sum = numbers.top();
            numbers.pop();
            sum += numbers.top();
            numbers.pop();
            numbers.push( sum );
            total += sum * 1LL;
        }
        cout << total << endl;
    }

    return 0;
}