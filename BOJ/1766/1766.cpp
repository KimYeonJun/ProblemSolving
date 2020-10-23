/*
[BOJ] 1766�� : ������
���� ���� : ��������, �켱���� ť

�⺻���� �������Ŀ� �켱���� ť�� ������ �����̴�.
������ ���� �߿� �����ϸ� ���� �������� Ǯ��� �Ѵٴ� ������ �����ϱ� ����
Indegree�� 0�� �������� �켱���� ť�� �ִ´�.
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
#define MAX 100000000
#define MOD 1000000000
using namespace std;
int indeg[32001];
vector<int> adj[32001];
int N, M;
void Input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		indeg[b]++;
		adj[a].push_back(b);
	}
}
void Topo_Sort() {
	priority_queue<int, vector<int>, greater<int>> pq;
	vector<int> answer;
	for (int i = 1; i <= N; i++) {
		if (indeg[i] == 0)
			pq.push(i);
	}
	while (!pq.empty()) {
		int cur = pq.top();
		pq.pop();
		answer.push_back(cur);
		for (int i = 0; i < adj[cur].size(); i++) {
			int nxt = adj[cur][i];
			if (--indeg[nxt] == 0) {
				pq.push(nxt);
			}
		}
	}
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << " ";
	return;
}
void Solve() {
	Input();
	Topo_Sort();
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Solve();
	return 0;
}