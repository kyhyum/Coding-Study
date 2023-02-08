#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

string code[16] = {"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};
stack<string> stk;
vector<string> answers;

void bit(int n, int num) {
    while (num != 0) {
        stk.push(code[num % n]);
        num /= n;
    }
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    stk.push("0");
    for (int i = 0; i < t * m; i++ ) {
       bit(n, i);
       int stksize = stk.size();
       for (int j = 0; j < stksize; j++) {
           answers.push_back(stk.top());
           stk.pop();
       }
    }

    for (int i = p - 1; i < t * m; i += m) {
        answer += answers[i];
    }
    return answer;
}