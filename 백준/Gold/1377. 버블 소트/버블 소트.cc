#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> arr;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        arr.push_back({ num,i });
    }

    sort(arr.begin(), arr.end());

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (ans < arr[i].second - i) {
            ans = arr[i].second - i;
        }
    }

    cout << ans + 1;
}
