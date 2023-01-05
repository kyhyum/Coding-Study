#include <string>
#include <vector>
using namespace std;
vector<vector<int>> arrs;
vector<int> answer = { 0,0 };
void check(int x, int y, int ax, int ay) {
    int zeronum = 0;
    int onenum = 0;
    for (int i = y; i < ay; i++) {
        for (int j = x; j < ax; j++) {
            if (arrs[i][j] == 0) {
                zeronum++;
            }
            else {
                onenum++;
            }
        }
    }
    if (onenum == 0) {
        answer[0]++;
        return;
    }
    else if (zeronum == 0) {
        answer[1]++;
        return;
    }

    check(x, y, (x + ax) / 2, (y + ay) / 2);

    check((x + ax) / 2, y, ax, (y + ay) / 2);

    check(x, (y + ay) / 2, (x + ax) / 2, ay);

    check((x + ax) / 2, (y + ay) / 2, ax, ay);

}
vector<int> solution(vector<vector<int>> arr) {
    arrs = arr;
    int arrsize = arr.size();
    check(0, 0, arrsize, arrsize);
    return answer;
}