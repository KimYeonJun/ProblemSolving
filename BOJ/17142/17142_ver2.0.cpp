/*
[BOJ] 17142��: ������ 3

1. Input
	1.1) 0�� �Է¹����� �� ĭ�� count�� ����(BFS �� ��� �� ĭ�� ���̷����� �������� Ȯ���ϱ� ����)
	1.2) 2�� �Է¹����� ���̷��� ����Ʈ�� �߰�(DFS ������ ����)
2. DFS
	2.1) DFS �������� M���� ����
3. BFS
	3.1) ���õ� M���� ���̷����� �������� BFS Ž��.
	3.2) �� ĭ�� ���̷����� ������ ��쿡�� max_time�� �����ϰ�, cnt(���̷����� ���� �� ĭ�� ��)�� ����
	3.3) ��Ȱ�� ���̷��� ĭ�� ���̷����� ������ ��쿡�� 3.2�� �۾��� ���� �ʴ´�.
	3.4) BFS�� ������, �Է� �� ������ �� ĭ�� ���� BFS�� ���� ���� cnt�� ���Ͽ� ������ ������ �����Ѵ�.
*/
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
struct Virus {
	int x;
	int y;
};
int N, M, empty_cnt = 0, answer = 987654321;
int board[51][51];
int time[51][51];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
vector<Virus> virus_list;
bool virus_visit[11];
void Input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (board[i][j] == 0) {
				empty_cnt++;
			}
			else if (board[i][j] == 2) {
				virus_list.push_back({ i,j });
			}
		}
	}
}
void BFS(queue<Virus>& que) {
	int cnt = 0;
	int max_time = 0;
	while (!que.empty()) {
		Virus cur = que.front();
		que.pop();
		int x = cur.x;
		int y = cur.y;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N || board[nx][ny] == 1)
				continue;
			if (time[nx][ny] == -1) {
				time[nx][ny] = time[x][y] + 1;
				que.push({ nx,ny });
				if (board[nx][ny] == 0) {
					cnt++;
					max_time = time[nx][ny];
				}
			}
		}
	}
	if (cnt == empty_cnt) {
		answer = min(answer, max_time);
	}
}
void Solution() {
	memset(time, -1, sizeof(time));
	queue<Virus> que;
	for (int i = 0; i < virus_list.size(); i++) {
		if (virus_visit[i]) {
			que.push({ virus_list[i].x,virus_list[i].y });
			time[virus_list[i].x][virus_list[i].y] = 0;
		}
	}
	BFS(que);
}
void DFS(int idx, int cnt) {
	if (cnt == M) {
		Solution();
	}
	for (int i = idx; i < virus_list.size(); i++) {
		if (virus_visit[i])
			continue;
		virus_visit[i] = true;
		DFS(i, cnt + 1);
		virus_visit[i] = false;
	}
}
void Solve() {
	Input();
	DFS(0, 0);
	if (answer == 987654321)
		answer = -1;
	cout << answer << endl;
}
int main() {
	Solve();
	return 0;
}