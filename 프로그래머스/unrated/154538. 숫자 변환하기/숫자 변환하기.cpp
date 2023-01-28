#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int x, int y, int n) {
    queue<pair<int,int>> que;
    que.push({ y,0 });
    while (1) {
        if (que.front().first == x) return que.front().second;
        if (que.front().first - n >= x) que.push({ que.front().first - n, que.front().second + 1 });
        if (que.front().first / 2 >= x && que.front().first % 2 == 0) que.push({ que.front().first / 2, que.front().second + 1 });
        if (que.front().first / 3 >= x && que.front().first % 3 == 0) que.push({ que.front().first / 3, que.front().second + 1 });
        que.pop();

        if (que.empty()) return -1;
    }

}