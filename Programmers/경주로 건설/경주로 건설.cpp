/*
2020 카카오 인턴십 4번
문제 유형 : 최단거리(BFS)

문제 풀이
1. BFS를 활용하여 최소 금액, 최단 거리를 구함.
2. 한 정점에서 4방향에 대한 cost가 다르므로, 3차원 visit배열을 활용.
3. 정점 방문 시, cost가 더 작은 경우에만 방문 가능

*/
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#define INF 987654321;
using namespace std;
int visit[26][26][4];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
struct load {
    int x;
    int y;
    int dir;
};
int solution(vector<vector<int>> board) {
    int answer = INF;
    int N = board.size();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < 4; k++)
                visit[i][j][k] = INF;
        }
    }
    queue<load> que;
    que.push(load{ 0,0,0 });
    que.push(load{ 0,0,1 });
    visit[0][0][0] = 0;
    visit[0][0][1] = 0;
    while (!que.empty()) {
        load cur = que.front();
        int x = cur.x;
        int y = cur.y;
        int dir = cur.dir;
        que.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= N || nx < 0 || nx >= N || board[nx][ny] == 1)
                continue;
            if (dir == i || (dir + 2) % 4 == i) {
                if (visit[nx][ny][i] > visit[x][y][dir] + 100) {
                    visit[nx][ny][i] = visit[x][y][dir] + 100;
                    que.push(load{ nx,ny,i });
                }
            }
            else {
                if (visit[nx][ny][i] > visit[x][y][dir] + 600) {
                    visit[nx][ny][i] = visit[x][y][dir] + 600;
                    que.push(load{ nx,ny,i });
                }
            }
        }

    }
    for (int i = 0; i < 4; i++) {
        answer = min(answer, visit[N - 1][N - 1][i]);
    }
    return answer;
}