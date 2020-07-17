/*
���α׷��ӽ�: Ÿ�� ��Ĺ�
���� ���� : DP, �Ǻ���ġ

������ �־��� ���� ���� �Ǻ���ġ ������ ���� �� �� �ִ�.
N��° �Ǻ���ġ ���� ���ϰ�, N��° ���� N-1��° ���� Ȱ���Ͽ� �ѷ��� ���� �� �ִ�.
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