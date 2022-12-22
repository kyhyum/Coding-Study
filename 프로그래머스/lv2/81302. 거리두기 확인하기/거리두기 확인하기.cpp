#include <vector>
#include <string>
using namespace std;
int check(vector<string>& place) {
    vector<pair<int, int>> persons;
    for (int x = 0, y; x < place.size(); ++x)
        for (y = 0; y < place[x].size(); ++y)
            if (place[x].at(y) == 'P')               persons.push_back(make_pair(x, y));
    if (persons.size() <= 1)
        return 1;
    for (int x = 0, y; x < persons.size() - 1; ++x) {
        for (y = x + 1; y < persons.size(); ++y) {
            auto& t1 = persons[x];
            auto& t2 = persons[y];
            const auto& distance = abs(t1.first - t2.first) + abs(t1.second - t2.second);
            if (distance == 1)
                return 0;
            if (distance == 2) {
                if (t1.first == t2.first) {           // 좌/우 로 앉아 있는 경우
                    if (place[t1.first].at(min(t1.second, t2.second) + 1) != 'X')
                        return 0;
                }
                else if (t1.second == t2.second) {    // 상/하 로 앉아 있는 경우
                    if (place[min(t1.first, t2.first) + 1].at(t1.second) != 'X')
                        return 0;
                }
                else {                                // 대각으로 앉아 있는 경우
                    if ((t1.first < t2.first && t1.second < t2.second) || (t2.first < t1.first && t2.second < t1.second)) {
                        if (place[min(t1.first, t2.first)].at(max(t1.second, t2.second)) != 'X' ||
                            place[max(t1.first, t2.first)].at(min(t1.second, t2.second)) != 'X')
                            return 0;
                    }
                    else {
                        if (place[min(t1.first, t2.first)].at(min(t1.second, t2.second)) != 'X' ||
                            place[max(t1.first, t2.first)].at(max(t1.second, t2.second)) != 'X')
                            return 0;
                    }
                }
            }
        }
    }
    return 1;
}
vector<int> solution(vector<vector<string>> places) {
    vector<int> ans;
    for (int t = 0, x, y; t < places.size(); ++t)
        ans.push_back(check(places[t]));
    return ans;
}