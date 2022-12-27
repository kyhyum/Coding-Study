#include <vector>
#include <algorithm>
using namespace std;
int arr[101][101];
vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    int index = 0;
    for(int ix = 1, iy; ix <= rows; ++ix)
        for(iy = 1; iy <= columns; ++iy)
            arr[ix][iy] = ++index;
    
    vector<int> tmp, ans;
    for(const auto& query : queries){
        tmp.clear();
        auto &x1 = query[0], &y1 = query[1], &x2 = query[2], &y2 = query[3];
        // 구간의 값들 가져오기
        for(int y = y1; y < y2; ++y)
            tmp.push_back(arr[x1][y]);
        for(int x = x1; x < x2; ++x)
            tmp.push_back(arr[x][y2]);
        for(int y = y2; y > y1; --y)
            tmp.push_back(arr[x2][y]);
        for(int x = x2; x > x1; --x)
            tmp.push_back(arr[x][y1]);
        ans.push_back(*min_element(tmp.begin(), tmp.end()));        // 최소값
        rotate(tmp.begin(), tmp.end() - 1 , tmp.end());             // 오른쪽으로 한칸 이동
        // 이동된 값들 적용시키기
        index = 0;
        for(int y = y1; y < y2; ++y)
            arr[x1][y] = tmp[index++];
        for(int x = x1; x < x2; ++x)
            arr[x][y2] = tmp[index++];
        for(int y = y2; y > y1; --y)
            arr[x2][y] = tmp[index++];
        for(int x = x2; x > x1; --x)
            arr[x][y1] = tmp[index++];
    }
    return ans;
}