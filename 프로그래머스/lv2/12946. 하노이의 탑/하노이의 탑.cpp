#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> answer;

void hanoi(int n, int from, int by, int to) {
    vector<int> ans;
    if (n == 1) {
        ans.push_back(from);
        ans.push_back(to);
        answer.push_back(ans);
    }
    else {
        hanoi(n - 1, from, to, by);
        ans.push_back(from);
        ans.push_back(to);
        answer.push_back(ans);
        hanoi(n - 1, by, from, to);
    }
}

vector<vector<int>> solution(int n) {
    hanoi(n, 1, 2, 3);
    return answer;
}