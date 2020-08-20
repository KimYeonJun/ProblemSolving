/*
프로그래머스: 등굣길
문제 유형 : dp

부분 합을 구하는 과정에서 int범위를 초과할 수 있으므로 % MOD 연산을 해야함.
*/
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;
int MOD = 1000000007;
int dp[101][101];
int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    //n,m 도달
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < puddles.size(); i++) {
        dp[puddles[i][1]][puddles[i][0]] = -1;
    }
    dp[1][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (dp[i][j] == -1) {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] += (dp[i - 1][j] + dp[i][j - 1]) % MOD;
        }
    }
    answer = dp[n][m] % MOD;
    return answer;
}