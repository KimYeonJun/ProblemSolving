/*
[BOJ] 10844��: ���� ��� ��
���� ���� : DP

N=2 �� ���
���� �ڸ��� 0�� ��� �տ� 1�� �� �� ����
���� �ڸ��� 1�� ��� �տ� 0,2�� �� �� ����
���� �ڸ��� 2�� ��� �տ� 1,3�� �� �� ����
....
���� �ڸ��� 9�� ��� �տ� 8�� �� �� ����

��,
dp[n][0] = dp[n-1][0]
dp[n][1..8] = dp[n-1][i-1]  + dp[n-1][i+1]
dp[n][9] = dp[n-1][8]
�̶�� ��ȭ���� ���� �� �ִ�.
*/
#include <stdio.h>
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
long long dp[101][10];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	for (int i = 1; i <= 9; i++)
		dp[1][i] = 1;
	for (int i = 2; i <= N; i++) {
		dp[i][0] = dp[i - 1][1];
		for (int j = 1; j <= 8; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1])%MOD;
		}
		dp[i][9] = dp[i - 1][8];
	}
	long long answer = 0;
	for (int i = 0; i <= 9; i++) {
		answer += dp[N][i] % MOD;
	}
	cout << answer%MOD << endl;

}