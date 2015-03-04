#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class UnionFind {
private:
    vector<int> p, rank, set_size;
    int num_sets;

public:
    void resize (int N) {
        rank.assign(N, 0);
        p.assign(N, 0);
        set_size.assign(N, 1);
        num_sets = N;
        for (int i = 0; i < N; ++i) {
            p[i] = i;
        }
    }
    int find_set(int i) {
        return (p[i] == i) ? i : (p[i] = find_set(p[i]));
    }
    bool is_same_set(int i, int j) {
        return find_set(i) == find_set(j);
    }
    void union_set(int i, int j) {
        if (!is_same_set(i, j)) {
            --num_sets;
            set_size[i] = set_size[j] = set_size[i] + set_size[j];
            int x = find_set(i),
                y = find_set(j);
            if (rank[x] > rank[y]) {
                p[y] = x;
            } else {
                p[x] = y;
                if (rank[x] == rank[y])
                    ++rank[y];
            }
        }
    }
    int get_num_sets() {
        return num_sets;
    }
    int get_set_size(int i) {
        return set_size[i];
    }
};

int t, n, a, b, success, failure;
char type[2];
string line;
stringstream ss;

int main (int argc, char const *argv[]) {

    ios_base::sync_with_stdio(false);

    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    #endif

    cin >> t;
    UnionFind uf;

    while (t--) {
        success = failure = 0;

        cin >> n;
        getline(cin, line);
        uf.resize(n + 1);

        while (getline(cin, line) && line != "") {
            ss.clear();
            ss << line;
            ss >> type >> a >> b;
            if (type[0] == 'c') {
                uf.union_set(a, b);
            } else {
                if  (uf.is_same_set(a, b))
                    ++success;
                else
                    ++failure;
            }
        }

        cout << success << "," << failure << endl;

        if (t) cout << endl;
    }

    return 0;
}