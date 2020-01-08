#include <iostream>
#include <queue>
#include <string>
using namespace std;
int board[102][102];
bool vis[102][102];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
struct point {
	int x;
	int y;
	int move; //몇번 움직였는지 기록하기 위한 변수
};
int main() {
	int N, M;
	cin >> N >> M;
	
	for (int i = 1; i <= N; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < input.size(); j++) {
			board[i][j + 1] = input[j] - '0';
		}

	}

	queue<point> que;
	que.push({1,1,1});
	vis[1][1] = true;
	while (!que.empty()) {
		auto cur = que.front();
		que.pop();
		if (cur.x == N && cur.y == M) {
			cout << cur.move << endl;
			break;
		}
		for (int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];
			int nm = cur.move + 1;
			if (nx<1 || nx>N || ny<1 || ny>M) {
				continue;
			}
			if (board[nx][ny] == 1 && !vis[nx][ny]) {
				que.push({ nx,ny,nm });
				vis[nx][ny] = true;
			}
		}
	}
	return 0;
}