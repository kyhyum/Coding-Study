#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
vector<string> courses;

map<string, int> n;


bool cmp(pair<string, int> a, pair<string, int> b) {
    return a.second > b.second;
}

void dfs(string x, string a, int index, int depth) {
    if (depth == a.length()) {
        n[a]++;
        return;
    }

    for (int i = index; i < x.length(); i++) { // order의 index부터
        a[depth] = x[i];
        dfs(x, a, i + 1, depth + 1); // index에 i+1를 넘김. ⭐즉, 다음 문자부터 DFS 시작 (중복 허용 X)⭐
    }
}
vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for (int i = 0; i < orders.size(); i++) {
        sort(orders[i].begin(), orders[i].end());
        for (int j = 0; j < course.size(); j++) {
            string a = "";
            a.resize(course[j]);
            dfs(orders[i], a, 0, 0);
        }
    } 
    vector<pair<string, int>> sorted;
    for (auto& order : n)
        if (order.second > 1)
            sorted.push_back(make_pair(order.first, order.second));
    sort(sorted.begin(), sorted.end(), cmp);

    for (int i = 0; i < course.size(); i++) {
        int max = 0;
        for (int j = 0; j < sorted.size(); j++) {
            if (sorted[j].first.length() != course[i])
                continue;
            else if (max == 0) {
                answer.push_back(sorted[j].first);
                max = sorted[j].second;
            }
            else if (max == sorted[j].second)
                answer.push_back(sorted[j].first);
            else
                break;
        }
    }

    sort(answer.begin(), answer.end());
    return answer;
}