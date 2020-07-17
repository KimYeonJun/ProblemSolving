/*
프로그래머스: 네트워크
문제유형: DFS or BFS

DFS탐색을 통해 네트워크를 연결하고, 최종적인 네트워크 수를 구한다.
*/
#include <string>
#include <vector>
#include <queue>
using namespace std;
bool visit[201];
void DFS(int idx, int n, vector<vector<int>> computers) {
    visit[idx] = true;
    for (int i = 0; i < n; i++) {
        if (idx == i || visit[i] || computers[idx][i] == 0)
            continue;
        DFS(i, n, computers);
    }

}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for (int i = 0; i < n; i++) {
        if (visit[i])
            continue;
        answer++;
        DFS(i, n, computers);
    }
    return answer;
}