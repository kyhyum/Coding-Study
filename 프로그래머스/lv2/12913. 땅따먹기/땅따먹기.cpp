#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> land)
{
    int answer = 0;
    int a = land.size()-1;
    for (int i = 1; i < land.size(); i++) {
        land[i][0] += max(max(land[i - 1][1], land[i - 1][2]), land[i - 1][3]);
        land[i][1] += max(max(land[i - 1][0], land[i - 1][2]), land[i - 1][3]);
        land[i][2] += max(max(land[i - 1][1], land[i - 1][0]), land[i - 1][3]);
        land[i][3] += max(max(land[i - 1][1], land[i - 1][2]), land[i - 1][0]);
    }
    answer = max(max(land[a][1], land[a][0]), max(land[a][2], land[a][3]));
    
    return answer;
}