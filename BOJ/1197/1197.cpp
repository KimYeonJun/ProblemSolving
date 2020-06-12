/*
BOJ 1197��: �ּ� ���д� Ʈ��
���� ���� : �ּ� ���� Ʈ��(MST), ���Ͽ� ���ε� -> ũ�罺Į �˰���

ũ�罺Į �˰����� ����Ͽ� MST�� ���Ѵ�.
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct edge {
	int v1;
	int v2;
	int cost;
};
int V, E;
int parent[10001];
int level[10001];
vector<edge> edge_list;
int find(int x) {
	if (parent[x] == x)
		return x;
	return parent[x] = find(parent[x]);
}
bool uni(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v)
		return false;
	if (level[u] < level[v])
		parent[u] = v;
	else
		parent[v] = u;
	if (level[u] == level[v])
		level[u]++;
	return true;
}
bool cmp(edge& e1, edge& e2) {
	return e1.cost < e2.cost;
}
void Input() {
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		edge input;
		cin >> input.v1 >> input.v2 >> input.cost;
		edge_list.push_back(input);
	}
}
void Solution() {
	for (int i = 1; i <= V; i++) {
		parent[i] = i;
		level[i] = 1;
	}
	sort(edge_list.begin(), edge_list.end(), cmp);
	int cnt = 0;
	int result = 0;
	for (int i = 0; i < E; i++) {
		int v1 = edge_list[i].v1;
		int v2 = edge_list[i].v2;
		int cost = edge_list[i].cost;
		if (!uni(v1, v2))
			continue;
		cnt++;
		result += cost;
		if (cnt == V - 1)
			break;
	}
	cout << result << endl;
}
void Solve() {
	Input();
	Solution();
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Solve();
	return 0;
}