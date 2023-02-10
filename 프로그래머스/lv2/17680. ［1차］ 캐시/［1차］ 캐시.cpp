#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<pair<string, int>> cache;

    for (int i = 0; i < cities.size(); i++) {
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);

        bool isfind = false;
        for (int idx = 0; idx < cache.size(); idx++) {
            if (cache[idx].first == cities[i]) {
                isfind = true;
                break;
            }
        }

        if (isfind) {
            answer++;
            bool isfind = false;
            for (int idx = 0; idx < cache.size(); idx++) {
                if (cache[idx].first == cities[i]) {
                    isfind = true;
                    cache[idx].second = i;
                    break;
                }
            }
        }
        else {
            answer += 5;
            if (cacheSize != 0) {
                if (cache.size() < cacheSize) {
                    cache.push_back({ cities[i], i });
                }
                else {
                    int misssize = cities.size();
                    int missidx;
                    for (int idx = 0; idx < cache.size(); idx++) {
                        if (cache[idx].second < misssize) {
                            misssize = cache[idx].second;
                            missidx = idx;
                        }
                    }
                    cache.erase(cache.begin() + missidx);
                    cache.push_back({ cities[i],i });
                }
            }
        }
    }

    return answer;
}