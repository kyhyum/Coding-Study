#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> maps;
    int idx = 1;
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        string a = "";
        a += ch;
        maps.insert({ a,idx });
        idx++;
    }
    for (int i = 0; i < msg.size(); i++) {
        string word = "";
        int b = i;
        word += msg[b];
        string dic;
        //맵에 키가 존재안할 때까지 반복
        while (1) {
            dic = word;
            b++;
            word += msg[b];
            if (b == msg.size() || maps.find(word) == maps.end()) {
                break;
            }
        }
        i = b - 1;

        maps[word] = idx;
        idx++;

        answer.push_back(maps[dic]);
    }

    return answer;
}