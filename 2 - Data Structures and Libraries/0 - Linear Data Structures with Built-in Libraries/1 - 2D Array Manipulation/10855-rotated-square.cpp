#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, n;
vector<string> large, small;
vector<int> counter(4);

void Rotate () {
    vector<string> after = small;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            after[j][n - 1 - i] = small[i][j];
    small = after;
    return ;
}

void Output (vector<string> &out) {
    for (int i = 0; i < out.size(); ++i) {
        for (int j = 0; j < out[i].size(); ++j)
            cout << out[i][j];
        cout << endl;
    }
    cout << endl;
    return ;
}

int NumOfAppearance () {
    int c = 0;
    bool match;
    for (int i = 0; i <= N - n; ++i)
        for (int j = 0; j <= N - n; ++j) {
            match = true;
            for (int si = 0; si < n && match; ++si)
                for (int sj = 0; sj < n && match; ++sj)
                    if (small[si][sj] != large[i + si][j + sj])
                        match = false;
            c += match;
        }
    return c;
}

int main (int argc, char const *argv[]) {
    
    ios_base::sync_with_stdio(false);

    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    #endif

    while (cin >> N >> n) {
        if (!N && !n)
            return 0;

        large.resize(N);
        small.resize(n);

        for (int i = 0; i < N; ++i)
            cin >> large[i];

        for (int i = 0; i < n; ++i)
            cin >> small[i];

        for (int i = 0; i < 4; ++i) {
            counter[i] = NumOfAppearance();
            Rotate();
        }

        for (int i = 0; i < 4; ++i)
            cout << counter[i] << " \n"[i == 3];
    }
    
    return 0;
}