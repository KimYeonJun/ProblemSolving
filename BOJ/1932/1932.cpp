/*
BOJ 1932��: ���� �ﰢ��
���� ���� : DP

���� Ǯ��: ���� ������ �Ʒ� ������ ������ ����, ������ �Ʒ� ���� ������ ũ�ٸ� ���Ž����ش�.
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
#define MAX 100001
using namespace std;
int arr[501][501];
int dp[501][501];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> arr[i][j];
		}
	}
	dp[0][0] = arr[0][0];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + arr[i+1][j]);
			dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + arr[i + 1][j + 1]);
		}
	}
	int answer = 0;
	for (int i = 0; i < N; i++) {
		answer = max(answer, dp[N - 1][i]);
	}
	cout << answer << endl;
}