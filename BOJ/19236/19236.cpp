/*
[BOJ] 19236번: 청소년 상어
시작 시간 : 19 시 28분
종료 시간 : 



물고기 한칸 -> 빈칸 or 다른 물고기 있는 칸 이동 가능
상어 or 맵 밖은 못감

상어는 물고기 있는 칸만 갈 수 있다.
이동할 수 없으면 집으로
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Fish {
	int x;
	int y;
	int dir;
	bool die = false;
};
Fish fish_list[17];
int board[4][4];
int dx[8] = {-1,-1,0,1,1,1,0,-1 };
int dy[8] = {0,-1,-1,-1,0,1,1,1 };
Fish shark;
int answer = 0;
void print() {
	cout << "--------------------------" << endl;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	cout << "-------------------------------" << endl;
}
void Input() {
	int a, b;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> a >> b;
			board[i][j] = a;
			Fish fish;
			fish.x = i;
			fish.y = j;
			fish.dir = b-1;
			fish_list[a] = fish;
		}
	}
}
void moveFish() {

	for (int i = 1; i <= 16; i++) {
		Fish fish = fish_list[i];
		if (fish.die)
			continue;
		int x = fish.x;
		int y = fish.y;
		int dir = fish.dir;
		for (int j = 0; j < 8; j++) {
			int ndir = (dir + j) % 8;
			int nx = x + dx[ndir];
			int ny = y + dy[ndir];
			if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4)
				continue;
			if (board[nx][ny] == -1)
				continue;
			if (board[nx][ny] != 0) {
				int nxt = board[nx][ny];
				fish_list[nxt].x = x;
				fish_list[nxt].y = y;
			}
			fish_list[i].x = nx;
			fish_list[i].y = ny;
			fish_list[i].dir = ndir;
			board[x][y] = board[nx][ny];
			board[nx][ny] = i;
			break;
		}
	}
}
void copy(int A[][4], int B[][4], Fish C[], Fish D[]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			A[i][j] = B[i][j];
		}
	}
	for (int i = 1; i <= 16; i++) {
		C[i] = D[i];
	}
}
void DFS(int x,int y, int dir,int sum) {
	Fish tmp_fish_list[17];
	int tmp_board[4][4];
	copy(tmp_board, board, tmp_fish_list, fish_list);
	moveFish();
	for (int i = 1; i <= 3; i++) {
		int nx = x + dx[dir] * i;
		int ny = y + dy[dir] * i;
		if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4)
			break;;
		if (board[nx][ny] > 0) {
			int nxt = board[nx][ny];
			fish_list[nxt].die = true;
			board[x][y] = 0;
			board[nx][ny] = -1;
			DFS(nx, ny, fish_list[nxt].dir, sum + nxt);
			board[nx][ny] = nxt;
			board[x][y] = -1;
			fish_list[nxt].die = false;
		}
	}
	copy(board, tmp_board, fish_list, tmp_fish_list);
	answer = max(answer, sum);
	return;
}
void Solution() {
	int nxt = board[0][0];
	fish_list[nxt].die = true;
	board[0][0] = -1;
	DFS(0,0, fish_list[nxt].dir,nxt);
}
void Solve() {
	Input();
	Solution();
	cout << answer << endl;
}
int main() {
	Solve();
	return 0;
}