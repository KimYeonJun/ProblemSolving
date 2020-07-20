/*
프로그래머스: 여행경로
문제 유형: DFS

DFS로 탐색하여 가능한 여행경로를 모두 저장하고,
알파벳순으로 정렬
*/
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool visit[10000];
int N;
vector<vector<string>> answer;
bool cmp(vector<string>& a, vector<string>& b) {
    return a < b;
}
void DFS(string cur, vector<vector<string>>& tickets, int cnt, vector<string> path) {
    if (cnt == N) {
        answer.push_back(path);
        return;
    }
    for (int i = 0; i < N; i++) {
        if (tickets[i][0] == cur && !visit[i]) {
            visit[i] = true;
            path.push_back(tickets[i][1]);
            DFS(tickets[i][1], tickets, cnt + 1, path);
            path.pop_back();
            visit[i] = false;
        }
    }
}
vector<string> solution(vector<vector<string>> tickets) {
    N = tickets.size();
    vector<string> path{ "ICN" };
    DFS("ICN", tickets, 0, path);
    sort(answer.begin(), answer.end());
    return answer[0];
}