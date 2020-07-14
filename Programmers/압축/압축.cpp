/*
프로그래머스: 압축
문제 유형 : 구현

map을 사용해서 각 문자 저장.
*/
#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> dict;
    for (int i = 0; i < 26; i++) {
        string str = "";
        str += (char)(i + 'A');
        dict[str] = i + 1;
    }
    for (int i = 0; i < msg.size(); i++) {
        string str;
        for (int j = msg.size() - i; j >= 1; j--) {
            str = msg.substr(i, j);
            if (dict.find(str) != dict.end()) {
                i += (j - 1);
                break;
            }
        }
        answer.push_back(dict[str]);
        str += msg[i + 1];
        cout << str << endl;
        dict[str] = dict.size() + 1;
    }
    return answer;
}