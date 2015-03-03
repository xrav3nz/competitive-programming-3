#include <iostream>
#include <string>
#include <queue>
#include <string>
#include <vector>
#include <functional>

using namespace std;

#define id first
#define p second

typedef pair< int, int > pii;

class ComparePii {
public:
    bool operator() (const pii &a, const pii &b) {
        if (a.p == b.p)
            return a.id > b.id;
        return a.p > b.p;
    }
};

priority_queue< pii, vector< pii >, ComparePii > result;
vector< int > interval(3001);
pii current;
string cmd;
int q_num, period, n;

int main (int argc, char const *argv[]) {

    ios_base::sync_with_stdio(false);

    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    #endif

    while (cin >> cmd && cmd[0] != '#') {
        cin >> q_num >> period;
        result.push( make_pair( q_num, period ) );
        interval[q_num] = period;
    }

    cin >> n;

    while (n--) {
        current = result.top();
        result.pop();
        cout << current.id << "\n";
        current.p += interval[ current.id ];
        result.push( current );
    }

    return 0;
}