#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct Team {
    int id, t, p_count;
    bool in;
    vector<int> problem;
    Team () {
        in = false;
        t = 0;
        p_count = 0;
        problem.assign(10, 0);
    }
};

int N, id, p, t;
string line, verdict;
stringstream ss;

bool CompareTeam (const Team &a, const Team &b) {
    if (a.p_count != b.p_count)
        return a.p_count > b.p_count;
    if (a.t != b.t)
        return a.t < b.t;
    if (a.in != b.in)
        return a.in;
    return a.id < b.id;
}

int main (int argc, char const *argv[]) {
    
    ios_base::sync_with_stdio(false);

    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    #endif

    cin >> N;

    getline(cin, line);
    getline(cin, line);

    while (N--) {

        Team teams[101];
        for (int i = 0; i <= 100; ++i)
            teams[i].id = i;

        while (getline(cin, line)) {
            if (line == "") break;
            ss.clear();
            ss << line;
            ss >> id >> p >> t >> verdict;
            teams[id].in = true;
            if (verdict == "I" && teams[id].problem[p] != -1) {
                ++teams[id].problem[p];
            } else if (verdict == "C" && teams[id].problem[p] != -1) {
                teams[id].t += 20 * teams[id].problem[p] + t;
                teams[id].problem[p] = -1;
                ++teams[id].p_count;
            }
        }

        sort(teams, teams + 101, CompareTeam);

        for (int i = 0; i < 101; ++i) {
            if (teams[i].in)
                cout << teams[i].id << " " << teams[i].p_count << " " << teams[i].t << endl;
            else
                break;
        }

        if (N) cout << endl;
    }
    
    return 0;
}