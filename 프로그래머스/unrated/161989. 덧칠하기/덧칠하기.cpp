#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    vector<bool> sections(n);
    for (int i = 0; i < section.size(); i++) {
        sections[section[i] - 1] = true;
    }

    for (int i = 0; i < n; i++) {
        if (sections[i] == true) {
            for (int j = i; j < i + m; j++) {
                if (j == n) {
                    break;
                }
                else {
                    sections[j] = false;
                }
            }
            i = (i + m  < n) ? i + m - 1 : n;
            answer++;
        }
    }

    return answer;
}