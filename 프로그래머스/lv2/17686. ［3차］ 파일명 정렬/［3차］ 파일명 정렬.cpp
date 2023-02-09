#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//구조 : 파일 이름(index, head, number)
struct fileName {
    int index;
    string head;
    int number;
};

vector<fileName> v;

//fileName 구조체 정렬 기준
bool compare(const fileName& f1, const fileName& f2) {
    if (f1.head == f2.head) {
        if (f1.number == f2.number) {
            return f1.index < f2.index;
        }
        else {
            return f1.number < f2.number;
        }
    }
    else {
        return f1.head < f2.head;
    }
}

//해당 문자가 숫자인지 판단하는 함수
bool isNumber(char c) {
    if (c >= '0' && c <= '9') {
        return true;
    }
    return false;
}

vector<string> solution(vector<string> files) {

    vector<string> answer;

    //모든 파일 탐색
    for (int i = 0; i < files.size(); i++) {

        //1. 소문자 변환
        string fileString = "";
        for (int j = 0; j < files[i].length(); j++) {
            fileString += tolower(files[i][j]);
        }

        //HEAD, NUMBER 초기화
        string HEAD = "";
        string NUMBER = "";
        int pointer = 0;

        //2-1. HEAD 분할
        while (pointer < fileString.length()) {

            //숫자가 나오면 반복문 종료
            if (isNumber(fileString[pointer])) {
                break;
            }

            HEAD += fileString[pointer];
            ++pointer;
        }

        //2-2. NUMBER 분할
        while (pointer < fileString.length()) {

            //숫자가 아닌것이 나오면 반복문 종료
            if (!isNumber(fileString[pointer])) {
                break;
            }

            NUMBER += fileString[pointer];
            ++pointer;
        }

        //구조체 생성
        fileName f;
        f.index = i;
        f.head = HEAD;
        f.number = stoi(NUMBER);

        //3. 벡터에 구조체 저장
        v.push_back(f);
    }

    sort(v.begin(), v.end(), compare);

    for (int i = 0; i < v.size(); i++) {
        answer.push_back(files[v[i].index]);
    }

    return answer;
}