#include <iostream>

using namespace std;
int arr[101][101];
int arrsize;
void dfs(int answer[], int idx) {
    answer[idx] = 1;
    for (int j = 0; j < arrsize; j++) {
        if (arr[idx][j] == 1 && answer[j] != 1) {
            dfs(answer, j);
        }
    }
}
int main() {
    cin >> arrsize;
    for (int i = 0; i < arrsize; i++) {
        for (int j = 0; j < arrsize; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < arrsize; i++) {
        int answer[101] = { 0, };
        for (int j = 0; j < arrsize; j++) {
            if (arr[i][j] == 1) {
                dfs(answer, j);
            }
        }
        for (int j = 0; j < arrsize; j++) {
            cout << answer[j] << " ";
        }
        cout << endl;
    }
    return 0;
}