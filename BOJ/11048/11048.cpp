/*
BOJ 11048: �̵��ϱ�

DFS�� Ǯ���ٰ� �ð��ʰ�, N�� M�� ������ 1000�̶�.
->DP�� Ǯ�� ����

DP[i][j] = DP[i-1][j-1],DP[i-1][j],DP[i][j-1] �� �ִ� + �ڱ� �ڽ��� ��

*/
#include <iostream>
#include <algorithm>
using namespace std;
int N, M;
int map[1001][1001];
int dp[1001][1001];
int dx[3] = {1,0,1};
int dy[3] = { 0,1,1 };
int result = 0;
void Input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}
}

void Solution() {
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			dp[i][j] = max(max(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]) + map[i][j];
		}
	}
	cout << dp[N][M] << endl;
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