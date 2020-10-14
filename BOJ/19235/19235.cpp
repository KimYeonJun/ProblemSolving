/*
[BOJ] 19235번: 모노미노도미노

문제 풀이
1. Input
	1.1) Green과 Blue를 따로 저장
	1.2) Green의 경우 1*2타일 저장 시, (2,0)으로 저장. 
		-> 블록 이동할때 왼쪽만 확인하면 된다.
	1.3) Blue의 경우 2*1 타일 저장 시, (3,0)으로 저장.
		-> 블록 이동할때 위만 확인하면 된다.

*/
#include <iostream>

using namespace std;
int N;
int green_board[6][4];
int blue_board[4][6];
int answer = 0;
void Print() {
	cout << "------------Green Board----------------" << endl;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			cout << green_board[i][j] << " ";
		}
		cout << endl;
	}
	cout << "------------Blue Board----------------" << endl;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 6; j++) {
			cout << blue_board[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
void Gravity_Green() {
	for (int i = 4; i >= 0; i--) {
		for (int j = 0; j < 4; j++) {
			if (green_board[i][j] == 0)
				continue;
			if (green_board[i][j] == 2) { // 1*2
				for (int k = i + 1; k <= 5; k++) {
					if (green_board[k][j] == 0 && green_board[k][j + 1] == 0) {
						if (j > 0 && green_board[k][j - 1] == 2)
							break;
						green_board[k][j] = green_board[k - 1][j];
						green_board[k - 1][j] = 0;
					}
					else
						break;
				}
			}
			else {
				for (int k = i + 1; k <= 5; k++) {
					if (green_board[k][j] == 0) {
						if (j > 0 && green_board[k][j - 1] == 2)
							break;
						green_board[k][j] = green_board[k - 1][j];
						green_board[k - 1][j] = 0;
					}
					else
						break;
				}
			}
		}
	}
}
bool isGreenFull() {
	bool flag = false;
	for (int i = 5; i >= 0; i--) {
		int cnt = 0;
		for (int j = 0; j < 4; j++) {
			if (green_board[i][j] == 3)
				cnt += 1;
			else
				cnt += green_board[i][j];
		}
		if (cnt == 4) {
			for (int j = 0; j < 4; j++)
				green_board[i][j] = 0;
			flag = true;
			answer++;
		}
	}
	return flag;
}
bool Magic_Green() {
	int cnt = 0;
	for (int i = 0; i <= 1; i++) {
		for (int j = 0; j < 4; j++) {
			if (green_board[i][j] > 0) {
				cnt++;
				break;
			}
		}
	}
	if (cnt == 0)
		return false;
	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < 4; j++) {
			green_board[5 - i][j] = 0;
		}
	}
	return true;
}
void Move_Green() {
	Gravity_Green();
	while (isGreenFull()) {
		Gravity_Green();
	}
	if (Magic_Green()) {
		Gravity_Green();
	}
}
void Gravity_Blue() {
	for (int i = 4; i >= 0; i--) {
		for (int j = 0; j < 4; j++) {
			if (blue_board[j][i] == 0)
				continue;
			if (blue_board[j][i] == 3) { // 2*1
				for (int k = i + 1; k <= 5; k++) {
					if (blue_board[j][k] == 0 && blue_board[j+1][k] == 0) {
						if (j > 0 && blue_board[j-1][k] == 3)
							break;
						blue_board[j][k] = blue_board[j][k-1];
						blue_board[j][k-1] = 0;
					}
					else
						break;
				}
			}
			else {
				for (int k = i + 1; k <= 5; k++) {
					if (blue_board[j][k] == 0) {
						if (j > 0 && blue_board[j-1][k] == 3)
							break;
						blue_board[j][k] = blue_board[j][k-1];
						blue_board[j][k-1] = 0;
					}
					else
						break;
				}
			}
		}
	}

}
bool isBlueFull() {
	bool flag = false;
	for (int i = 5; i >= 0; i--) {
		int cnt = 0;
		for (int j = 0; j < 4; j++) {
			if (blue_board[j][i] == 0)
				continue;
			if (blue_board[j][i] == 3)
				cnt += 2;
			else
				cnt += 1;
		}
		if (cnt == 4) {
			for (int j = 0; j < 4; j++)
				blue_board[j][i] = 0;
			flag = true;
			answer++;
		}
	}
	return flag;
}
bool Magic_Blue() {
	int cnt = 0;
	for (int i = 0; i <= 1; i++) {
		for (int j = 0; j < 4; j++) {
			if (blue_board[j][i] > 0) {
				cnt++;
				break;
			}
		}
	}
	if (cnt == 0)
		return false;
	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < 4; j++) {
			blue_board[j][5 - i] = 0;
		}
	}
	return true;
}
void Move_Blue() {
	Gravity_Blue();
	while (isBlueFull()) {
		Gravity_Blue();
	}
	if (Magic_Blue()) {
		Gravity_Blue();
	}
}
void getAnswer() {
	int cnt = 0;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			if (green_board[i][j] == 0)
				continue;
			if (green_board[i][j] == 2)
				cnt += 2;
			else
				cnt += 1;
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 6; j++) {
			if (blue_board[i][j] == 0)
				continue;
			if (blue_board[i][j] == 3)
				cnt += 2;
			else
				cnt += 1;
		}
	}
	cout << answer << endl;
	cout << cnt << endl;
}
void Solve() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int t, x, y;
		cin >> t >> x >> y;
		if (t == 1) {
			green_board[0][y] = 1;
			blue_board[x][0] = 1;
		}
		else if (t == 2) {
			green_board[0][y] = 2;
			blue_board[x][0] = 2;
			blue_board[x][1] = 2;
		}
		else if (t == 3) {
			green_board[0][y] = 3;
			green_board[1][y] = 3;
			blue_board[x][0] = 3;
		}
		Move_Green();
		Move_Blue();
	}
	getAnswer();
}
int main() {
	Solve();
	return 0;
}