/*
[BOJ] 17142번: 연구소 3

1. Input
	1.1) 0을 입력받으면 빈 칸의 count를 증가(BFS 후 모든 빈 칸에 바이러스가 퍼졌는지 확인하기 위해)
	1.2) 2를 입력받으면 바이러스 리스트에 추가(DFS 조합을 위해)
2. DFS
	2.1) DFS 조합으로 M개를 선택
3. BFS
	3.1) 선택된 M개의 바이러스를 시작으로 BFS 탐색.
	3.2) 빈 칸에 바이러스가 퍼지는 경우에는 max_time을 갱신하고, cnt(바이러스가 퍼진 빈 칸의 수)를 증가
	3.3) 비활성 바이러스 칸에 바이러스가 퍼지는 경우에는 3.2의 작업을 하지 않는다.
	3.4) BFS가 끝나면, 입력 시 저장한 빈 칸의 수와 BFS를 통해 구한 cnt를 비교하여 같으면 정답을 갱신한다.
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