#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    stack<int> assist;
    assist.push(0);
    int top = 0;
    for (int i = 0; i < order.size(); i++) {

        if (top < order[i]) {
            for (int j = top + 1; j <= order[i]; j++) {
                assist.push(j);
            }
        }

        if (assist.top() == order[i]) {
            answer++;
            top =  (top > assist.top()) ? top : assist.top();
            assist.pop();
        }
        else {
            break;
        }
        
    }
    return answer;
}
