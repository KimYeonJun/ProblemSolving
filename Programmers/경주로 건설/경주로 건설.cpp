/*
2020 īī�� ���Ͻ� 4��
���� ���� : �ִܰŸ�(BFS)

���� Ǯ��
1. BFS�� Ȱ���Ͽ� �ּ� �ݾ�, �ִ� �Ÿ��� ����.
2. �� �������� 4���⿡ ���� cost�� �ٸ��Ƿ�, 3���� visit�迭�� Ȱ��.
3. ���� �湮 ��, cost�� �� ���� ��쿡�� �湮 ����

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