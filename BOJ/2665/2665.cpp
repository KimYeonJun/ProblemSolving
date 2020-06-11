/*
BOJ 2665번: 미로만들기
문제 유형 : BFS

문제 풀이
1. 방문을 확인하는 2차원 배열인 visit을 int형으로 선언.
	-> 정점 방문 시, visit배열에 해당 정점에 방문했을때 검은방에서 흰 방으로 바꾼 최소값을 갱신.
*/
#include <iostream>
#include <queue>
#include <string>
using namespace std;
int n;
int board[50][50];
int visit[50][50];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
void Input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < n; j++) {
			board[i][j] = input[j]-'0';
		}
	}
}
void BFS() {
	queue<pair<int,int>> que;
	que.push({ 0,0 });
	visit[0][0] = 0;
	while (!que.empty()) {
		auto cur = que.front();
		int x = cur.first;
		int y = cur.second;
		que.pop();
		cnt++;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n)
				continue;
			if (board[nx][ny] == 1) { // 빈방
				if (visit[nx][ny] > visit[x][y]) {
					visit[nx][ny] = visit[x][y];
					que.push({ nx,ny });
				}
			}
			else { //벽
				if (visit[x][y] + 1 < visit[nx][ny]) {
					visit[nx][ny] = visit[x][y] + 1;
					que.push({ nx,ny });
				}
			}
		}
	}
	cout << visit[n-1][n-1] << endl;
}
void Solution() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visit[i][j] = 987654321;
		}
	}
	BFS();
}
void Solve() {
	Input();
	Solution();
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Solve();
	return 0;
}