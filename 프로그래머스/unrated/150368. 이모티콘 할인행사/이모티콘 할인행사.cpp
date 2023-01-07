#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<vector<int>> emoticon_sale;
vector<vector<int>> user_results;
vector<vector<int>> user;

float sale[4] = { 40, 30, 20, 10 };

int user_size;

bool compare(vector<int> a, vector<int> b) {
    if (a[0] >= b[0]) {
        if (a[1] >= b[1]) {
            return a > b;
        }
        else {
            return b < a;
        }
    }
    return b < a;
}
void dfs(int idx, int user_money[]) {
    if (idx == emoticon_sale.size()) {
        vector<int> results = { 0,0 };
        for (int i = 0; i < user.size(); i++) {
            if (user_money[i] >= user[i][1]) {
                results[0]++;
            }
            else {
                results[1] += user_money[i];
            }
        }
        user_results.push_back(results);
    }
    else {
        for (int i = 0; i < 4; i++) {
            int temp[100];
            copy_n(user_money, 100, temp);
            for(int j = 0 ; j < user.size() ; j++){
                if (sale[i] >= user[j][0]) {
                    temp[j] += emoticon_sale[idx][i];
                }
            }
            idx++;
            dfs(idx, temp);
            idx--;
        }
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer = {0,0};
    user = users;
    user_size = users.size();
    int user_money[100] = {0,};

    for (int i = 0; i < emoticons.size(); i++) {
        vector<int> temp;
        for (int j = 0; j < 4; j++) {
            temp.push_back(emoticons[i] * (100 - sale[j])/100);
            cout << emoticons[i] * (100 - sale[j]) / 100 << endl;
        }
        emoticon_sale.push_back(temp);
    }
    dfs(0, user_money);


    sort(user_results.begin(), user_results.end(), compare);

    answer[0] = user_results[0][0];
    answer[1] = user_results[0][1];

    return answer;
}