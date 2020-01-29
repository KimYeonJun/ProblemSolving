#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

int N, M, V;
vector<vector<int>> graph;
bool check[1001];
void input() {
	cin >> N >> M >> V;
	graph.resize(N+1);
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for (int i = 1; i <= N; i++) {
		sort(graph[i].begin(), graph[i].end());
	}
}
void DFS(int start) {
	check[start] = true;
	cout << start << " ";
	for (int i = 0; i < graph[start].size(); i++) {
		int next = graph[start][i];
		if (check[next] == false) {
			DFS(next);
		}
	}
}
void BFS() {
	queue<int> que;
	que.push(V);
	check[V] = true;
	while (!que.empty()) {
		int t = que.front();
		que.pop();
		cout << t << " ";
		for (int i = 0; i < graph[t].size(); i++) {
			int next = graph[t][i];
			if (check[graph[t][i]] == false) {
				check[graph[t][i]] = true;
				que.push(graph[t][i]);
			}
		}
	}
}
void solve() {
	input();
	DFS(V);
	memset(check, 0, sizeof(check));
	cout << endl;
	BFS();

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();


	return 0;
}