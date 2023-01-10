#include <string>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
#include <iostream>
using namespace std;
map<string,long long> nums;
void dfs(vector<string> expression, string order, int idx) {
    queue<string> que;
    string operators = "";
    operators += order[idx];
    if (idx == 3) {
        nums[order] = abs(stoll(expression[0]));
        return;
    }
    for (int i = 0; i < expression.size(); i++) {
        if (operators == expression[i]) {
            if (order[idx] == '*') {
                i++;
                que.back() = to_string(stoll(que.back()) * stoll(expression[i]));
            }
            else if (order[idx] == '+') {
                i++;
                que.back() = to_string(stoll(que.back()) + stoll(expression[i]));
            }
            else if (order[idx] == '-') {
                i++;
                que.back() = to_string(stoll(que.back()) - stoll(expression[i]));
            }
        }
        else {
            que.push(expression[i]);
        }
        
    }
    int queuesize = que.size();
    expression.clear();
    for (int i = 0; i < queuesize; i++) {
        expression.push_back(que.front());
        que.pop();
    }
    dfs(expression, order, ++idx);
}
long long solution(string expression) {
    long long answer = 0;
    vector<string> order = { "*+-", "*-+", "+*-", "+-*", "-*+", "-+*" };
    string num = "";
    string operators = "";
    vector<string> expressions;
    for (int i = 0; i < expression.size(); i++) {
        if (expression[i] >= 48 && expression[i] <= 57) {
            num += expression[i];
        }
        if(i == expression.size() - 1 || expression[i] < 48) {
            expressions.push_back(num);
            num = "";
            operators += expression[i];
            if (i != expression.size() - 1) {
                expressions.push_back(operators);
                operators = "";
            }
        }
    }

    for (int i = 0; i < 6; i++) {
        nums.insert({ order[i], 0});
        dfs(expressions, order[i], 0);
    }

    for (int i = 0; i < 6; i++) {
        if (nums[order[i]] > answer) answer = nums[order[i]];
    }
    return answer;
}