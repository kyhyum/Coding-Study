#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> star;

void generateStar(int x, int y, int size) {
    if (size == 1) {
        star[x][y] = '*';
        return;
    }
    
    int newSize = size / 3;
    
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i == 1 && j == 1) {
                continue; // Skip the center
            }
            generateStar(x + i * newSize, y + j * newSize, newSize);
        }
    }
}

int main() {
    int N;
    cin >> N;
    
    star.assign(N, vector<char>(N, ' '));

    generateStar(0, 0, N);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << star[i][j];
        }
        cout << '\n';
    }

    return 0;
}