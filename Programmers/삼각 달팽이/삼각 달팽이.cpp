/*
[Programmers] 삼각 달팽이
문제 유형 : 구현

문제 풀이
1. 3가지 case로 나눈다
    1.1) 왼쪽 변에서 아래로 달팽이가 움직이는 경우
    1.2) 오른쪽으로 달팽이가 움직이는 경우
    1.3) 오른쪽 변에서 위로 달팽이가 움직이는 경우
2. 각 case에 대한 조건문을 통해 숫자를 채운다.


*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;
int board[1001][1001];
int cnt = 1;
vector<int> solution(int N) {
    vector<int> answer;
    int cnt = 1;
    int x = -1, y = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            if (i % 3 == 0) {
                x++;
            }
            else if (i % 3 == 1) {
                y++;
            }
            else if (i % 3 == 2) {
                x--; y--;
            }
            board[x][y] = cnt++;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++)
            answer.push_back(board[i][j]);
    }
    return answer;
}