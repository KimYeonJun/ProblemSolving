/*
BOJ 2665��: �̷θ����
���� ���� : BFS

���� Ǯ��
1. �湮�� Ȯ���ϴ� 2���� �迭�� visit�� int������ ����.
	-> ���� �湮 ��, visit�迭�� �ش� ������ �湮������ �����濡�� �� ������ �ٲ� �ּҰ��� ����.
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
			if (board[nx][ny] == 1) { // ���
				if (visit[nx][ny] > visit[x][y]) {
					visit[nx][ny] = visit[x][y];
					que.push({ nx,ny });
				}
			}
			else { //��
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