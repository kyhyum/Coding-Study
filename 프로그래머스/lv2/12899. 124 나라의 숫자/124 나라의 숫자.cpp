#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

string solution(int n) {
    queue<char> que;
    string answer = "";
    while (n != 0){
        if(n % 3 == 2){
            answer = "2" + answer;
        }else if(n % 3 == 1){
            answer = "1" + answer;
        }else if(n % 3 == 0){
            answer = "4" + answer;
            n--;
        }
    n /= 3;
    }
    return answer;
}