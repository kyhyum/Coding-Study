#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<pair<int, int>>> blankpiece;
vector<vector<pair<int, int>>> puzzlepiece;

vector<vector<int>> game_boards;
vector<vector<int>> tables;

bool blank_visited[2500] = { false, };
bool puzzle_visited[2500] = { false, };

int XY;

vector<pair<int, int>> sortblocks(vector<pair<int, int>> boards) {

    int minx = 51;
    int miny = 51;
    for (int j = 0; j < boards.size(); j++) {
        if (boards[j].first < minx) {
            minx = boards[j].first;
        }
        if (boards[j].second < miny) {
            miny = boards[j].second;
        }
    }
    for (int j = 0; j < boards.size(); j++) {
        boards[j].first -= minx;
        boards[j].second -= miny;
    }
    sort(boards.begin(), boards.end());

    return boards;

}

vector<pair<int, int>> spin(vector<pair<int, int>> boards) {
        int max = 0;
        for (int i = 0; i < boards.size(); i++) {
            if (boards[i].first > max) {
                max = boards[i].first;
            }
            if (boards[i].second > max) {
                max = boards[i].second;
            }
        }
        vector<pair<int, int>> spin_piece;
        for (int i = 0; i < boards.size(); i++) {
            spin_piece.push_back({ max - boards[i].second , boards[i].first});
        }
        return sortblocks(spin_piece);
}



void bfs(int a, int y, int x) {
    vector<vector<int>> boards;
    queue<pair<int, int>> que;
    vector<pair<int, int>> temp;

    if (a == 0) {
        boards = game_boards;
    }
    else {
        boards = tables;
    }

    int dx[] = { -1,0,1,0 };
    int dy[] = { 0,1,0,-1 };

    que.push({ y,x });
    if (a == 0) {
        boards[y][x] = 1;
    }
    else {
        boards[y][x] = 0;
    }
    temp.push_back({ y,x });
    while (!que.empty()) {
        y = que.front().first;
        x = que.front().second;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= XY || ny >= XY)   continue;

            if (boards[ny][nx] == a) {
                que.push({ ny,nx });
                if (a == 1) {
                    boards[ny][nx] = 0;
                    temp.push_back({ ny,nx });
                }
                else {
                    boards[ny][nx] = 1;
                    temp.push_back({ ny,nx });
                }
            }
        }
        que.pop();
    }
    if (a == 0) {
        game_boards = boards;
    }
    else {
        tables = boards;
    }
    if (a == 0) {
        blankpiece.push_back(temp);
    }
    else {
        puzzlepiece.push_back(temp);
    }
}
void extraction(int a) {
    for (int i = 0; i < XY; i++) {
        for (int j = 0; j < XY; j++) {
            if (a == 0) {
                if (game_boards[i][j] == a) {
                    bfs(a, i, j);
                }
            }
            else {
                if (tables[i][j] == a) {
                    bfs(a, i, j);
                }
            }
        }
    }
}
int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;
    XY = game_board.size();
    game_boards = game_board;
    tables = table;
    extraction(1);
    extraction(0);
    for (int i = 0; i < puzzlepiece.size(); i++) {
        puzzlepiece[i] = sortblocks(puzzlepiece[i]);
    }
    for (int i = 0; i < blankpiece.size(); i++) {
        blankpiece[i] = sortblocks(blankpiece[i]);
    }

    for (int i = 0; i < blankpiece.size(); i++) {
        for (int j = 0; j < puzzlepiece.size(); j++) {
            if (blankpiece[i].size() == puzzlepiece[j].size() && blank_visited[i] == false && puzzle_visited[j] == false) {
                for (int r = 0; r < 4; r++) {
                    if (blankpiece[i] == puzzlepiece[j]) {
                        cout << i << " " << j << endl;
                        answer += puzzlepiece[j].size();
                        puzzle_visited[j] = true;
                        blank_visited[i] = true;
                        break;
                    }
                    puzzlepiece[j] = spin(puzzlepiece[j]);
                }
            }

        }
    }
    
    return answer;
}