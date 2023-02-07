#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> maps;
    for (int i = 0; i < clothes.size(); i++) {
        maps[clothes[i][1]]++;
    }
   
    for (auto iter = maps.begin(); iter != maps.end(); ++iter) {
        answer *= (iter->second + 1);
    }
    answer -= 1;
    return answer;
}