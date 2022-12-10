#include <string>
#include <vector>
#include <iostream>
using namespace std;

int minimum = 0;
vector<int> enemys;
void dfs(int num, int k, int idx, int count){
    int plusidx = idx + 1;
    int pluscount = count + 1;
    int minusk = k - 1;
    
    //무적권 쓸 수 있을 때
    if (k > 0){
        //사용
        dfs(num, minusk, plusidx, pluscount);
        //사용 X
        num -= enemys[idx];
        
        if(num < 0 || idx >= enemys.size() - 1){
            if(minimum < count){
                minimum = count;
            }
            return;
        }else{
            dfs(num,k,plusidx,pluscount);    
        }
    }else{  //무적권 쓸 수 없을 때
         num -= enemys[idx];
        
        if(num < 0 || idx >= enemys.size() - 1){
            if(minimum < count){
                minimum = count;
            }
            return;
        }else{
            dfs(num,k,plusidx,pluscount);    
        }
    }
    
}
int solution(int n, int k, vector<int> enemy) {
    enemys = enemy;
    dfs(n,k,0,0);
    return minimum;
}