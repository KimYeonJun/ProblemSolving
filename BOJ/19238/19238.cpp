/*
[BOJ] 19238번: 스타트 택시
시작 시간 : 15시 07분
종료 시간 : 16시 01분
소요 시간 : 54분

문제 풀이

1. Input
	1.1) 맵 입력 시, 벽인 경우 -1로 변경.
	1.2) 사람의 index를 맵에 표시한다.
	1.3) 사람의 좌표와 도착지점을 people_list 배열에 저장
2. BFS
	2.1) 택시에서 각 사람까지의 최단거리를 BFS로 구한다.
	2.2) BFS의 종료 조건은, 택시를 타지 않은 사람의 수를 다 찾으면 종료.
	2.3) 사람을 찾으면 택시를 태워야 할 사람을 정하기 위해 vector에 (사람번호, 최단거리)를 저장한다.
3. Move_Taxi
	3.1) vector 정렬을 통해, 택시를 태울 사람을 정한다.
	3.2) 연료 부족으로 택시 위치에서 승객의 위치까지 가지 못하면 retrun false;
	3.3) 갈 수 있다면 승객 위치부터 도착 위치까지 BFS해서 최단거리를 구한다.
	3.4) 남은 연료를 통해 도착위치 까지 갈 수있으면 연료 더하고, 택시위치 바꾸고, 맵에 표시된 승객을 지운다.
*/
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
struct People {
	int x;
	int y;
	int ex;
	int ey;
};
struct loc {
	int x;
	int y;
	int t;
};
int board[21][21];
bool visit[21][21];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
People people_list[410];
vector<pair<int,int>> vec;
int N, M, K;
int tx, ty;
bool cmp(pair<int, int>& a, pair<int, int>& b) {
	if (a.second == b.second) {
		int v1 = a.first;
		int v2 = b.first;
		if (people_list[v1].x == people_list[v2].x) {
			return people_list[v1].y < people_list[v2].y;
		}
		return people_list[v1].x < people_list[v2].x;
	}
	return a.second < b.second;
}
void Input() {
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1)
				board[i][j] = -1;
		}
	}
	cin >> tx >> ty;
	for (int i = 1; i <= M; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		board[a][b] = i;
		people_list[i].x = a;
		people_list[i].y = b;
		people_list[i].ex = c;
		people_list[i].ey = d;
	}
}
void BFS(int cnt) {
	memset(visit, 0, sizeof(visit));
	queue<loc> que;
	que.push(loc{ tx,ty,0 });
	visit[tx][ty] = true;
	if (board[tx][ty] > 0) { //틀렸습니다의 원인
		vec.push_back({ board[tx][ty],0 });
	}
	while (!que.empty()) {
		loc cur = que.front();
		que.pop();
		int x = cur.x;
		int y = cur.y;
		int t = cur.t;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<1 || nx>N || ny<1 || ny>N || visit[nx][ny] || board[nx][ny] == -1)
				continue;
			if (board[nx][ny] > 0) {
				vec.push_back({ board[nx][ny],t + 1 });
				if (--cnt == 0)
					return;
			}
			que.push({ nx,ny,t + 1 });
			visit[nx][ny] = true;
		}
	}
}
bool Move_Taxi() {
	if (K - vec[0].second < 0)
		return false;
	K -= vec[0].second;
	int num = vec[0].first;
	int sx = people_list[num].x; int sy = people_list[num].y;
	int ex = people_list[num].ex; int ey = people_list[num].ey;
	memset(visit, 0, sizeof(visit));
	queue<loc> que;
	que.push(loc{ sx,sy,0 });
	visit[sx][sy] = true;
	while (!que.empty()) {
		loc cur = que.front();
		que.pop();
		int x = cur.x; int y = cur.y; int t = cur.t;
		if (x == ex && y == ey) {
			if (K - t < 0)
				return false;
			K += t;
			tx = ex;
			ty = ey;
			board[sx][sy] = 0;
			return true;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i]; int ny = y + dy[i];
			if (nx<1 || nx>N || ny<1 || ny>N || visit[nx][ny] || board[nx][ny] == -1)
				continue;
			visit[nx][ny] = true;
			que.push(loc{ nx,ny,t + 1 });
		}
	}
	return false;
}
void Solution() {
	int answer = 0;
	for (int i = 0; i < M; i++) {
		vec.clear();
		BFS(M-i);
		sort(vec.begin(), vec.end(), cmp);
		if (vec.size()==0 || !Move_Taxi()) {
			answer = -1;
			break;
		}
	}

	if (answer == -1)
		cout << "-1" << endl;
	else {
		cout << K << endl;
	}
}
void Solve() {
	Input();
	Solution();
}
int main() {
	Solve();
	return 0;
}