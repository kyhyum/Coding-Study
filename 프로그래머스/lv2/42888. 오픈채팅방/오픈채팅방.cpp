#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <iostream>
using namespace std;
vector<string> answer;

void enter(string a) {
    answer.push_back(a + "님이 들어왔습니다.");
}

void leave(string a) {
    answer.push_back(a + "님이 나갔습니다.");
}

vector<string> solution(vector<string> record) {
    map<string, string> maps;
    for (int i = 0; i < record.size(); i++) {
        istringstream iss(record[i]);
        string command, uid, nickname;
        iss >> command >> uid >> nickname;

        if (command == "Enter") {
            maps[uid] = nickname;
        }
        else if (command == "Change" && maps.find(uid) != maps.end()) {
            maps[uid] = nickname;
        }
    }
    for (int i = 0; i < record.size(); i++) {
        istringstream iss(record[i]);
        string command, uid, nickname;
        iss >> command >> uid >> nickname;
        if (command == "Enter") {
            enter(maps[uid]);
        }
        else if (command == "Leave") {
            leave(maps[uid]);
        }
    }
    return answer;
}