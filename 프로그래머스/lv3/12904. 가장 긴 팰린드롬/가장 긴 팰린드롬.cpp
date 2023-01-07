#include <iostream>
#include <string>
using namespace std;

int answer = 1;
string a;
void dfs(int leftidx,int rightidx) {
    if (leftidx >= 0 && rightidx < a.size()) {
        if (a[leftidx] == a[rightidx]) {
            if (rightidx - leftidx + 1 > answer) {
                answer = rightidx - leftidx + 1;
            }
            dfs(leftidx-1, rightidx+1);
        }
    }
    else {
        return;
    }   
}
int solution(string s)
{
    a = s;
    for (int i = 0; i < s.size(); i++) {
        int leftidx = i - 1;
        int rightidx = i + 1;
        int num = 0;
        dfs(i, rightidx);
        dfs(leftidx, rightidx);
    }

    return answer;
}