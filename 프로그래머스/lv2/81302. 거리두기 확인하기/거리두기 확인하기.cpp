#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<vector<string>> place;

int check(int i, int array[5][5]) {
        for (int j = 0; j < 5; j++) {
            for (int w = 0; w < 5; w++) {
                cout << array[j][w] << " ";
                if (array[j][w] <= -2) {
                    return 0;
                }
            }
            cout << endl;
        }
    return 1;
}
vector<int> solution(vector<vector<string>> places) {
    place = places;
    vector<int> answer;
    for (int i = 0; i < 5; i++) {
        int array[5][5] = { 0, };
        for (int j = 0; j < 5; j++) {
            for (int w = 0; w < 5; w++) {
                if (places[i][j][w] == 'X') {
                    array[j][w] += 4;
                }
                else if (places[i][j][w] == 'P') {
                    int dx[4] = { 0,1,0,-1 };
                    int dy[4] = { 1,0,-1,0 };
                    for (int k = 0; k < 4; k++) {
                        int nx = dx[k] + j;
                        int ny = dy[k] + w;
                        if (nx >= 0 && ny >= 0 && nx < 5 && ny < 5) {
                            if (places[i][nx][ny] == 'P') {
                                answer.push_back(0);
                                w = 5;
                                j = 5;
                                break;
                            }
                            array[nx][ny] += -1;
                        }
                    }
                }
            }
        }
        if (i != answer.size() - 1) {
            answer.push_back(check(i, array));
        }
        cout << endl;
    }
        return answer;
}