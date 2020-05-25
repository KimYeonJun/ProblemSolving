/*
BOJ 2252번: 줄 세우기
문제 유형 : 위상정렬

위상정렬 기본 문제.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M;
int indeg[32001];
vector<int> adj[32001];

void topo_sort() {
	queue<int> que;
	vector<int> result;
	for (int i = 1; i <= N; i++) {
		if (indeg[i] == 0)
			que.push(i);
	}
	while (!que.empty()) {
		int cur = que.front();
		que.pop();
		result.push_back(cur);
		for (int i = 0; i < adj[cur].size(); i++) {
			int next = adj[cur][i];
			indeg[next]--;
			if (indeg[next] == 0)
				que.push(next);
		}
	}
	if (result.size() != N) {
		return;
	}
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << " ";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	//input
	while (M--) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		indeg[b]++;
	}
	topo_sort();
}