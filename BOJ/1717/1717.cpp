/*
BOJ 1717번: 집합의 표현
문제 유형 : 유니온파인드
*/
#include <iostream>
#define endl '\n'
using namespace std;
int parent[1000001];
int level[1000001];
int cmd[3];
int find(int u) {
	if (parent[u] == u)
		return u;
	return parent[u] = find(parent[u]);
}
void uni(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v)
		return;
	if (level[u] < level[v]) {
		parent[u] = v;
	}
	else
		parent[v] = u;
	if (level[u] == level[v])
		level[u]++;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		level[i] = 1;
	}
	for (int i = 0; i < m; i++) {
		cin >> cmd[0] >> cmd[1] >> cmd[2];
		if (cmd[0] == 0) { //union
			uni(cmd[1], cmd[2]);
		}
		else { //find
			int x = find(cmd[1]);
			int y = find(cmd[2]);
			if (x == y)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}
}