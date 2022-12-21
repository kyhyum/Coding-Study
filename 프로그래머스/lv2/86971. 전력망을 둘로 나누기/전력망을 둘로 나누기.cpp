#include <string>
#include <vector>
#include <math.h>
#include <iostream>
using namespace std;

vector<vector<int>> wire;

int dfs_count(int node, bool visited[]) {
    int num = 1;
    for (int i = 0; i < wire.size(); i++) {
        if (node == wire[i][0]) {
            int a = wire[i][1];
            if (visited[a] == false) {
                visited[a] = true;
                num += dfs_count(wire[i][1], visited);
                visited[a] = false;
            }
            else {
                continue;
            }
        }
        else if (node == wire[i][1]) {
            int a = wire[i][0];
            if (visited[a] == false) {
                visited[a] = true;
                num += dfs_count(wire[i][0], visited);
                visited[a] = false;
            }
            else {
                continue;
            }
        }
    }

    return num;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 100;
    bool visited[100] = {false,};
    wire = wires;
    for (int i = 0; i < wires.size(); i++) {
        int left_num = wires[i][0];
        int right_num = wires[i][1];
        visited[left_num] = true;
        visited[right_num] = true;
        int left_count = dfs_count(wires[i][0], visited);
        int right_count = dfs_count(wires[i][1], visited);
        visited[wires[i][0]] = false;
        visited[wires[i][1]] = false;

        cout << left_count << " " << right_count << endl;
         if(answer > abs(left_count - right_count)){
             answer = abs(left_count - right_count);
         }
    }

    return answer;
}