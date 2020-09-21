/*
백준 1005번: ACM Craft
문제 유형 : 위상정렬 + DP

문제 풀이
1. indegree를 를 사용하여 위상정렬을 진행한다.
2. 위상정렬을 진행하면서, 정점 방문 시, 정점에 대한 최대 공사시간을 갱신한다.
	-> 동시에 짓기 시작한 건물이 모두 완성되어야 다음 건물이 지을 수 있어서
	-> DP적용
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
#define MOD 10007
using namespace std;
int N, K,W;
int arr[1001];
int indeg[1001];
int dp[1001];
vector<int> adj[1001];
void init() {
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i <= 1000; i++)
		adj[i].clear();

}
void topo_sort() {
	queue<int> que;
	for (int i = 1; i <= N; i++) {
		if (indeg[i] == 0) {
			que.push(i);
			dp[i] = arr[i];
		}
	}
	while (!que.empty()) {
		int cur = que.front();
		que.pop();
		for (int i = 0; i < adj[cur].size(); i++) {
			int nxt = adj[cur][i];
			dp[nxt] = max(dp[nxt], dp[cur] + arr[nxt]);
			if (--indeg[nxt] == 0)
				que.push(nxt);
		}
	}
	return;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		init();
		cin >> N >> K;
		for (int i = 1; i <= N; i++) {
			cin >> arr[i];
		}
		while (K--) {
			int X, Y;
			cin >> X >> Y;
			indeg[Y]++;
			adj[X].push_back(Y);
		}
		topo_sort();
		cin >> W;
		cout<< dp[W] << endl;
	}
	return 0;
}