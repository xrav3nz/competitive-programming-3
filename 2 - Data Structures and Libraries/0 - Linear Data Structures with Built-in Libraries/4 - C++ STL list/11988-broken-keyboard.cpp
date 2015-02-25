#include <iostream>
#include <list>

using namespace std;

list<char> display;
list<char>::iterator it;
string line;

int main (int argc, char const *argv[]) {
    
    ios_base::sync_with_stdio(false);

    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    #endif

    while (getline(cin, line)) {
        display.clear();
        it = display.begin();
        for (auto c : line) {
            if (c == '[')
                it = display.begin();
            else if (c == ']')
                it = display.end();
            else 
                display.insert(it, c);
        }
        for (auto c : display)
            cout << c;
        cout << endl;
    }
    
    return 0;
}