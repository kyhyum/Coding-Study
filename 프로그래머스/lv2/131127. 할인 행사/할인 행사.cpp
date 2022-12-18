#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<string> wants;

bool check(map<string, int> map) {
    for (int i = 0; i < map.size(); i++) {
        if (map[wants[i]] > 0) {
            return false;
        }
    }
    return true;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    wants = want;
    map<string, int> maps;
    map<string, int> map;
    for (int i = 0; i < want.size(); i++) {
        map.insert({ want[i], number[i] });
    }
    maps = map;
    int a = discount.size() - 10;
    for (int i = 0; i < a + 1; i++) {
        for (int j = i; j < i + 10; j++) {
            if (map.find(discount[j]) != map.end()) {
                map[discount[j]]--;
            }
        }
        if (check(map) == true) {
            answer++;
        }
        
        map = maps;
    }
    return answer;
}