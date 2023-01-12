#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

int solution(string s) {
    int answer = s.size();
    if(s.size() == 1){
        return 1;
    }
    int diff = 1;
    int idx = 0;
    stack<string> stk;
    stack<string> counts;
    while (1) {
        int count = 1;
        for (int i = 0; i < s.size(); i += diff) {
            if (stk.empty()) {
                stk.push(s.substr(i, diff));
            }
            else {
                if (stk.top() == s.substr(i, diff)) {
                    count++;
                }
                else {
                    stk.push(s.substr(i, diff));
                    if (count != 1) {
                        counts.push(to_string(count));
                        count = 1;
                    }
                    
                }
            }
            if (i == s.size() - diff) {
                if (count != 1) {
                    counts.push(to_string(count));
                }
            }
        }
        int temp = 0;
        
        int stksize = stk.size();
        for (int i = 0; i < stksize; i++) {
            temp += stk.top().size();
            stk.pop();
        }

        int countssize = counts.size();
        for (int i = 0; i < countssize; i++) {
            temp += counts.top().size();
            counts.pop();
        }
        if (temp <= answer) {
            answer = temp;
        }
        if (diff == s.size()/2) {
            break;
        }
        diff++;
    }
    return answer;
}