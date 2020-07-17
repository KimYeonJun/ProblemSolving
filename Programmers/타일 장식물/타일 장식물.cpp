/*
프로그래머스: 타일 장식물
문제 유형 : DP, 피보나치

문제에 주어진 수를 보면 피보나치 수열인 것을 알 수 있다.
N번째 피보나치 수를 구하고, N번째 수와 N-1번째 수를 활용하여 둘레를 구할 수 있다.
*/
#include <string>
#include <vector>

using namespace std;
long long dp[81];
long long dp2[81];
long long solution(int N) {
    long long answer = 0;
    dp[0] = 0;
    dp[1] = 1;
    if (N == 1) {
        return 4;
    }
    else {
        for (int i = 2; i <= N; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
    }
    answer = (dp[N] + dp[N - 1]) * 2 + dp[N] * 2;
    return answer;
}