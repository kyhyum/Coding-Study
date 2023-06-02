#include <iostream>
using namespace std;

int combination(int n, int r) {
    int result = 1;
    for (int i = 1; i <= r; ++i) {
        result *= (n - i + 1);
        result /= i;
    }
    return result;
}

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; ++i) {
        int N, M;
        cin >> N >> M;

        int answer = combination(M, N);
        cout << answer << endl;
    }

    return 0;
}