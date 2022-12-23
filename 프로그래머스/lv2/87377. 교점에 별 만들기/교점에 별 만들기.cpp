#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <climits>

using namespace std;

vector<int> max_min(vector<pair<int, int>> point) {
    int x_maxValue = INT_MIN;
    int y_maxValue = INT_MIN;
    int x_minValue = INT_MAX;
    int y_minValue = INT_MAX;
    for (int i = 0; i < point.size(); i++) {
        if (point[i].first < x_minValue) {
            x_minValue = point[i].first;
        }
        if (point[i].first > x_maxValue) {
            x_maxValue = point[i].first;
        }
        if (point[i].second < y_minValue) {
            y_minValue = point[i].second;
        }
        if (point[i].second > y_maxValue) {
            y_maxValue = point[i].second;
        }
    }
    vector<int> x;
    x.push_back(x_maxValue - x_minValue);
    x.push_back(y_maxValue - y_minValue);
    return x;
}
vector<pair<int, int>> point_set(vector<pair<int, int>> point) {
    int x_maxValue = INT_MIN;
    int y_maxValue = INT_MIN;
    int x_minValue = INT_MAX;
    int y_minValue = INT_MAX;
    for (int i = 0; i < point.size(); i++) {
        if (point[i].first > x_maxValue) {
            x_maxValue = point[i].first;
        }
        if (point[i].second > y_maxValue) {
            y_maxValue = point[i].second;
        }
    }
    for (int i = 0; i < point.size(); i++) {
        point[i].first = y_maxValue - point[i].first;
    }
    for (int i = 0; i < point.size(); i++) {
        if (point[i].first < x_minValue) {
            x_minValue = point[i].first;
        }
        if (point[i].second < y_minValue) {
            y_minValue = point[i].second;
        }
    }
    for (int i = 0; i < point.size(); i++) {
        point[i].second -= y_minValue;
        point[i].first -= x_minValue;
    }
    

    return point;
}
vector<string> solution(vector<vector<int>> line) {
    vector<pair<int, int>> point;
    for (int i = 0; i < line.size()-1; i++) {
        for (int j = i + 1; j < line.size(); j++) {
            long long adbc = (long long)line[i][0] * line[j][1] - (long long)line[i][1] * line[j][0];
            if (adbc == 0)  continue;      //평행 또는 일치. 단, 무수히 많은 교점->일치가 주어지지 않는다고 했으니 평행만 있다 
            long long bfed = (long long)line[i][1] * line[j][2] - (long long)line[i][2] * line[j][1];
            long long ecaf = (long long)line[i][2] * line[j][0] - (long long)line[i][0] * line[j][2];
            if ((bfed % adbc != 0) || (ecaf % adbc != 0)) continue;    //정수가 아닌 경우
            bfed /= adbc;     //x
            ecaf /= adbc;     //y
            point.push_back({ ecaf, bfed });
        }
    }
    vector<int> a = max_min(point);
    
    vector<string> answer;
    string c = "";
    for (int i = 0; i <= a[1] ; i++) {
        c = c + '.';
    }
    for (int i = 0; i <= a[0]; i++) {
        answer.push_back(c);
    }
    point = point_set(point);
    for (int i = 0; i < point.size(); i++) {
        cout << point[i].first << " " << point[i].second << endl;
        answer[point[i].first][point[i].second] = '*';
    }
    return answer;
}