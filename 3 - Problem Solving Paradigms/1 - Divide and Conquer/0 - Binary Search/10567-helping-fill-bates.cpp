#include <cstdio>
#include <vector>

using std::vector;

#define MAX_LENGTH 1000000 + 10
#define MAX_QUERY_LENGTH 101 + 10
#define MAX_STATES 52

char candidate_line[MAX_LENGTH], query_string[MAX_QUERY_LENGTH];
vector< vector<int> > new_sequence(MAX_STATES, vector<int>(0));
int num_queries, start, end, low, high, mid, state_id, answer;
bool valid;

int char_to_state_id(char &c) {
    return (c >= 'A' && c <= 'Z') ? (c - 'A') : (c - 'a' + 26);
}

void process_candidate() {
    for (int i = 0; candidate_line[i]; ++i) {
        state_id = char_to_state_id(candidate_line[i]);
        new_sequence[state_id].push_back(i);
    }
    return ;
}

int main (int argc, char const *argv[]) {
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    #endif

    scanf("%s", candidate_line);
    process_candidate();
    scanf("%d", &num_queries);
    while (num_queries--) {
        scanf("%s", query_string);
        start = end = -1;
        valid = true;
        for (int i = 0; query_string[i]; ++i) {
            char c = query_string[i];
            state_id = char_to_state_id(c);
            if (start == -1) {
                if (new_sequence[state_id].size()) {
                    end = start = new_sequence[state_id][0];
                } else {
                    valid = false;
                    break;
                }
            } else {
                low = 0, high = new_sequence[state_id].size() - 1;
                answer = -1;
                while (low <= high) {
                    mid = (high - low) / 2 + low;
                    if (new_sequence[state_id][mid] > end) {
                        answer = new_sequence[state_id][mid];
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                }
                if (answer == -1) {
                    valid = false;
                    break;
                } else {
                    end = answer;
                }

            }
        }
        if (valid) {
            printf("Matched %d %d\n", start, end);
        } else {
            printf("Not matched\n");
        }
    }

    return 0;
}