#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string input, output;

int main (int argc, char const *argv[]) {
    
    ios_base::sync_with_stdio(false);

    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    #endif

    while (cin >> input && input != "#") {
        output = "";
        if (next_permutation(input.begin(), input.end()))
            output = input;
        if (output == "")
            cout << "No Successor" << endl;
        else
            cout << output << endl;
    }    
    
    return 0;
}