#include <iostream>
#include <string>
#include <map>

using namespace std;

int t, total;
string line;
map<string, int> species_count;

int main (int argc, char const *argv[]) {

    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    #endif

    scanf("%d\n", &t);

    while ( t-- ) {

        species_count.clear();
        total = 0;

        while ( getline(cin, line) && line != "" ) {
            ++ species_count[line];
            ++ total;
        }
        for ( auto m : species_count ) {
            printf("%s %.4f\n", m.first.c_str(), m.second * 100.0 / total);
        }

        if ( t ) {
            printf("\n");
        }
    }
    
    return 0;
}