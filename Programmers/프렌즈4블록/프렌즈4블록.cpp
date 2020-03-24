/*
string str = "aaaa";
str[0]==str[1]==str[2]==str[3]이 아닌
(str[0]==str[1]) && (str[1]==str[2]) && (str[2]==str[3]) 로 비교해야함.
*/
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
bool visit[35][35];
bool flag = true;
int answer = 0;
void searchDelete(vector<string>& board, int m, int n) {
    for (int i = m - 1; i >= 1; i--) {
        for (int j = 0; j < n - 1; j++) {
            if (board[i][j] == ' ')
                continue;
            if ((board[i][j] == board[i][j + 1]) && (board[i][j + 1] == board[i - 1][j]) && (board[i - 1][j] == board[i - 1][j + 1]))
            {
                flag = true;
                visit[i][j] = true;
                visit[i][j + 1] = true;
                visit[i - 1][j] = true;
                visit[i - 1][j + 1] = true;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (visit[i][j] == true) {
                board[i][j] = ' ';
                answer++;
            }
        }
    }
}
void gravity(vector<string>& board, int m, int n) {
    for (int i = 1; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == ' ')
                continue;
            for (int k = i - 1; k >= 0; k--) {
                if (board[k][j] == ' ') {
                    board[k][j] = board[k + 1][j];
                    board[k + 1][j] = ' ';
                }
            }
        }
    }
}
int solution(int m, int n, vector<string> board) {
    reverse(board.begin(), board.end());
    while (flag) {
        flag = false;
        memset(visit, 0, sizeof(visit));
        searchDelete(board, m, n);
        gravity(board, m, n);
    }


    return answer;
}