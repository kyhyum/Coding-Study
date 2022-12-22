#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool opened[100] = {false, };
vector<int> Cards;
vector<vector<int>> box(2);
void select(int card, int box_num){
    if(!opened[card - 1]){
        box[box_num].push_back(card-1);
        opened[card-1] = true;
        select(Cards[card-1] , box_num);
        if(box_num == 1){
            opened[card-1] = false;
        }
    }
}
int solution(vector<int> cards) {
    int answer = 0;
    Cards = cards;
    for(int i = 0 ; i < cards.size() ; i++){
        opened[i] = true;
        box[0].push_back(i);
        select(cards[i],0);
        for(int j = 0 ; j < cards.size() ; j++){
            if(!opened[j]){
                opened[j] = true;
                box[1].push_back(j);
                select(cards[j],1);
                answer = max(answer, (int)(box[0].size() * box[1].size()));
                opened[j] = false;
                box[1].clear();
            }
        }
        box[0].clear();
        for(int i = 0 ; i < cards.size() ; i++){
            opened[i] = false;
        }
    }
    return answer;
}