/*
[BOJ] 17144��: �̼����� �ȳ�!
���� �ð� : 16�� 13��
���� �ð� : 16�� 54��
�ҿ� �ð� : 41��

���� Ǯ��
1. Spread
	1.1) �̼������� Ȯ���� �� �� ĭ�� ���Ӱ� �������� �̼����� ���� �ӽ� ��(t_board)�� �����Ѵ�.
	1.2) Ȯ���� ������, ���� �̼�����(board)�� ���Ӱ� �������� �̼�����(t_board)�� ���Ѵ�.
2. Clean
	2.1) ���� �ٶ�(i==0), �Ʒ��� �ٶ�(i==1) �� ��쿡 DFS ����
	2.2) DFS�� ���ڴ� ��ǥ, �������� ����, ���� û���� Ÿ��(���� or �Ʒ���)�� ������.
	2.3) ���� �ٶ� DFS�� ���� ���⿡ ���� clean�� ���� �Ͼ�Ƿ� dir==2���� ����
	2.4) �Ʒ��� �ٶ� DFS�� ���� ���⿡ ���� clean�� ���� �Ͼ�Ƿ� dir==0���� ����
3. DFS
	3.1) DFS�� ���� ������ ����û������ ��ĭ�� ������ ����̴�
	3.2) �������� ������ ���� range�� ����� type�� �°� ������ ��ȯ.
	3.3) Ȥ�� ����û������ x��ǥ, ������ y��ǥ�� �����ص� ������ ��ȯ�Ѵ�.
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