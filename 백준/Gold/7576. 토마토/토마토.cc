#include <iostream>
#include <queue>
using namespace std;

struct Point {
    int x, y, days;
};

bool isValid(int x, int y, int rows, int cols) {
    return x >= 0 && x < rows && y >= 0 && y < cols;
}

int main() {
    int cols, rows;
    cin >> cols >> rows;
    
    int grid[1000][1000];
    queue<Point> tomatoQueue;
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 1) {
                tomatoQueue.push({i, j, 0});
            }
        }
    }
    
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    
    int maxDays = 0;
    
    while (!tomatoQueue.empty()) {
        Point current = tomatoQueue.front();
        tomatoQueue.pop();
        maxDays = current.days;
        
        for (int i = 0; i < 4; ++i) {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];
            
            if (isValid(nx, ny, rows, cols) && grid[nx][ny] == 0) {
                grid[nx][ny] = 1;
                tomatoQueue.push({nx, ny, current.days + 1});
            }
        }
    }
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == 0) {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    
    cout << maxDays << endl;
    
    return 0;
}