#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
long long GetBitCounts(long long a){
    long long count = 0; 
    while(1){
        if(a % 2 == 0) return count;
        count++;
        a /= 2;
    }
}
vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for(int i = 0 ; i < numbers.size() ; i++){
        long long num = numbers[i];
        if(num % 2 == 0){
            answer.push_back(++num);
        }else{
            int counts = GetBitCounts(num);
            cout << counts;
            answer.push_back(num + pow(2,counts) - pow(2,counts-1));
        }
        
    }
    return answer;
}