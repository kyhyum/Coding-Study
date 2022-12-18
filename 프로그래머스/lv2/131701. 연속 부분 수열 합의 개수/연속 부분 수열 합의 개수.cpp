#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
int answer = 0;

    vector<vector<int>> a;
    vector<int> temp;
    set<int> set;

    a.push_back(elements);
    for (int j = 0; j < elements.size(); j++) {
        set.insert(elements[j]);
    }
    for (int i = 1; i < elements.size() - 1; i++) {
        temp.clear();
        for (int j = 0; j < elements.size(); j++) {
            int index = (i + j) % elements.size();
            temp.push_back(a[i - 1][j] + elements[index]);
            set.insert(a[i - 1][j] + elements[index]);
        }
        a.push_back(temp);
    }
    answer = set.size() + 1;
    return answer;
}