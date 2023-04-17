#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    vector<int> v;
    int sizes;
    cin >> sizes;
    for (int i = 0; i < sizes; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    int min_cnt = 4;
    for (int i = 0; i < v.size(); i++) {
        int num = v[i];
        int cnt = 1;
        int answer = 4;
        int idx = i + 1;
        if (idx != v.size()) {
            while (cnt < 5) {
                if (num + cnt == v[idx]) {
                    answer--;
                    if (idx == v.size() - 1) {
                        break;
                    }
                    idx++;
                }
                cnt++;
            }
            min_cnt = min(answer, min_cnt);
        }
    }
    cout << min_cnt;
}