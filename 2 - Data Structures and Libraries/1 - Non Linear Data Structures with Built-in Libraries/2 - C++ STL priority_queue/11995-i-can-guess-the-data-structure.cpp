#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <string>

using namespace std;

#define action first
#define number second

int n;
string result;
vector< pair< int, int > > operation;

bool isStack() {
    stack< int > s;
    for ( auto op : operation ) {
        if ( op.action == 1 ) {
            s.push( op.number );
        } else {
            if ( s.empty() ) {
                return false;
            } else if ( s.top() != op.number ) {
                return false;
            }
            s.pop();
        }
    }
    return true;
}

bool isQueue() {
    queue< int > q;
    for ( auto op : operation ) {
        if ( op.action == 1 ) {
            q.push( op.number );
        } else {
            if ( q.empty() ) {
                return false;
            } else if ( q.front() != op.number ) {
                return false;
            }
            q.pop();
        }
    }
    return true;
}

bool isPriorityQueue() {
    priority_queue< int > pq;
    for ( auto op : operation ) {
        if ( op.action == 1 ) {
            pq.push( op.number );
        } else {
            if ( pq.empty() ) {
                return false;
            } else if ( pq.top() != op.number ) {
                return false;
            }
            pq.pop();
        }
    }
    return true;
}

int main (int argc, char const *argv[]) {

    ios_base::sync_with_stdio(false);

    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    #endif

    while ( cin >> n ) {
        operation.resize( n );
        for ( int i = 0; i < n; ++i ) {
            cin >> operation[i].action >> operation[i].number;
        }

        result = "impossible";
        if ( isStack() ) {
            result = "stack";
        }
        if ( isQueue() ) {
            result = (result == "impossible") ? "queue" : "not sure";
        }
        if ( result != "not sure" && isPriorityQueue() ) {
            result = (result == "impossible") ? "priority queue" : "not sure";
        }
        cout << result << "\n";
    }

    return 0;
}