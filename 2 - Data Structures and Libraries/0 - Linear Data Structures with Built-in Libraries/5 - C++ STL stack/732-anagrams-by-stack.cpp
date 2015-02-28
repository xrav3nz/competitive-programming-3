#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

string in, out, blank("");
int in_size;
stack<char> s;

bool AreAnagram () {
    string _in = in;
    string _out = out;
    sort (_in.begin(), _in.end());
    sort (_out.begin(), _out.end());
    return (_in == _out);
}

void Generate(int is, int os, string &seq) {
    if (is > 0) {
        seq.push_back('i');
        s.push(in[in_size - is]);
        Generate (is - 1, os, seq);
        s.pop();
        seq.pop_back();
    }

    if (os > 0 && os > is && s.top() == out[in_size - os]) {
        s.pop();
        seq.push_back('o');
        Generate (is, os - 1, seq);
        seq.pop_back();
        s.push(out[in_size - os]);
    }

    if (os == 0 && is == 0) {
        for (int i = 0; i < in_size * 2; ++i) {
            cout << seq[i] << " \n"[i == in_size * 2 - 1];
        }
    }

    return ;
}

int main (int argc, char const *argv[]) {
    
    ios_base::sync_with_stdio(false);

    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    #endif

    while (cin >> in >> out) {
        if (in.size() != out.size() || !AreAnagram()) {
            cout << "[\n]\n";
        } else {
            in_size = in.size();
            cout << "[\n";
            Generate(in_size, in_size, blank);
            cout << "]\n";
        }
    }
    
    return 0;
}