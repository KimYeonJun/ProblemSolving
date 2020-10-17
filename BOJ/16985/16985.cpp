/*
[BOJ] 16985번: Maaaaaaaaaze

문제 풀이
1. 순열을 사용하여 판을 쌓는 순서를 정한다.
2. 중복조합을 사용하여, 각 판을 90도, 180도, 270도, 360도 회전 시켜본다.
3. 각 판을 회전 시킨 후, BFS를 사용하여 (0,0,0) 에서 (4,4,4)까지의 최단 거리를 구한다.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#define INF 987654321
using namespace std;
struct loc {
	int z;
	int x;
	int y;
	int t;
};
int board[5][5][5];
int tboard[5][5][5];
int tmp[5][5];
int visit[5];
bool select_visit[5];
bool bfs_visit[5][5][5];
int dx[6] = { 1,0,-1,0,0,0 };
int dy[6] = { 0,1,0,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };
int answer = INF;
int order[5];
void Input() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				cin >> board[i][j][k];
			}
		}
	}
}
void Rotate(int idx) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++)
			tmp[i][j] = tboard[idx][i][j];
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			tboard[idx][i][j] = tmp[4 - j][i];
		}
	}
}
int BFS() {
	int res = INF;
	memset(bfs_visit, 0, sizeof(bfs_visit));
	queue<loc> que;
	que.push({ 0,0,0,0 });
	bfs_visit[0][0][0] = true;
	while (!que.empty()) {
		loc cur = que.front();
		que.pop();
		int z = cur.z;
		int x = cur.x;
		int y = cur.y;
		int t = cur.t;
		if (x == 4 && y == 4 && z == 4) {
			res = t;
			break;
		}
		for (int i = 0; i < 6; i++) {
			int nz = z + dz[i];
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nz < 0 || nz >= 5 || nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || bfs_visit[nz][nx][ny])
				continue;
			if (tboard[nz][nx][ny] == 1) {
				bfs_visit[nz][nx][ny] = true;
				que.push({ nz,nx,ny,t + 1 });
			}
		}
	}
	return res;

}
void DFS(int cnt) {
	if (cnt == 5) {
		if (tboard[0][0][0] == 1 && tboard[4][4][4] == 1) {
			answer = min(answer,BFS());
			if (answer == 12) {
				cout << "12" << endl;
				exit(0);
			}
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		DFS(cnt + 1);
		Rotate(order[cnt]);
	}
}
void Select_DFS(int cnt) {
	if (cnt == 5) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				for (int k = 0; k < 5; k++) {
					tboard[i][j][k] = board[order[i]][j][k];
				}
			}
		}
		DFS(0);
		return;
	}
	for (int i = 0; i < 5; i++) {
		if (select_visit[i])
			continue;
		select_visit[i] = true;
		order[cnt] = i;
		Select_DFS(cnt + 1);
		select_visit[i] = false;
	}
}
void Solve() {
	Input();
	Select_DFS(0);
	if (answer == INF)
		answer = -1;
	cout << answer << endl;
}
int main() {
	Solve();
	return 0;
}