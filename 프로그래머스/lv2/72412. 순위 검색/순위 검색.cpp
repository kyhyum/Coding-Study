#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

map<string, vector<int>> m;

void infoIntoMap(string info) {

    string infoArr[4][2] = {
        {"-"},
        {"-"},
        {"-"},
        {"-"}
    };
    int infoScore = 0;

    //info 띄어쓰기 분리
    istringstream iss(info);
    iss >> infoArr[0][1] >> infoArr[1][1] >> infoArr[2][1] >> infoArr[3][1] >> infoScore;

    //info가 해당될 수 있는 모든 쿼리 만들기
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                for (int l = 0; l < 2; l++) {
                    //map의 key
                    string infoString = infoArr[0][i] + infoArr[1][j]
                        + infoArr[2][k] + infoArr[3][l];

                    //map에 저장
                    m[infoString].push_back(infoScore);
                }
            }
        }
    }
}

int findQueryFromMap(string query) {

    int output = 0;

    string queryArr[4];
    int queryScore = 0;

    //query 띄어쓰기 분리
    string trash = "";
    istringstream iss(query);
    iss >> queryArr[0] >> trash >> queryArr[1] >> trash
        >> queryArr[2] >> trash >> queryArr[3] >> queryScore;

    //map의 key만들기
    string queryString = "";
    for (int i = 0; i < 4; i++) {
        queryString += queryArr[i];
    }

    //findScores = map의 value
    vector<int> findScores = m[queryString];

    //해당 백터에서 queryScore의 lower_bound를 찾고 개수 계산
    output = findScores.end() - lower_bound(findScores.begin(), findScores.end(), queryScore);

    //개수 반환
    return output;
}

vector<int> solution(vector<string> info, vector<string> query) {

    vector<int> answer;

    //주어진 info를 map에 담기
    for (int i = 0; i < info.size(); i++) {
        infoIntoMap(info[i]);
    }

    //map에 저장되어 있는 점수들 정렬
    for (auto& instance : m) {
        sort(instance.second.begin(), instance.second.end());
    }

    //query를 분리해서 answer에 저장
    for (int i = 0; i < query.size(); i++) {
        answer.push_back(findQueryFromMap(query[i]));
    }

    //반환
    return answer;
}
