#include <iostream>
#include <vector>

using namespace std;

#define column first
#define number second

vector< vector< pair<int, int> > > matrix;
vector< int > col(1000);
int n, m, col_count, a;

int main (int argc, char const *argv[]) {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    #endif

    while(cin >> n >> m) {
        matrix.clear();
        matrix.resize(m + 1);

        for (int row = 1; row <= n; ++row) {
            cin >> col_count;
            if (col_count == 0) continue;
            for (int i = 0; i < col_count; ++i) {
                cin >> col[i];
            }
            for (int i = 0; i < col_count; ++i) {
                cin >> a;
                matrix[ col[i] ].push_back( make_pair(row, a) );
            }
        }

        cout << m << " " << n << "\n";
        for (int row = 1, size = 0; row <= m; ++row) {
            size = matrix[row].size();
            if (size == 0) {
                cout << "0\n\n";
                continue;
            }
            cout << size << " ";
            for (int i = 0; i < size; ++i) {
                cout << matrix[row][i].column << " \n"[i == size - 1];
            }
            for (int i = 0; i < size; ++i) {
                cout << matrix[row][i].number << " \n"[i == size - 1];
            }

        }
    }



    return 0;
}