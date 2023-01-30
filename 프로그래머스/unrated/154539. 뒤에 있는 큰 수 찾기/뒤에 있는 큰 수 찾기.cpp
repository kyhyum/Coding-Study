#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    stack<int> stk;
    stack<int> stk_answer;

    
    for (int i = numbers.size() - 1 ; i >= 0; i--) {
        if (stk.empty()) {
            stk_answer.push(-1);
            stk.push(numbers[i]);
        }
        else {
            if (stk.top() > numbers[i]) {
                stk_answer.push(stk.top());
                stk.push(numbers[i]);
            }
            else if (stk.top() <= numbers[i]) {
                while (1) {
                    if (stk.empty() || stk.top() > numbers[i]) break;
                    stk.pop();
                }
                if (!stk.empty()) {
                    stk_answer.push(stk.top());
                }
                else {
                    stk_answer.push(-1);
                }
                stk.push(numbers[i]);
            }
        }
    }

    int a = stk_answer.size();
    for (int i = 0; i < a; i++) {
        answer.push_back(stk_answer.top());
        stk_answer.pop();
    }
    return answer;
}