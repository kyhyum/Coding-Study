#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;
bool solution(vector<string> phone_book) {
    set<string> tmp;
    for (auto& number : phone_book)
        tmp.insert(number);
    for (auto it1 = tmp.begin(); it1 != tmp.end(); ++it1)
        for (auto it2 = it1; it2 != tmp.end(); ++it2)
            if (it1 != it2)
                if (it2->find(*it1) == 0)
                    return false;
                else
                    break;
    return true;
}