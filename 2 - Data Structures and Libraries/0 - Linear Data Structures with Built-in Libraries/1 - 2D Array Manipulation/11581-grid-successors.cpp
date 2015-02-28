#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, counter, sum, line;
vector< vector<int> > grid(3, vector<int>(3, 0)), f(3), temp(3);

int adj[4][2] = {
    -1, 0,
    1, 0,
    0, 1,
    0, -1
};

bool IsLegal (int i, int j) {
    return i >= 0 && j >= 0 && i < 3 && j < 3;
}

vector< vector<int> > F (vector< vector<int> > &input) {
    temp = input;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j) {
            sum = 0;
            for (int k = 0; k < 4; ++k)
                if (IsLegal(i + adj[k][0], j + adj[k][1]))
                    sum += input[i + adj[k][0]][j + adj[k][1]];
            temp[i][j] = sum & 1;
        }
    return temp;
}

void Output (vector< vector<int> > &out) {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            cout << out[i][j] << ((j == 2) ? "\n" : "");
    cout << endl;
    return ;
}

int main (int argc, char const *argv[]) {
    
    ios_base::sync_with_stdio(false);

    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    #endif

    cin >> n;

    while (n--) {
        for (int i = 0; i < 3; ++i) {
            cin >> line;
            grid[i][0] = line / 100;
            grid[i][1] = line % 100 / 10;
            grid[i][2] = line % 10;
        }

        counter = 0;

        f = F(grid);

        while (grid != f) {
            ++counter;
            grid = f;
            f = F(f);
        }

        cout << (counter - 1) << endl;
    }
    
    return 0;
}