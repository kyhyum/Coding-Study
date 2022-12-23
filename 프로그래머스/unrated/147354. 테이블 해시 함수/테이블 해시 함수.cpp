#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int idx = 0;
bool cmp(vector<int> &a, vector<int> &b) 
{
    if (a[idx] == b[idx]) {
        return b[0] < a[0];
    }
    else {
        return a[idx] < b[idx];
    }
}
int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    idx = col-1;
    sort(data.begin(), data.end(), cmp);
    for (int i = row_begin ; i <= row_end; i++) {
        int a = 0;
        for (int j = 0; j < data[i-1].size() ; j++) {
            a += data[i-1][j] % i;
        } 
        answer = (i == row_begin) ? a : answer ^ a;
    }
    return answer;
}