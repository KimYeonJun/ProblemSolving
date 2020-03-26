/*
BOJ 1018�� : ü���� �ٽ� ĥ�ϱ�
���� ���� : �ùķ��̼�
���� Ǯ�� : 1. 8x8�� �߶�� �ϹǷ� �ݺ����� 0 <= N-8 , 0 <= M-8 �� �ݺ��Ѵ�
			2. ���� ���� ����� ��� �ٽ� ĥ�ؾ� �ϴ� ���簢���� ������ ���Ѵ�
			3. ���� ���� ������ �� ��� �ٽ� ĥ�ؾ� �ϴ� ���簢�� ������ ���Ѵ�.
			4. 2,3�� ����� �ּҰ��� ������� ����.

getWhite()�� getBlack()��  
���ÿ� �����Ѱ� getAnswer()�̴�.
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

char board[50][50];
int N, M;
int answer = 987654321;
void Input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < M; j++) {
			board[i][j] = input[j];
		}
	}
}
void getWhite(int x, int y) {
	int cnt = 0;
	for (int i = x; i < x + 8; i++) {
		for (int j = y; j < y + 8; j++) {
			if ((i + j) % 2 == 0) {
				if (board[i][j] != 'W')
					cnt++;
			}
			else {
				if (board[i][j] != 'B')
					cnt++;
			}
		}
	}
	if (answer > cnt)
		answer = cnt;
}
void getBlack(int x, int y) {
	int cnt = 0;
	for (int i = x; i < x + 8; i++) {
		for (int j = y; j < y + 8; j++) {
			if ((i + j) % 2 == 0) {
				if (board[i][j] != 'B')
					cnt++;
			}
			else {
				if (board[i][j] != 'W')
					cnt++;
			}
		}
	}
	if (answer > cnt)
		answer = cnt;
}
void getAnswer(int x, int y) {
	int whiteCnt = 0;
	int blackCnt = 0;
	for (int i = x; i < x + 8; i++) {
		for (int j = y; j < y + 8; j++) {
			if ((i + j) % 2 == 0) {
				if (board[i][j] != 'B')
					blackCnt++;
				else
					whiteCnt++;
			}
			else {
				if (board[i][j] != 'W')
					blackCnt++;
				else
					whiteCnt++;
			}
		}
	}
	answer = min(min(blackCnt, whiteCnt), answer);
}
void Solution() {
	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			//cout << i << " " << j << endl;
			//getWhite(i,j);
			//getBlack(i,j);
			getAnswer(i, j);
		}
	}
	cout << answer << endl;
}
void Solve() {
	Input();
	Solution();
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	Solve();
	return 0;
}