/*
BOJ 1976번: 여행 가자
문제 유형 : 유니온파인드
*/
#include <iostream>
#define endl '\n'
using namespace std;
int parent[201];
int level[201];

int find(int u) {
	if (u == parent[u])
		return u;
	return parent[u] = find(parent[u]);
}
void uni(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v)
		return;
	if (level[u] < level[v])
		parent[u] = v;
	else
		parent[v] = u;
	if (level[u] == level[v])
		level[u]++;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	cin >> N >> M;
	int input;
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
		level[i] = 1;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> input;
			if (input == 1) {
				uni(i, j);
			}
		}
	}
	cin >> input;
	int val = find(input);
	for (int i = 0; i < M - 1; i++) {
		cin >> input;
		if (val != find(input)) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
}