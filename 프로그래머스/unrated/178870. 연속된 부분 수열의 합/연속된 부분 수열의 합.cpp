#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer = {0,1000000};
    
    int left_idx = sequence.size() - 1;
    int right_idx = sequence.size() - 1; 
    int sum = sequence[sequence.size() - 1];
    while (left_idx >= 0 && right_idx >= 0) {
        if(sum == k){
            if(right_idx - left_idx <= answer[1] - answer[0]){
                answer[0] = left_idx;
                answer[1] = right_idx;
            }
            sum += sequence[--left_idx];
        }else if(sum < k){
            sum += sequence[--left_idx];
        }else if(sum > k){
            sum -= sequence[right_idx--];
        }
    }
    return answer;
}