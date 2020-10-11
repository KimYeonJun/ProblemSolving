/*
[BOJ] 16988번: Baaaaaaaaaduk2 (Easy)
시작 시간 : 10시 10분
종료 시간 : 10시 45분
소요 시간 : 35분

문제 풀이

1. DFS
	1.1) 빈 칸의 집합에서 순열로 2개를 선택한다.
	1.2) 선택된 칸의 좌표를 나의 돌로 변경하고 BFS()실행
	1.3) BFS()종료되면, 다시 빈 칸으로 복원
2. BFS
	2.1) 상대의 돌이 놓인 칸 중에서 아직 방문하지 않은 칸을 시작으로 BFS 실행
	2.2) BFS를 돌면서 0을 만난다면 flag=false 처리하여, 죽을 수 없음을 표시한다.
	2.3) 2를 만난다면, 연결되어 있는 상대의 돌이므로 방문을 체크한다.
	2.4) 죽을 수 있는 경우(flag==true) 라면, 결과 값 갱신.

*/

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M;
int board[21][21];
bool visit[21][21];
bool doll_visit[401];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
vector<pair<int, int>> doll_list;
vector<pair<int, int>> doll_select;
int answer = 0;
void Input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] == 0) {
				doll_list.push_back({ i,j });
			}
		}
	}
}
int BFS(int x, int y) {
	int cnt = 1;
	queue<pair<int, int>> que;
	que.push({ x,y });
	visit[x][y] = true;
	bool flag = true;
	while (!que.empty()) {
		auto cur = que.front();
		que.pop();
		int x = cur.first;
		int y = cur.second;
		//cout << x << " " << y << endl;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M || visit[nx][ny])
				continue;
			if (board[nx][ny] == 0) {
				flag = false;
				continue;
			}
			if (board[nx][ny] == 1)
				continue;
			if (board[nx][ny] == 2) {
				visit[nx][ny] = true;
				que.push({ nx,ny });
				cnt++;
			}
		}
	}
	if (flag == false)
		cnt = 0;
	return cnt;
}
void Solution() {
	memset(visit, 0, sizeof(visit));
	int res = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visit[i][j] || board[i][j] == 0 || board[i][j] == 1)
				continue;
			//cout << i << " " << j << endl;
			res += BFS(i, j);
			//cout<<"결과 : " << res << endl;
		}
	}
	answer = max(answer, res);
}
void DFS(int idx, int cnt) {
	if (cnt == 2) {
		for (int i = 0; i < 2; i++) {
			int x = doll_select[i].first;
			int y = doll_select[i].second;
			//cout << "시작 : " << x << " " << y << endl;
			board[x][y] = 1;
		}
		Solution();
		for (int i = 0; i < 2; i++) {
			int x = doll_select[i].first;
			int y = doll_select[i].second;
			board[x][y] = 0;
		}
		return;
	}
	for (int i = idx; i < doll_list.size(); i++) {
		if (doll_visit[i])
			continue;
		doll_visit[i] = true;
		doll_select.push_back({ doll_list[i].first,doll_list[i].second });
		DFS(i, cnt + 1);
		doll_select.pop_back();
		doll_visit[i] = false;
	}
}
void Solve() {
	Input();
	DFS(0, 0);
	cout << answer << endl;
}
int main() {
	Solve();

	return 0;
}