/*
프로그래머스: 방금그곡
문제 유형 : 문자열

C#,D#,F#,G#,A# -> c,d,f,g,a로 변환
*/
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;
bool cmp(pair<string, int>& p1, pair<string, int>& p2) {
    return p1.second > p2.second;
}
string change(string m) {
    for (int i = 0; i < m.size(); i++) {
        if (m[i] == '#') {
            m[i - 1] = m[i - 1] - 'A' + 'a';
            m.erase(m.begin() + i);
            i--;
        }
    }
    return m;
}
vector<string> getInfo(string musicinfos) {
    vector<string> res;
    stringstream ss(musicinfos);
    string token;
    while (getline(ss, token, ',')) {
        res.push_back(token);
    }
    return res;
}
int getTime(string start, string end) {
    int start_h = stoi(start.substr(0, 2));
    int start_m = stoi(start.substr(3, 5));
    int end_h = stoi(end.substr(0, 2));
    int end_m = stoi(end.substr(3, 5));
    if (start_h == end_h)
        return end_m - start_m;

    else
        return (end_m + 60 - start_m) + (end_h - start_h - 1) * 60;

}
string getMelody(string m, int time) {
    m = change(m);
    string res = "";
    int cnt = 0;
    for (int i = 0; i < time; i++) {
        res += m[cnt];
        cnt = (cnt + 1) % m.size();
    }
    return res;
}
string solution(string m, vector<string> musicinfos) {
    string answer = "";
    int max_time = 0;
    m = change(m);
    vector<pair<string, int>> res;
    for (int i = 0; i < musicinfos.size(); i++) {
        vector<string> info = getInfo(musicinfos[i]);
        int time = getTime(info[0], info[1]);
        string melody = getMelody(info[3], time);
        if (melody.find(m) != string::npos) {
            if (max_time < time) {
                answer = info[2];
                max_time = time;
            }
        }
    }
    if (answer.size() == 0)
        answer = "(None)";
    return answer;
}