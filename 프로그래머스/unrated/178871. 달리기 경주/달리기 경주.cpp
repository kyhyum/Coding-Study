#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    map<string, int> maps;
    map<int, string> spam;
    
    for(int i = 0 ; i < players.size() ; i++){
        maps.insert({players[i], i + 1});
        spam.insert({i + 1, players[i]});
    }
    
    for(auto calling : callings){
        //선수 등수 뽑기
        int rank = maps[calling];
        //앞에 선수 이름 뽑기
        string front_name = spam[rank - 1];
        //앞에 선수 한칸 뒤로
        maps[front_name]++;
        //선수 한칸 뒤로
        maps[calling]--;
        //spam 바꾸기
        string temp = spam[rank - 1];
        spam[rank - 1] = spam[rank];
        spam[rank] = temp;
    }
    
    for(int i = 0 ; i < players.size() ; i++){
        answer.push_back(spam[i+1]);
    }
    
    return answer;
}