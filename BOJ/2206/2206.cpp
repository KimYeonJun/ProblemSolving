/*
BOJ 2206번: 벽 부수고 이동하기
문제 유형 : 시뮬레이션(BFS)
문제 풀이 : 
			굉장히 까다로운 BFS 문제. BFS 탐색 조건이 너무 어려움.
			queue에 좌표,벽 뚫기 사용여부, 이동 거리를 넣으며 이동한다.
			각 좌표의 방문 조건으로는 벽 뚫기를 사용하고 방문했는지, 벽 뚫기를 사용하지 않고 방문했는지 체크를 위해 3차원배열을 사용.
			큐에 push 조건으로는 
				1. 다음 좌표가 벽이고, 벽 뚫기를 사용했는지 -> 진행못함
				2. 다음 좌표가 벽이고, 벽 뚫기를 사용 안했는지 -> 벽 뚫기를 사용하고 방문했다고 체크
				3. 다음 좌표가 벽이 아니고,  벽 뚫기를 사용한 경우 -> 벽 뚫기를 사용하고 방문했는지 확인 
							-> 벽 뚫기를 사용하고 이미 방문한 곳이라면 최단거리의 후보에서 벗어난다.
				4. 다음 좌표가 벽이 아니고 , 벽 뚫기를 사용하지 않은 경우 -> 벽 뚫기를 사용하지 않고 방문했는지 확인
							-> 벽 뚫기를 사용하지 않고 이미 방문했던 곳이라면 최단거리의 후보에서 벗어난다.
*/
#include <iostream>
#include <queue>
#include <string>
using namespace std;
struct people {
	int x;
	int y;
	int breakWall;
	int dis;
};
int N, M;
int board[1001][1001];
bool visit[1001][1001][2];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };


void Input() {
	cin >> N >> M;
	string input;
	for (int i = 1; i <=N; i++) {
		cin >> input;
		for (int j = 1; j <= M; j++) {
			board[i][j] = input[j-1] - '0';
		}
	}
}
int BFS() {
	visit[1][1][0] = true;
	queue<people> que;
	que.push(people{ 1,1,0,1 });
	while (!que.empty()) {
		people cur = que.front();
		if (cur.x == N && cur.y == M)
			return cur.dis;
		que.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];
			int nb = cur.breakWall;
			int ndis = cur.dis + 1;
			if (nx<1 || nx>N || ny<1 || ny>M)
				continue;
			if (board[nx][ny] == 1 && nb == 0) {
				visit[nx][ny][1] = true;
				que.push(people{ nx,ny,1,ndis });
			}
			else if (board[nx][ny] == 0 && !visit[nx][ny][nb]) {
				visit[nx][ny][nb] = true;
				que.push(people{ nx,ny,nb,ndis });
			}
		}

	}
	return -1;
}
void Solve() {
	Input();
	cout << BFS() << endl;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	Solve();
	return 0;
}