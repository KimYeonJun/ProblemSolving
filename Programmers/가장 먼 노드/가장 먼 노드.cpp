/*
프로그래머스: 가장 먼 노드
문제 유형 : BFS

주어진 간선에 대한 정보를 graph에 저장.
BFS로 경로 탐색.
*/
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<int> graph[20001];
int visit[20001];
void BFS() {
    queue<int> que;
    visit[1] = 1;
    que.push(1);
    while (!que.empty()) {
        int cur = que.front();
        que.pop();
        for (int i = 0; i < graph[cur].size(); i++) {
            int nxt = graph[cur][i];
            if (visit[nxt])
                continue;
            visit[nxt] = visit[cur] + 1;
            que.push(nxt);
        }
    }
    return;
}
int getAnswer() {
    sort(visit, visit + 20001, greater<int>());
    int max = visit[0];
    int result = 1;
    for (int i = 1; i < 20001; i++) {
        if (visit[i] == max)
            result++;
        else
            break;
    }
    return result;
}
int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    for (int i = 0; i < edge.size(); i++) {
        graph[edge[i][0]].push_back(edge[i][1]);
        graph[edge[i][1]].push_back(edge[i][0]);
    }
    BFS();
    answer = getAnswer();
    return answer;
}