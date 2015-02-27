#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

string in, out, seq;
bool stop;

bool AreAnagram () {
    string _in = in;
    string _out = out;
    sort (_in.begin(), _in.end());
    sort (_out.begin(), _out.end());
    return (_in == _out);
}

bool StackOp () {
    stack<char> s;
    int i = 0, j = 0;
    for (auto c : seq) {
        if (c == 'i') {
            s.push(in[i++]);
        } else {
            if (s.empty()) {
                return false;
            } else {
                if (out[j++] != s.top())
                    return false;
                s.pop();
            }
        }
    }
    return true;
}

int main (int argc, char const *argv[]) {
    
    ios_base::sync_with_stdio(false);

    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    #endif

    while (cin >> in >> out) {
        cout << '[' << endl;
        if (in.size() != out.size() || !AreAnagram()) {
            cout << ']' << endl;
            continue;
        }
        seq = string(in.size(), 'i') + string(in.size(), 'o');
        do {
            if (StackOp()) {
                for (int i = 0; i < seq.size(); ++i) {
                    cout << seq[i] << " \n"[i + 1 == seq.size()];
                }
            }
        } while (next_permutation(seq.begin(), seq.end()) && !stop);
        cout << ']' << endl;
    }
    
    return 0;
}