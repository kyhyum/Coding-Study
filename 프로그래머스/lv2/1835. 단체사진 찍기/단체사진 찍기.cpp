#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<string> data) {
    vector<char> friends = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
    vector<char> positions = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};

    vector<string> conditions;
    for (int i = 0; i < n; i++) {
        conditions.push_back(data[i]);
    }

    int answer = 0;
    do {
        bool satisfied = true;
        for (string condition : conditions) {
            char f1 = condition[0], f2 = condition[2], op = condition[3];
            int dist = condition[4] - '0';

            int idx1 = find(friends.begin(), friends.end(), f1) - friends.begin();
            int idx2 = find(friends.begin(), friends.end(), f2) - friends.begin();
            int pos1 = find(positions.begin(), positions.end(), friends[idx1]) - positions.begin();
            int pos2 = find(positions.begin(), positions.end(), friends[idx2]) - positions.begin();

            if (op == '=') {
                if (abs(pos1 - pos2) != dist + 1) {
                    satisfied = false;
                    break;
                }
            } else if (op == '<') {
                if (abs(pos1 - pos2) >= dist + 1) {
                    satisfied = false;
                    break;
                }
            } else if (op == '>') {
                if (abs(pos1 - pos2) <= dist + 1) {
                    satisfied = false;
                    break;
                }
            }
        }
        if (satisfied) {
            answer++;
        }
    } while (next_permutation(positions.begin(), positions.end()));

    return answer;
}