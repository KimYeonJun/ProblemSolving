/*
[BOJ] 17779번: 게리맨더링 2

문제 풀이
1. 문제의 조건에 맞는 x,y,d1,d2를 찾는다.
2. 1,2,3,4 구역을 나눈다
3. 5구역의 경계선을 구한다.
4. 5구역 내부를 구한다.
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int N;
int A[21][21];
int board[21][21];
int gu[5];
int answer = 987654321;
void Input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
		}
	}
}
void Print() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}
void getAnswer() {
	memset(gu, 0, sizeof(gu));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int idx = board[i][j];
			gu[idx-1] += A[i][j];
		}
	}
	sort(gu, gu + 5);
	answer = min(answer, (gu[4] - gu[0]));

}
void getArea(int x, int y, int d1, int d2) {
	for (int i = 1; i < x + d1; i++) {
		for (int j = 1; j <= y; j++) {
			board[i][j] = 1;
		}
	}
	for (int i = 1; i <= x + d2; i++) {
		for (int j = y + 1; j <= N; j++) {
			board[i][j] = 2;
		}
	}
	for (int i = x + d1; i <= N; i++) {
		for (int j = 1; j < y - d1 + d2; j++) {
			board[i][j] = 3;
		}
	}
	for (int i = x + d2 + 1; i <= N; i++) {
		for (int j = y - d1 + d2; j <= N; j++) {
			board[i][j] = 4;
		}
	}
	//5구역 구하기
	for (int i = 0; i <= d1; i++) {
		board[x + i][y - i] = 5;
		board[x + d2 + i][y + d2 - i] = 5;
	}
	for (int i = 0; i <= d2; i++) {
		board[x + i][y + i] = 5;
		board[x + d1 + i][y - d1 + i] = 5;
	}
	for (int i = x + 1; i < x + d1 + d2; i++) {
		bool flag = false;
		for (int j = 1; j <= N; j++) {
			if (board[i][j] == 5 && !flag)
				flag = true;
			else if (board[i][j] == 5 && flag)
				break;
			if (flag)
				board[i][j] = 5;
		}
	}
	getAnswer();
	
}
void Solution() {
	for (int x = 1; x <= N-1; x++) {
		for (int y = 2; y <= N-1; y++) {
			for (int d1 = 1; d1 <= N; d1++) {
				for (int d2 = 1; d2 <= N; d2++) {
					if ( x<x+d1 + d2&&x+d1+d2<=N && y - d1 >= 1 && y + d2 <= N) {
						memset(board, 0, sizeof(board));
						getArea(x, y, d1, d2);
					}
				}
			}
		}

	}
}
void Solve() {
	Input();
	Solution();
	cout<<answer<<endl;
}
int main() {
	Solve();
	return 0;
}