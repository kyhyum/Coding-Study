#include <iostream>
#include <vector>
using namespace std;

int answer = 0;
int solution(int n, vector<int> stations, int w)
{
    vector<pair<int, int>> no_sta;
    int num = 1;
    for (int i = 0; i < stations.size(); i++) {
        if (num > stations[i] - w - 1 && num < stations[i] + w + 1) {
            num = stations[i] + w + 1;
            continue;
        } 

        no_sta.push_back({ num, stations[i] - w - 1 });
        num = stations[i] + w + 1;
    }
    if (num <= n) {
        no_sta.push_back({ num, n});
    }
    
    for (int i = 0; i < no_sta.size(); i++) {
        answer += ((no_sta[i].second - no_sta[i].first) / (w*2 + 1)) + 1;
    }


    return answer;
}