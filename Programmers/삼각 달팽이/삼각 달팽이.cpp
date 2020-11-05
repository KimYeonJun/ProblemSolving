/*
[Programmers] �ﰢ ������
���� ���� : ����

���� Ǯ��
1. 3���� case�� ������
    1.1) ���� ������ �Ʒ��� �����̰� �����̴� ���
    1.2) ���������� �����̰� �����̴� ���
    1.3) ������ ������ ���� �����̰� �����̴� ���
2. �� case�� ���� ���ǹ��� ���� ���ڸ� ä���.


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