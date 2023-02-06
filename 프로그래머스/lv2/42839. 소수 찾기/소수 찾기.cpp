#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
vector<int> number;
bool isprime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void dfs(bool visited[7],string numbers, string num) {
    number.push_back(stoi(num));
    for (int i = 0; i < numbers.size(); i++) {
        if (visited[i] == false) {
            visited[i] = true;
            dfs(visited, numbers, num + numbers[i]);
            visited[i] = false;
        }
    }
}

int solution(string numbers) {
    int answer = 0;
    bool visited[7] = { false, };
    for (int i = 0; i < numbers.size(); i++) {
        visited[i] = true;
        string a = "";
        a += numbers[i];
        dfs(visited, numbers, a);
        visited[i] = false;
    }
    sort(number.begin(), number.end());
    number.erase(unique(number.begin(), number.end()), number.end());
    for (int i = 0; i < number.size(); i++) {
        if (isprime(number[i])) answer++;
    }
    return answer;
}