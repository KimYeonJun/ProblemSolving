/*
[BOJ] 15683번: 감시

문제 풀이
1. cctv type별로 탐색 가능한 방향을 미리 저장.
2. DFS로 cctv의 방향을 모두 선택.
3. 각 cctv별로 선택된 방향을 탐색한다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct cctv {
	int x;
	int y;
	int type;
};
int answer = 987654321;
int N, M;
int board[10][10];
int t_board[10][10];
vector<cctv> cctv_list;
vector<int> watch_list[15];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
vector<vector<int>> dir_list[6] = { {{0},{1},{2},{3}},{{1,3},{0,2}},
	{{1,2},{2,3},{3,0},{0,1}},{{1,2,3},{0,1,3},{0,2,3},{0,1,2}},{{0,1,2,3}} };

void Input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			t_board[i][j] = board[i][j];
			if (board[i][j] == 0 || board[i][j]==6)
				continue;
			cctv_list.push_back(cctv{ i,j,board[i][j] });
		}
	}
}
void Copy_Map() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			board[i][j] = t_board[i][j];
		}
	}
}
void Do_Watch(int x,int y,int d) {
	while (1) {
		x += dx[d];
		y += dy[d];
		if (x < 0 || x >= N || y < 0 || y >= M||board[x][y]==6)
			break;
		if (board[x][y] == 0)
			board[x][y] = -1;
	}
}
void getAnswer() {
	int tmp = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 0)
				tmp++;
		}
	}
	answer = min(answer, tmp);
}
void DFS(int cnt) {
	if (cnt == cctv_list.size()) {
		Copy_Map();
		for (int i = 0; i < cnt; i++) {
			for (int j = 0; j < watch_list[i].size(); j++) {
				Do_Watch(cctv_list[i].x, cctv_list[i].y, watch_list[i][j]);
			}
		}
		getAnswer();
		return;
	}
	int type = cctv_list[cnt].type;
	for (int i = 0; i < dir_list[type - 1].size(); i++) {
		watch_list[cnt] = dir_list[type - 1][i];
		DFS(cnt + 1);
	}
}
void Solve() {
	Input();
	DFS(0);
	cout << answer << endl;
}
int main() {
	Solve();
	return 0;
}