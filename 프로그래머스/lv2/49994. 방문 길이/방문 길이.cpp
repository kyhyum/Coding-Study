#include <string>
#include <iostream>
#include <set>
using namespace std;

int solution(string dirs) {
    int answer = 0;
    int x = 5, y = 5;
    bool visited[10][10][10][10] = { false, };
    set<string> set;
    for (int i = 0; i < dirs.size(); i++) {
        if (dirs[i] == 'L') {
            if (x == 0) continue;
            string a = to_string(x) + to_string(y) + to_string(x - 1) + to_string(y);
            set.insert(a);
            a = to_string(x - 1) + to_string(y) + to_string(x) + to_string(y);
            set.insert(a);
            --x;
        }
        else if (dirs[i] == 'R') {
            if (x == 10) continue;
            string a = to_string(x) + to_string(y) + to_string(x + 1) + to_string(y);
            set.insert(a);
            a = to_string(x + 1) + to_string(y) + to_string(x) + to_string(y);
            set.insert(a);
            ++x;
        }
        else if (dirs[i] == 'U') {
            if (y == 10) continue;
            string a = to_string(x) + to_string(y) + to_string(x) + to_string(y + 1);
            set.insert(a);
            a = to_string(x) + to_string(y + 1) + to_string(x) + to_string(y);
            set.insert(a);
            ++y;
        }
        else if (dirs[i] == 'D') {
            if (y == 0) continue;
            string a = to_string(x) + to_string(y) + to_string(x) + to_string(y - 1);
            set.insert(a);
            a = to_string(x) + to_string(y - 1) + to_string(x) + to_string(y);
            set.insert(a);
            --y;
        }
    }
    answer = set.size() / 2;
    return answer;
}