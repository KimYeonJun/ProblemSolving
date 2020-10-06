/*
BOJ 2580번: 스도쿠
문제 유형 : 백트랙킹

row[a][b]=true의 의미는 a번째 가로줄에 b라는 값이 존재한다.
col[a][b]=true의 의미는 a번째 세로줄에 b라는 값이 존재한다.
square[a][b]=true의 의미는
0 1 2
3 4 5    로 구역을 정하고, a번째 구역에 b라는 값이 존재한다.
6 7 8

DFS로 탐색하여, 0인 좌표에 대해서 1~9까지 대입해본다.
row,col,square 3가지 조건을 모두 충족하면, 다음 인덱스를 탐색한다.
이때, 충족한 값이 확정 값이 아니기 때문에 백트랙킹 후 복귀할때 값을 해제시켜줘야한다.

*/
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <math.h>
#include <sstream>
#include <unordered_map>
#define endl '\n'
#define INF 987654321
#define MAX 100000000
#define MOD 1000000000
using namespace std;
int board[10][10];
bool row[10][10];
bool col[10][10];
bool square[10][10];
void DFS(int idx) {
	if (idx == 81) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << board[i][j] << " ";
			}
			cout << endl;
		}
		exit(0);
	}
	int x = idx / 9;
	int y = idx % 9;
	int sq = (x / 3) * 3 + y / 3;
	if (board[x][y] == 0) {
		for (int i = 1; i <= 9; i++) {
			if (row[x][i] || col[y][i] || square[sq][i])
				continue;
			row[x][i] = true;
			col[y][i] = true;
			square[sq][i] = true;
			board[x][y] = i;
			DFS(idx + 1);
			board[x][y] = 0;
			square[sq][i] = false;
			col[y][i] = false;
			row[x][i] = false;
		}
	}
	else {
		DFS(idx + 1);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> board[i][j];
			if (board[i][j] != 0) {
				int idx = (i / 3) * 3 + j / 3;
				int num = board[i][j];
				row[i][num] = true;
				col[j][num] = true;
				square[idx][num] = true;
			}
		}
	}
	DFS(0);
	return 0;
}