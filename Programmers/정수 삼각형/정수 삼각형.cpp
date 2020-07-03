/*
���α׷��ӽ� : ���� �ﰢ��
���� ���� : DP

���� Ǯ��
1. �Ʒ� ���� ������ ��(����, ������ 2������), ������ ���� ���� ���� �Ʒ� ����� ���� ���Ͽ� �ִ밪�� �����Ѵ�.

*/
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int dp[501][501];
int solution(vector<vector<int>> triangle) {
    int answer = 0;
    dp[0][0] = triangle[0][0];
    int N = triangle.size();

    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j <= i; j++) {
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + triangle[i + 1][j]);
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + triangle[i + 1][j + 1]);
        }
    }
    for (int i = 0; i < triangle[N - 1].size(); i++) {
        answer = max(answer, dp[N - 1][i]);
    }
    return answer;
}