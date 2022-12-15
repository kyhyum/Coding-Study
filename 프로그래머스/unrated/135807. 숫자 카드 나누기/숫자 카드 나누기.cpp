#include <string>
#include <vector>
#include <iostream>
using namespace std;
int gcd(int x, int y) {
 return x % y == 0 ? y : gcd(y, x % y); 
}
int x(vector<int> a){
    int x = a[0];
    for(int i = 1 ; i < a.size() ; i++){
         x = gcd(x,a[i]);
    }
    return x;
}
int y(int c, vector<int> array){
    for(int i = 0 ; i < array.size() ; i++){
       if(array[i] % c == 0){
            return 0;
        } 
    }
    return c;
}
int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    if(x(arrayA) > x(arrayB)){
       return y(x(arrayA),arrayB);
    }else if(x(arrayA) < x(arrayB)){
       return y(x(arrayB),arrayA);
    }else{
        return 0;
    }
}