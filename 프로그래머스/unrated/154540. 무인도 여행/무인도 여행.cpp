#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
bool visited[100][100] = { false, };
vector<string> map;
int bfs(int x, int y) {
    queue<pair<int,int>> que;
    int sum = 0;
    int ax[4] = { 0,1,0,-1 };
    int ay[4] = { 1,0,-1,0 };
    
    que.push({ y, x });
    if (map[que.front().first][que.front().second] == 'X' || visited[que.front().first][que.front().second] == true) return 0;

    while (!que.empty()) {
        if (visited[que.front().first][que.front().second] == false) {
            visited[que.front().first][que.front().second] = true;

            for (int i = 0; i < 4; i++) {
                if (que.front().first + ay[i] >= 0 && que.front().first + ay[i] < map.size() && que.front().second + ax[i] >= 0 && que.front().second + ax[i] < map[0].size()) {
                    if (map[que.front().first + ay[i]][que.front().second + ax[i]] == 'X' || visited[que.front().first + ay[i]][que.front().second + ax[i]] == true) continue;
                    que.push({ que.front().first + ay[i], que.front().second + ax[i] });
                }
            }

            sum += map[que.front().first][que.front().second] - 48;
            que.pop();
        }
        else {
            que.pop();
        }
    }
    return sum;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    map = maps;
    for (int i = 0; i < maps.size(); i++) {
        for (int j = 0; j < maps[i].size(); j++) {
            int x = bfs(j, i);
            if (x != 0) answer.push_back(x);
        }
    }
    sort(answer.begin(), answer.end());
    if (answer.empty()) answer.push_back(-1);
    
    return answer;
}