#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;
int cal(int i) {
    int a = 0;
    for (int j = 0; j <= 4 - i; j++) {
        a += pow(5, j);
    }
    return a;
}
int solution(string word) {
    int answer = 0;
    char Vowels[5] = { 'A','E','I','O','U' };
        for (int i = 0; i < 5; i++) {
            if (i < word.size()) 
            {
                for(int j = 0; j < 5 ;j++){
                    if(word[i] == Vowels[j])  answer +=  cal(i) * j;
                }
            }

        }
    return answer + word.size();
}