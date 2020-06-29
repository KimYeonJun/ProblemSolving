/*
프로그래머스 : 가장 큰 정사각형 찾기
문제 유형 : DP
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int board[1001][1001];
int solution(vector<vector<int>> board)
{
    int answer = board[0][0];
    for (int i = 1; i < board.size(); i++) {
        for (int j = 1; j < board[i].size(); j++) {
            if (board[i][j] != 1)
                continue;
            board[i][j] = min(min(board[i - 1][j], board[i][j - 1]), board[i - 1][j - 1]) + 1;
            answer = max(answer, board[i][j]);
        }
    }
    return answer * answer;
}