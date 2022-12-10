#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int n, int k, vector<int> enemy) {
    priority_queue<int,vector<int>,greater<int>> que;
    cout << enemy.size();
    if(k >= enemy.size()){
        return enemy.size();
    }
    for(int i = 0 ; i < k ; i++){
        que.push(enemy[i]);
    }
    int i = k;
    for(i ; i < enemy.size() ; i++){
        if(que.top() < enemy[i]){
            n -= que.top();
            if(n<0){
                return i;
            }else{
                que.pop();
                que.push(enemy[i]);
            }
        }else{
            n -= enemy[i];
            if(n<0){
                return i;
            }
        }
    }
    return enemy.size();
}