#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> mineral;
int answers = 2501;
void dfs(int idx, int answer, vector<int>picks , vector<vector<int>> mineral) {
    bool have = false;
    for (int i = 0; i < 3; i++) {
        if (picks[i] > 0) {
            have = true;
        }
    }
    if (have == true && idx < mineral.size()) {
        if (picks[0] > 0) {
            picks[0]--;
            dfs(idx + 1, answer + mineral[idx][0], picks, mineral);
            picks[0]++;
        }
        if (picks[1] > 0) {
            picks[1]--;
            dfs(idx + 1, answer + mineral[idx][1], picks, mineral);
            picks[1]++;
        }
        if (picks[2] > 0) {
            picks[2]--;
            dfs(idx + 1, answer + mineral[idx][2], picks, mineral);
            picks[2]++;
        }
    }
    else {
        if (answer < answers)
            answers = answer;
    }
}
int solution(vector<int> picks, vector<string> minerals) {
    int i = 1;
    int dia = 0;
    int iron = 0;
    int stone = 0;
    while (i <= minerals.size()) {
        if (minerals[i-1] == "diamond") dia++;
        else if (minerals[i - 1] == "iron") iron++;
        else if(minerals[i - 1] == "stone") stone++;
        if (i % 5 == 0 && i > 0) {
            vector<int> a;
            a.push_back(dia + iron + stone);
            a.push_back(dia * 5 + iron + stone);
            a.push_back(dia * 25 + iron * 5 + stone);
            mineral.push_back(a);
            dia = 0;
            iron = 0;
            stone = 0;
        }
        else if (i == minerals.size()) {
            vector<int> a;
            a.push_back(dia + iron + stone);
            a.push_back(dia * 5 + iron + stone);
            a.push_back(dia * 25 + iron * 5 + stone);
            mineral.push_back(a);
            dia = 0;
            iron = 0;
            stone = 0;
        }
        i++;
    }

    if (picks[0] > 0) {
        picks[0]--;
        dfs(1, mineral[0][0], picks, mineral);
        picks[0]++;
    }
    if (picks[1] > 0) {
        picks[1]--;
        dfs(1, mineral[0][1], picks, mineral);
        picks[1]++;
    }
    if (picks[2] > 0) {
        picks[2]--;
        dfs(1, mineral[0][2], picks, mineral);
        picks[2]++;
    }
    return answers;
}