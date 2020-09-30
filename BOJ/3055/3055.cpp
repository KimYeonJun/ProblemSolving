/*
BOJ 3055��: Ż��
���� ���� : BFS

���� Ǯ��
1. ���� Ȯ�忡 ���ؼ� BFS�� �����Ͽ�, �ʿ� ���� ���� �������� ǥ���Ѵ�.
2. ����ġ�� �̵��� ���ؼ� BFS�� ����
	-> �̵� ��, �ش� ĭ�� �� ���� ���� �����ߴ��� Ȯ��
	-> ���� ����������, �� ĭ���� �̵�.
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
#define MAX 1000001
#define MOD 1000000000
using namespace std;
struct loc {
	int x;
	int y;
	int t;
};
int R, C;
char board[51][51];
bool visit[51][51];
int visit_water[51][51];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int sx, sy, ex, ey;
vector<pair<int, int>> water_list;
void BFS_water() {
	queue<loc> que;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++)
			visit_water[i][j] = INF;
	}
	for (int i = 0; i < water_list.size(); i++) {
		int x = water_list[i].first;
		int y = water_list[i].second;
		que.push({ x,y,0 });
		visit_water[x][y] = 0;
	}
	while (!que.empty()) {
		loc cur = que.front();
		que.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];
			int nt = cur.t + 1;
			if (nx < 0 || nx >= R || ny < 0 || ny >= C || visit_water[nx][ny] !=INF ||
				board[nx][ny] == 'X' || board[nx][ny] == 'D')
				continue;
			visit_water[nx][ny] = nt;
			que.push(loc{ nx,ny,nt });
		}
	}
}
int BFS_hed() {
	queue<loc> que;
	que.push(loc{ sx,sy,0 });
	visit[sx][sy] = true;
	while (!que.empty()) {
		loc cur = que.front();
		//cout << cur.x << " " << cur.y << endl;
		que.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];
			int nt = cur.t + 1;
			if (nx < 0 || nx >= R || ny < 0 || ny >= C  ||
				board[nx][ny] == 'X'||visit[nx][ny])
				continue;
			if (board[nx][ny] == 'D')
				return nt;
			if (visit_water[nx][ny]<= nt)
				continue;
			visit[nx][ny] = true;
			que.push(loc{ nx,ny,nt });
		}
	}
	return -1;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}