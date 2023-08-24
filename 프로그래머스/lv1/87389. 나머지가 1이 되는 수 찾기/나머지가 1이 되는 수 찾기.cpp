#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int i = 1;
    while(1){
        if(n % i == 1)
            return i;
        i++;
    }
}