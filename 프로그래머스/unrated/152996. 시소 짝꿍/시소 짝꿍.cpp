#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int upperBound(int findWeight, vector<int> weights, int left, int right) {
    while (left < right) {
        int mid = (left + right) / 2;

        if (findWeight < weights[mid]) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }
    return left;
}

int lowerBound(int findWeight, vector<int> weights, int left, int right) {
    while (left < right) {
        int mid = (left + right) / 2;

        if (findWeight <= weights[mid]) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }
    return left;
}

long long solution(vector<int> weights) {
    long long answer = 0;
    vector<pair<int, int>> rates = { {1,1},{3,2},{4,2},{4,3} };

    sort(weights.begin(), weights.end());
    
    for (int i = 0; i < rates.size(); i++) {
        for (int j = 0; j < weights.size(); j++) {
            int a = weights[j];

            if (a * rates[i].first % rates[i].second != 0) continue;
            int b = ((a * rates[i].first) / rates[i].second);

            int upper = upperBound(b, weights, j + 1, weights.size());
            int lower = lowerBound(b, weights, j + 1, upper);
            
            answer += (upper - lower);
        }
    }
    return answer;
}