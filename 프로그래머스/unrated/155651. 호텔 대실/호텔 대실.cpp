#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> book_time) {
    int answer = 0;

    vector<pair<int, int>> v1;
    vector<pair<int, int>> v2;

    for (int i = 0; i < book_time.size(); i++)
    {
        int x = stoi(book_time[i][0].substr(0, 2)) * 60 + stoi(book_time[i][0].substr(3, 2));
        int y = stoi(book_time[i][1].substr(0, 2)) * 60 + stoi(book_time[i][1].substr(3, 2)) + 10;
        v1.push_back({ x, y });
    }

    sort(v1.begin(), v1.end());

    for (int i = 0; i < v1.size(); i++)
    {
        if (v2.empty())
            v2.push_back(v1[i]);
        else
        {
            int idx = 0;
            int fastTime = 1500;
            for (int j = 0; j < v2.size(); j++)
            {
                if (v2[j].second < fastTime)
                {
                    idx = j;
                    fastTime = v2[j].second;
                }
            }
            if (v2[idx].second <= v1[i].first)
                v2[idx] = v1[i];
            else
                v2.push_back(v1[i]);

            int size = v2.size();
        }
    }

    return v2.size();
}