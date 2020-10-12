/*
[BOJ] 17427번: 다리 만들기 2

문제 풀이
1. Labeling
	1.1) BFS를 사용하여 각 섬에 번호를 부여
	1.2) 같은 번호를 가진 섬의 좌표들을 island_pos에 저장.
2. Connect_Island
	2.1) 두 개의 섬을 선택한다.
3. Make_Bridge
	3.1) 시작 섬의 모든 좌표들로 부터 도착 섬 까지 DFS 탐색
	3.2) 도착 섬에 도달했고, 다리의 길이가 1보다 크면 edge_list에 간선 추가
4. Kruskal
	4.1) 크루스칼 알고리즘을 사용하여 최소신장트리(Mst)를 구성
	4.2) Union-Find알고리즘을 사용하여 같은 그룹인지 체크
	4.3) 같은 그룹이 아니라면 그룹화 해주고 정답 비용에 추가
*/
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
struct Edge {
	int v1;
	int v2;
	int cost;
};
int N, M;
int board[15][15];
int label[15][15];
bool visit[15][15];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int island_cnt = 1;
vector<Edge> edge_list;
vector<pair<int, int>> island_pos[7];
int parent[7];
bool cmp(Edge& e1, Edge& e2) {
	return e1.cost < e2.cost;
}
void Input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}
}
void BFS(int x,int y,int idx) {
	queue<pair<int, int>> que;
	que.push(make_pair(x, y));
	visit[x][y] = true;
	label[x][y] = idx;
	island_pos[idx].push_back({ x,y });
	while (!que.empty()) {
		auto cur = que.front();
		que.pop();
		int x = cur.first;
		int y = cur.second;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M || visit[nx][ny] || board[nx][ny] == 0)
				continue;
			visit[nx][ny] = true;
			label[nx][ny] = idx;
			island_pos[idx].push_back({ nx,ny });
			que.push({ nx,ny });
		}
	}
	return;
}
void Labeling() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visit[i][j] || board[i][j] == 0)
				continue;
			BFS(i, j, island_cnt);
			island_cnt++;
		}
	}
}
void DFS(int x, int y, int dir, int len, int start, int end) {
	int nx = x + dx[dir];
	int ny = y + dy[dir];
	if (nx < 0 || nx >= N || ny < 0 || ny >= M)
		return;
	if (board[nx][ny] == 0)
		DFS(nx, ny, dir, len + 1, start, end);
	else {
		if (label[nx][ny] == end) {
			if(len>1)
				edge_list.push_back(Edge{ start,end,len });
		}
	}
	return;
}
void Make_Bridge(int start, int end) {
	for (int i = 0; i < island_pos[start].size(); i++) {
		int x = island_pos[start][i].first;
		int y = island_pos[start][i].second;
		for (int j = 0; j < 4; j++) {
			int nx = x + dx[j];
			int ny = y + dy[j];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M || board[nx][ny] != 0)
				continue;
			DFS(nx, ny, j, 1, start, end);
		}
	}
}
void Connect_Island() {
	for (int i = 1; i < island_cnt; i++) {
		for (int j = i + 1; j < island_cnt; j++) {
			Make_Bridge(i, j);
		}
	}
}
int find(int u) {
	if (parent[u] == u)
		return u;
	return parent[u] = find(parent[u]);
}
bool uni(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v)
		return false;
	parent[u] = v;
	return true;
}
int Kruskal() {
	sort(edge_list.begin(), edge_list.end(), cmp);
	for (int i = 1; i < island_cnt; i++) {
		parent[i] = i;
	}
	int cnt = 1;
	int answer = 0;
	for (int i = 0; i < edge_list.size(); i++) {
		int v1 = edge_list[i].v1;
		int v2 = edge_list[i].v2;
		int cost = edge_list[i].cost;
		if (!uni(v1, v2))
			continue;
		answer += cost;
		if (++cnt == island_cnt-1) {
			break;
		}
	}
	if (cnt != island_cnt-1)
		answer = -1;
	return answer;
}
void Solve() {
	Input();
	Labeling();
	Connect_Island();
	cout << Kruskal() << endl;
}
int main() {
	Solve();
	return 0;
}