/*
[BOJ] 17144번: 미세먼지 안녕!
시작 시간 : 16시 13분
종료 시간 : 16시 54분
소요 시간 : 41분

문제 풀이
1. Spread
	1.1) 미세먼지가 확산할 때 각 칸에 새롭게 더해지는 미세먼지 양을 임시 맵(t_board)에 저장한다.
	1.2) 확산이 끝나면, 남은 미세먼지(board)에 새롭게 더해지는 미세먼지(t_board)를 더한다.
2. Clean
	2.1) 위쪽 바람(i==0), 아래쪽 바람(i==1) 각 경우에 DFS 실행
	2.2) DFS의 인자는 좌표, 진행중인 방향, 공기 청정기 타입(위쪽 or 아래쪽)을 가진다.
	2.3) 위쪽 바람 DFS는 북쪽 방향에 대한 clean이 먼저 일어나므로 dir==2부터 시작
	2.4) 아래쪽 바람 DFS는 남쪽 방향에 대한 clean이 먼저 일어나므로 dir==0부터 시작
3. DFS
	3.1) DFS의 종료 조건은 공기청정기의 옆칸에 도착한 경우이다
	3.2) 진행중인 방향이 맵의 range를 벗어나면 type에 맞게 방향을 전환.
	3.3) 혹은 공기청정기의 x좌표, 마지막 y좌표에 도착해도 방향을 전환한다.
*/
#include <iostream>
#include <cstring>
using namespace std;
int board[51][51];
int t_board[51][51];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int N, M, T;
pair<int, int> air[2];
void Input() {
	cin >> N >> M >> T;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] == -1) {
				if (air[0].first == 0) {
					air[0].first = i;
					air[0].second = j;
				}
				else {
					air[1].first = i;
					air[1].second = j;
				}
			}
		}
	}
}
void Spread() {
	memset(t_board, 0, sizeof(t_board));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] > 0) {
				int cnt = 0;
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx < 0 || nx >= N || ny < 0 || ny >= M || board[nx][ny] == -1)
						continue;
					t_board[nx][ny] += board[i][j] / 5;
					cnt++;
				}
				board[i][j] -= ((board[i][j] / 5) * cnt);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			board[i][j] += t_board[i][j];
		}
	}
}
void DFS(int x, int y,int dir,int type) {
	if (x == air[type].first && y == air[type].second + 1) {
		board[x][y] = 0;
		return;
	}
	int nx = x + dx[dir];
	int ny = y + dy[dir];
	if ((x==air[type].first && y==M-1)||nx < 0 || nx >= N || ny < 0 || ny >= M) {
		if (type == 0) {
			dir -= 1;
			if (dir == -1)
				dir = 3;
		}
		else {
			dir = (dir + 1) % 4;
		}
		nx = x + dx[dir];
		ny = y + dy[dir];
	}
	board[x][y] = board[nx][ny];
	DFS(nx, ny, dir,type);

}
void Clean() {
	for (int i = 0; i < 2; i++) {
		int sx, sy =air[i].second;
		if (i == 0) {
			sx = air[i].first - 1;
			DFS(sx, sy, 2, i);
		}
		else {
			sx = air[i].first + 1;
			DFS(sx, sy, 0, i);
		}
		board[sx][sy] = 0;
	}
}
void Print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}
void getAnswer() {
	int answer = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == -1)
				continue;
			answer += board[i][j];
		}
	}
	cout << answer << endl;
}
void Solution() {
	while (T--) {
		Spread();
		Clean();
	}
	getAnswer();
}
void Solve() {
	Input();
	Solution();
}
int main() {
	Solve();
	return 0;
}