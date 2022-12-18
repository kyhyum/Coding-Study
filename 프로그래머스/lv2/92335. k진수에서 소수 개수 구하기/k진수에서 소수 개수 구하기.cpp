#include <vector>
#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

using namespace std;

bool check(long num) {
    if (num < 2) return false;
    long a = (long)sqrt(num);
    for (long long i = 2; i <= a; i++) if (num % i == 0) return false;
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    vector<long> x;
    stack<int> stack;
    long long num = 0;

    while (1) {
        if (n % k == 0) {
            int size = stack.size();
            for (int i = 0; i < size; i++) {
                cout << num << endl;
                num = (num * 10) + stack.top();
                stack.pop();
            }
            if (num != 0) {
                x.push_back(num);
            }
            num = 0;
        }
        else { 
            stack.push(n % k);
        }
        if (n == 0) {
            break;
        }
        n /= k;
    }
    for (int i = 0; i < x.size(); i++) {
        if (check(x[i]) == true) {
            answer++;
        }
    }

    return answer;
}