#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int count = 0; 
    int diff = 0;
    char first = s[0];
    for(int i = 0 ; i < s.length() ; i++){
        if(count == diff){
            answer++;
            first = s[i];
        }
        if(first == s[i]){
            count++;
        }else{
            diff++;
        }
    }
    return answer;
}