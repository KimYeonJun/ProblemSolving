/*
프로그래머스 : 땅따먹기
문제유형 : DP

*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[100000][4];
int solution(vector<vector<int> > land)
{
    int answer = 0;
    int N = land.size();
    int M = land[0].size();
    for (int i = 0; i < 4; i++) {
        arr[0][i] = land[0][i];
    }
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < M; j++) {
            arr[i][j] = max(max(arr[i - 1][(j + 1) % 4], arr[i - 1][(j + 2) % 4]), arr[i - 1][(j + 3) % 4]) + land[i][j];
        }
    }
    for (int i = 0; i < 4; i++) {
        answer = max(answer, arr[N - 1][i]);
    }

    return answer;
}