/*
BOJ 4811��: �˾�
���� ���� : dp+���

�ߺ� �湮 ������ ���� dp�� ����Ѵ�.
����� �б�� 2���� �����ϴ�.
	1. w-1,h+1
	2. w,h-1
�� �ΰ����� ���� ���ϸ鼭 ���� �����ذ���.
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
int N;
long long dp[31][31];
/*long long DFS(int W, int H) {
	if (W == 0 && H == 0) {
		return 1;
	}
	if (dp[W][H] != 0)
		return dp[W][H];
	if (W > 0) {
		dp[W][H] += DFS(W - 1, H+1);
	}
	if (H > 0) {
		dp[W][H] += DFS(W, H - 1);
	}
	return dp[W][H];
}*/
long long DFS(int w, int h) {
	if (w < 0 || h < 0)
		return 0;
	if (w == 0)
		return 1;
	if (dp[w][h])
		return dp[w][h];
	return dp[w][h] = DFS(w, h - 1) + DFS(w - 1, h + 1);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	DFS(30, 0);
	while (1) {
		cin >> N;
		if (N == 0)
			break;
		cout << dp[N][0] << endl;
	}
}