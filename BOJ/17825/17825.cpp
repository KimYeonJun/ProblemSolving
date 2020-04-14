/*
BOJ 17825: 주사위 윷놀이
문제 유형 : 시뮬레이션

같은 위치에 말이 존재하는 지 확인하는 부분이 굉장히 어려웠음.

그냥 너무 어려웠음 꼭 다시 풀어보기
*/
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

vector<vector<int>> board{ {2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,-2},
							{10,13,16,19,25,30,35,40,-2},
							{20,22,24,25,30,35,40,-2},
							{30,28,27,26,25,30,35,40,-2}};
int boardlen[4] = { 20,8,7,8 };
vector<int> cmd(10);

int visit[11];
int result = 0;
bool done[4];
void Input() {
	for (int i = 0; i < 10; i++) {
		cin >> cmd[i];
	}
}

void play() {
	int answer = 0;
	vector<pair<int, int>> players{ {0, -1}, { 0,-1 }, { 0,-1 }, {0,-1} };
	memset(done, false, sizeof(done));
	for (int i = 0; i < 10; i++) {
		int player = visit[i];
		//cout << "플레이어: " << player << endl;
		if (done[player])
			return;
		for (int j = 0; j < cmd[i]; j++) {
			players[player].second++;
			if (board[players[player].first][players[player].second] == -2) { //도착
				done[player] = true;
				break;
			}

		}
		if (done[player])
			continue;
		answer += board[players[player].first][players[player].second];
		if (players[player].first == 0) {
			if (players[player].second == 4) {
				players[player].first = 1;
				players[player].second = 0;
			}
			else if (players[player].second == 9) {
				players[player].first = 2;
				players[player].second = 0;
			}
			else if (players[player].second == 14) {
				players[player].first = 3;
				players[player].second = 0;
			}
		}
		
		for (int j = 0; j < 4; j++) { //같은 위치에 말이 있는지 확인
			if (j == player)
				continue;
			if (done[j])
				continue;
			if (players[j].second == -1)
				continue;
			if (board[players[player].first][players[player].second] == board[players[j].first][players[j].second]) {
				if (players[player].first == players[j].first && players[player].second == players[j].second)
					return;
				else {
					if (boardlen[players[player].first] - 4 <= players[player].second && boardlen[players[j].first] - 4 <= players[j].second) {
						return;
					}
				}
			}
		}
	}
	result = max(result, answer);
}
void DFS(int cnt) {
	if (cnt == 10) {
		play();
		return;
	}
	for (int i = 0; i < 4; i++) {
		visit[cnt] = i;
		DFS(cnt + 1);
	}
}
void Solution() {
	DFS(0);
	cout << result << endl;
}
void Solve() {
	Input();
	Solution();
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Solve();
	return 0;
}