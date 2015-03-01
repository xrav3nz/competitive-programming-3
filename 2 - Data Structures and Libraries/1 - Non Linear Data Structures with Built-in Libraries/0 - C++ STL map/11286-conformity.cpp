#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector< string > frosh, course(5);
map< string, int > frequency;
int n, popular, total;

int main (int argc, char const *argv[]) {
    
    ios_base::sync_with_stdio(false);

    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    #endif

    while (cin >> n && n != 0) {

        frequency.clear();
        frosh.assign(n, "");
        popular = -1;
        total = 0;

        for ( int i = 0; i < n; ++i ) {
            for (int j = 0; j < 5; ++j) {
                cin >> course[j];
            }
            sort( course.begin(), course.end() );
            for (int j = 0; j < 5; ++j) {
                frosh[i] += course[j];
            }
            ++ frequency[ frosh[i] ];
            if ( frequency[ frosh[i] ] > popular ) {
                popular = frequency[ frosh[i] ];
            }
        }

        for ( auto combination : frosh ) {
            if ( frequency[combination] == popular ) {
                ++total;
            }
        }

        cout << total << endl;

    }
    
    return 0;
}