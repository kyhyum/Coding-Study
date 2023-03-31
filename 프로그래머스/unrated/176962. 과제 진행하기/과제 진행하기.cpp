#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int time_to_int(string time) {
    return stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));
}

bool cmp(vector<string> a, vector<string> b) {
    if (time_to_int(a[1]) < time_to_int(b[1])) {
        return true;
    }
    else {
        return false;
    }
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    sort(plans.begin(),plans.end(),cmp);

    stack < pair<string, int>> pause_stack;

    for (int i = 1; i < plans.size(); i++) {
        //시간내에 못 끝낼때
        if (time_to_int(plans[i][1]) - time_to_int(plans[i - 1][1]) < stoi(plans[i-1][2])) {
            pause_stack.push({plans[i - 1][0], stoi(plans[i - 1][2]) - (time_to_int(plans[i][1]) - time_to_int(plans[i - 1][1]))});
        }
        else { // 시간내에 끝낼때
            answer.push_back(plans[i-1][0]);
            if (!pause_stack.empty()) {

                //남은 시간
                int remain_time = time_to_int(plans[i][1]) - time_to_int(plans[i - 1][1]) - stoi(plans[i - 1][2]);

                while (1) {
                    //과제의 남은 시간이 사잇 시간보다 적을 경우 
                    if (pause_stack.top().second <= remain_time) {
                        answer.push_back(pause_stack.top().first);
                        remain_time -= pause_stack.top().second;
                        pause_stack.pop();
                    }
                    else {
                        pause_stack.top().second -= remain_time;
                        break;
                    }

                    if (pause_stack.empty()) {
                        break;
                    }
                }

            }
        }
        if (i == plans.size() - 1) {
            answer.push_back(plans[i][0]);
        }
    }

    int stack_size = pause_stack.size();
    
    for (int i = 0; i < stack_size; i++) {
        answer.push_back(pause_stack.top().first);
        pause_stack.pop();
    }


    return answer;
}