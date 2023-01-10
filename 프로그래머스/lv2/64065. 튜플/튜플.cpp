#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
bool cmp(pair<string, int> a, pair<string, int> b) {
    if (a.second == b.second) {
        return stoi(a.first) > stoi(b.first);
    }
    return a.second > b.second;
}
vector<int> solution(string s) {
    vector<int> answer;
    map<string, int> map;
    string a = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '{' || s[i] == '}' || s[i] == ',') {
            if (!a.empty()) {
                map[a]++;
                a = "";
            }
        }
        else {
            a += s[i];
        }
    }
    vector<pair<string, int>> vec(map.begin(), map.end());
    sort(vec.begin(), vec.end(),cmp);
    for (int i = 0; i < vec.size(); i++) {
        answer.push_back(stoi(vec[i].first));
    }
    return answer;
}
