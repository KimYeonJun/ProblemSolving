/*
BOJ 13460번: 구슬 탈출2
문제 유형 : BFS, 구현
*/
#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct marble {
	int rx;
	int ry;
	int bx;
	int by;
	int move=0;
};
marble mb;
int N, M;
int goal_x, goal_y;
char board[11][11];
bool visit[11][11][11][11];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
void Input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < M; j++) {
			board[i][j] = input[j];
			if (board[i][j] == 'B') {
				mb.bx = i;
				mb.by = j;
			}
			else if (board[i][j] == 'R') {
				mb.rx = i;
				mb.ry = j;
			}
			else if (board[i][j] == 'O') {
				goal_x = i;
				goal_y = j;
			}
		}
	}
}
int Tilt(int& x, int& y, int dir) {
	int cnt = 0;
	while (true) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (board[nx][ny] != '#' && board[x][y] !='O') {
			x = nx;
			y = ny;
			cnt++;
		}
		else {
			return cnt;
		}
	}
}
int Solution() {
	queue<marble> que;
	que.push(mb);
	visit[mb.rx][mb.ry][mb.bx][mb.by] = true;
	while (!que.empty()) {
		marble cur = que.front();
		que.pop();
		if (cur.move >= 10)
			return -1;
		for (int i = 0; i < 4; i++) {
			int rx = cur.rx;
			int ry = cur.ry;
			int bx = cur.bx;
			int by = cur.by;
			int nMove = cur.move + 1;

			int redMove = Tilt(rx, ry, i);
			int blueMove = Tilt(bx, by, i);
			if (board[bx][by] == 'O') {
				continue;
			}
			if (redMove == 0 && blueMove == 0)
				continue;
			if (board[rx][ry] == 'O') {
				return nMove;
			}
			if (rx == bx && ry == by) {
				if (redMove < blueMove) {
					bx -= dx[i];
					by -= dy[i];
				}
				else {
					rx -= dx[i];
					ry -= dy[i];
				}
			}
			if (visit[rx][ry][bx][by])
				continue;
			visit[rx][ry][bx][by] = true;
			que.push(marble{ rx,ry,bx,by,nMove });
		}
	}
	return -1;
}
int main() {
	Input();
	cout << Solution() << endl;;

	
}