#include <string>
#include <vector>
#include <cmath>

using namespace std;

int getMaxDivisorExceptMe(int x){
    if(x == 1) return 0;
    
    vector<int> v;
    for(int i = 2; i <= sqrt(x) ; i++){
        if(x % i == 0){
            v.push_back(i);
            if(x/i <= 10000000){
                return x/i;
            }
        }
    }
    
    if(!v.empty()){
        return v[v.size() - 1];
    }
    
    return 1;
}
vector<int> solution(long long begin, long long end) {
    vector<int> answer;
    for(int i = begin ; i <= end ; i++){
        answer.push_back(getMaxDivisorExceptMe(i));
    }
    return answer;
}