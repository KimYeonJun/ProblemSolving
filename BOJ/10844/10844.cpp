/*
[BOJ] 10844번: 쉬운 계단 수
문제 유형 : DP

N=2 인 경우
일의 자리가 0인 경우 앞에 1이 올 수 있음
일의 자리가 1인 경우 앞에 0,2가 올 수 있음
일의 자리가 2인 경우 앞에 1,3이 올 수 있음
....
일의 자리가 9인 경우 앞에 8이 올 수 있음

즉,
dp[n][0] = dp[n-1][0]
dp[n][1..8] = dp[n-1][i-1]  + dp[n-1][i+1]
dp[n][9] = dp[n-1][8]
이라는 점화식을 구할 수 있다.
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