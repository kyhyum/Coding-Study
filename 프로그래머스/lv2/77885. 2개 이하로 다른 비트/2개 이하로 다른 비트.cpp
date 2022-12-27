#include <vector>
using namespace std;
vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for(int i = 0 ; i < numbers.size() ; i++){
        long long bit = 1;
        while ((numbers[i] & bit) > 0) bit <<= 1;
        answer.push_back(numbers[i] + bit - (bit >> 1));
    }
    return answer;
}