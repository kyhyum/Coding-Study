#include <string>
#include <vector>
#include <iostream>
using namespace std;

double width(double up, double down){
    return (up+down)/2;
}

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> nums;
    vector<double> widths;
    vector<double> answer;
    //콜라츠 수열 저장
    while(k != 1){
        nums.push_back(k);
        if(k % 2 == 0){
            k /= 2;
        }else{
            k = k*3 + 1;
        }
    }
    nums.push_back(1);
    
    //1로 나눠서 넓이 저장
    for(int i = 0 ; i < nums.size() - 1 ; i++){
        widths.push_back(width(nums[i],nums[i+1]));
    }
    
    //left 부터 widths.size() + right까지 넓이 덧셈
    for(int i = 0 ; i < ranges.size() ; i++){
        double x = 0;
        double left = ranges[i][0];
        double right = ranges[i][1];
        
        if(left > widths.size() + right){
            answer.push_back(-1);
            continue;
        }
        
        for(left ; left < widths.size() + right ; left++){
            x += widths[left];
        }
        
        answer.push_back(x);
    }
    return answer;
}