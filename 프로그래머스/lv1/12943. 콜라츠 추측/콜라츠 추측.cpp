#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    long long n = num;
    for(int i = 0 ; i < 500 ; i++){
        if(n == 1){
            return i;
        }
        else{
            if(n % 2 == 0)
                n /= 2;
            else{
                n *= 3;
                n += 1;
            }
        }
    }
    return -1;
}