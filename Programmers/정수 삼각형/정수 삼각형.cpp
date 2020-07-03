/*
프로그래머스 : 정수 삼각형
문제 유형 : DP

문제 풀이
1. 아래 노드로 내려갈 때(왼쪽, 오른쪽 2가지만), 기존의 값과 현재 노드와 아래 노드의 합을 비교하여 최대값을 갱신한다.

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