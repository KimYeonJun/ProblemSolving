/*
SWEA 1949번 : 등산로 조성
문제 유형 : 시뮬레이션, 완전탐색

1. 가장 높은 봉우리들을 시작점으로 잡고 DFS 탐색.
2. 다음 칸이 현재 칸보다 낮은 곳이라면 그대로 DFS 탐색.
3. 다음 칸이 현재 칸보다 낮은 곳이 아니라면
	(1) 등산로 깎기를 이미 사용했으면 다음 칸으로 진행 못함
	(2) 등산로 깎기를 사용하지 않았다면, 다음 칸을 1~K까지 깎으면서 진행하고 등산로 깎기 사용 체크.

<-- 처음 풀이 -->
처음 풀이에는 시작 지점을 제외한 모든 칸을 차례대로 1~K까지 깎아서 DFS를 하였다.
이 풀이는 89ms로 다른 사람들보다 시간이 오래걸려서
블로그 참고 후, 다시 풀었더니 11ms로 줄일 수 있었음.

처음 풀이에는 굳이 안깎아도 되는 곳까지 깎으면서 탐색을 하니까 훨씬 오랜 시간이 소요됨

void Solution() {
	for (int i = 0; i < start_point.size(); i++) {
		int x = start_point[i].first;
		int y = start_point[i].second;
		//맵멀쩡할때
		visit[x][y] = true;
		DFS(x,y,1);
		for (int j = 1; j <= K; j++) {
			for (int k = 0; k < N; k++) {
				for (int l = 0; l < N; l++) {
					if (k == x && l == y)
						continue;
					if (board[k][l] - j >= 0) { //지형깎기
						board[k][l] -= j;
						DFS(x,y,1);
						board[k][l] += j;
					}
				}
			}
		}
		visit[x][y] = false;
	}
}
*/
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int N, K, result, max_height;
int board[8][8];
int t_board[8][8];
bool visit[8][8];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
vector<pair<int, int>> start_point;
void Input() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			max_height = max(max_height, board[i][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == max_height)
				start_point.push_back({ i,j });
		}
	}
}
void Initialize() {
	memset(board, 0, sizeof(board));
	memset(visit, 0, sizeof(visit));
	result = 0;
	max_height = 0;
	start_point.clear();
}
void DFS(int x, int y, int cnt,bool use) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= N || ny < 0 || ny >= N)
			continue;
		if (visit[nx][ny])
			continue;
		if (board[x][y] > board[nx][ny]) {
			visit[nx][ny] = true;
			DFS(nx, ny, cnt + 1, use);
			visit[nx][ny] = false;
		}
		else {
			if (use)
				continue;
			for (int j = 1; j <= K; j++) {
				int nextVal = board[nx][ny] - j;
				if (nextVal >= 0 && board[x][y]>nextVal) {
					board[nx][ny] -= j;
					visit[nx][ny] = true;
					use = true;
					DFS(nx, ny, cnt + 1, use);
					use = false;
					visit[nx][ny] = false;
					board[nx][ny] += j;
				}
			}
		}
	}
	result = max(result, cnt);
}
void Solution() {
	for (int i = 0; i < start_point.size(); i++) {
		int x = start_point[i].first;
		int y = start_point[i].second;
		visit[x][y] = true;
		DFS(x, y, 1,false);
		visit[x][y] = false;
	}
}
void Solve() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		Initialize();
		Input();
		Solution();
		cout << "#" << i << " " << result << endl;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Solve();
	return 0;
}