#include <string>
#include <vector>

using namespace std;
int answer = -1;    
void dfs(bool visited[], int k, vector<vector<int>> dungeons, int count){
    for(int i = 0 ; i < dungeons.size() ; i++){
        if(dungeons[i][0] <= k && k - dungeons[i][1] >= 0 && visited[i] == false){
            visited[i] = true;
            count++;
            if(answer < count){
                answer = count;
            }
            dfs(visited, k - dungeons[i][1], dungeons, count);
            visited[i] = false;
            count--;
        }
    }
}
int solution(int k, vector<vector<int>> dungeons) {
    bool visited[8] = {false, };
    dfs(visited, k, dungeons, 0);
    return answer;
}