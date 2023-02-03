#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<long long> factorial;
    vector<int> number;
    for (int i = 0; i < n; i++) {
        number.push_back(i + 1);
    }

    factorial.push_back(1);
    for (int i = 1; i < n; i++) {
        factorial.push_back(factorial[i - 1] * i);
    }

    long long a;
    int idx = factorial.size() - 1;
    k--;
    n--;
    while (number.size() != 1) {
        a = k / factorial[idx];
        k = k % factorial[idx];
        answer.push_back(number[a]);
        number.erase(number.begin() + a);
        factorial[idx] = factorial[idx] / n;
        n--;
    }
    answer.push_back(number[0]);

    return answer;
}