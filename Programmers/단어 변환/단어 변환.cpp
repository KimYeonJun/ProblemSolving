/*
프로그래머스: 단어 변환
문제 유형: DFS, BFS

DFS로 탐색 하여 단어 변환이 가능한 모든 경우의 수를 비교.
*/
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int maxNum = 987654321;
int answer;
bool visit[51];
bool isPossible(string begin, string comp) {
    int cnt = 0;
    for (int i = 0; i < begin.size(); i++) {
        if (begin[i] == comp[i])
            cnt++;
    }
    if (begin.size() == cnt + 1)
        return true;

    return false;

}
void DFS(string begin, string target, vector<string> words, int cnt) {
    if (begin == target) {
        answer = min(answer, cnt);
        return;
    }
    for (int i = 0; i < words.size(); i++) {
        string str = words[i];
        if (isPossible(begin, str) && !visit[i]) {
            visit[i] = true;
            DFS(str, target, words, cnt + 1);
            visit[i] = false;
        }
    }
}
int solution(string begin, string target, vector<string> words) {
    answer = maxNum;
    DFS(begin, target, words, 0);
    if (answer == maxNum)
        answer = 0;
    return answer;
}