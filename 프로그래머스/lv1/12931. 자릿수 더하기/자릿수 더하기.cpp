#include <iostream>

using namespace std;
int solution(int n)
{
    int answer = 0;
    int x = 10;
    while(n != 0){
        answer += (n % x);
        n /= x;
    }

    return answer;
}