/*
���� 1005��: ACM Craft
���� ���� : �������� + DP

���� Ǯ��
1. indegree�� �� ����Ͽ� ���������� �����Ѵ�.
2. ���������� �����ϸ鼭, ���� �湮 ��, ������ ���� �ִ� ����ð��� �����Ѵ�.
	-> ���ÿ� ���� ������ �ǹ��� ��� �ϼ��Ǿ�� ���� �ǹ��� ���� �� �־
	-> DP����
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