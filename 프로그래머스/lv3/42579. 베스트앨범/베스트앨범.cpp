#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(pair<string, int> a, pair<string, int> b) {
    if (a.second > b.second) {
        return true;
    }
    return false;
}
bool cmpi(pair<int, int> a, pair<int, int> b) {
    if (a.second > b.second) {
        return true;
    }
    return false;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> genresmap;
    map<int, int> playsmap;

    for (int i = 0; i < genres.size(); i++) {
        genresmap[genres[i]] += plays[i];
    }

    vector<pair<string, int>> genresvec(genresmap.begin(), genresmap.end());
    sort(genresvec.begin(), genresvec.end(),cmp);

    for (int j = 0; j < genresvec.size() ; j++) {
        for (int i = 0; i < genres.size(); i++) {
            if (genresvec[j].first == genres[i]) {
                playsmap.insert({ i,plays[i] });
            }
        }
        vector<pair<int, int>> playsvec(playsmap.begin(), playsmap.end());
        sort(playsvec.begin(), playsvec.end(), cmpi);

        int size = 0;
        if (playsvec.size() > 2) {
            size = 2;
        }
        else size = playsvec.size();

        for (int i = 0; i < size ; i++) {
            answer.push_back(playsvec[i].first);
        }
        playsmap.clear();
    }
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i];
    }
    return answer;
}