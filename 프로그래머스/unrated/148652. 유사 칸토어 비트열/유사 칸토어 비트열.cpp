#include <string>

using namespace std;

int whatbit(int n, long long x) {
    if (n == 1) {
        return x % 5 != 2;
    }
    else {
        if (!whatbit(n - 1, x / 5)) {
            return 0;
        }
        else {
            return x % 5 != 2;
        }
    }
}
int solution(int n, long long l, long long r) {
    int answer = 0;
    for (long long i = l - 1; i < r; i++) {
        answer += whatbit(n, i);
    } 
    return answer;
}
