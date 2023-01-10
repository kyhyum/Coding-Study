#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
        int answer = 0;

        while(n > 1) {
            int coke = (n / a)* b;
            n = coke + n%a;
            answer += coke;
            if (n < a) {
                break;
            }

        }

        return answer;
}