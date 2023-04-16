#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(vector<int> a, vector<int> b) {
    return a[0] < b[0];
}
int solution(vector<vector<int>> targets) {
    int answer = 0;
    sort(targets.begin(), targets.end(), cmp);
    for (int i = 0; i < targets.size(); i++) {
        int idx = i + 1;
        int left_bound = targets[i][0];
        int right_bound = targets[i][1];
        if (idx < targets.size()) {
            while (1) {
                if (idx < targets.size() && left_bound <= targets[idx][0] && right_bound > targets[idx][0]) {
                    left_bound = targets[idx][0];
                    if(targets[idx][1] < right_bound) right_bound = targets[idx][1];
                    idx++;
                }
                else {
                    i = idx - 1;
                    break;
                }
            }
        }
        answer++;
    }
    return answer;
}