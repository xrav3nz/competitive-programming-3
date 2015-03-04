#include <iostream>
#include <string>
#include <map>
#include <vector>

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
            int x = find_set(i),
                y = find_set(j);
            set_size[x] = set_size[y] = set_size[x] + set_size[y];
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
        return set_size[find_set(i)];
    }
};

string a, b;
map<string, int> name_to_id;
int id, t, n, i, j;

int main (int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    #endif

    cin >> t;
    UnionFind uf;

    while (t--) {
        cin >> n;
        uf.resize(n * 2 + 1);
        name_to_id.clear();
        id = 1;
        while(n--) {
            cin >> a >> b;
            i = name_to_id[a];
            j = name_to_id[b];
            if (i == 0) {
                i = id++;
                name_to_id[a] = i;
            }
            if (j == 0) {
                j = id++;
                name_to_id[b] = j;
            }
            uf.union_set(i, j);
            cout << uf.get_set_size(i) << endl;
        }
    }

    return 0;
}