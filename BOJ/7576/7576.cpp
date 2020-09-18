/*
BOJ 7576번: 토마토
문제 유형 : BFS

문제 풀이: 익은 토마토의 4방향에 썩은 토마토가 있다면 익은 토마토로 변경.
-> 새로 익은 토마토에 똑같이 적용
-> 모든 썩은토마토가 익으면 끝.
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <math.h>
#include <sstream>
#include <unordered_map>
#define endl '\n'
#define INF 987654321
#define MAX 100001
using namespace std;
struct tomato {
	int x;
	int y;
	int t;
};
int N, M;
int board[1001][1001];
bool visit[1001][1001];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int cnt = 0;
vector<pair<int, int>> vec;
int BFS() {
	queue<tomato> que;
	for (int i = 0; i < vec.size(); i++) {
		int x = vec[i].first;
		int y = vec[i].second;
		que.push(tomato{ x,y,0 });
		visit[x][y] = true;
	}
	while (!que.empty()) {
		tomato cur = que.front();
		que.pop();
		int x = cur.x;
		int y = cur.y;
		int t = cur.t;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M || visit[nx][ny] || board[nx][ny] == -1)
				continue;
			que.push(tomato{ nx,ny,t + 1 });
			visit[nx][ny] = true;
			if (++cnt == N * M) {
				return t + 1;
			}
		}
	}
	return -1;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] == 0)
				continue;
			cnt++;
			if (board[i][j] == 1) {
				vec.push_back({ i,j });
			}
		}
	}
	if (cnt == (N * M)) {
		cout << "0" << endl;
		return 0;
	}

	cout << BFS() << endl;
}