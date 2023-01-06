#include <algorithm>
#include <cmath>
using namespace std;
int gcd(int x, int y) {
 return x % y == 0 ? y : gcd(y, x % y); 
}
long long solution(int w,int h) {
    long long answer = 1;
    return(long long) w * h - (w + h - gcd(w,h));
}