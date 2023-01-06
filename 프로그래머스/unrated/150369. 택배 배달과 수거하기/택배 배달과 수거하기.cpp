#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

void clear(stack<int> &stk) {
    while (1) {
        if (stk.empty()) break;

        if (stk.top() == 0) stk.pop();
        else break;
    }
}

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    stack<int> deliver;
    stack<int> pickup;

    long long size = 0;

    for (int i = 0; i < n; i++) {
        deliver.push(deliveries[i]);
        pickup.push(pickups[i]);
    }
    
    while (1) {
        if (deliver.empty() && pickup.empty()) {
            break;
        }
        else {
            clear(deliver);
            clear(pickup);
            size = max(deliver.size(), pickup.size());
            for (int i = 0; i < cap; i++) {
                if (!pickup.empty()) {
                    pickup.top()--;
                }
                if (!deliver.empty()) {
                    deliver.top()--;
                }
                clear(deliver);
                clear(pickup);
            }
            answer += (size * 2);
        }
    }
    return answer;
}