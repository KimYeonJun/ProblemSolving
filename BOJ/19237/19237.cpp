/*
[BOJ] 19237번: 어른 상어
시작 시간 : 13시 30분
종료 시간 : 15시 06분
소요 시간 : 1시간 36분

문제 풀이
1. Shark 구조체를 사용해서 위치, 현재 방향, 방향 우선순위, die 유무를 저장.
2. Map 구조체를 사용해서 맵 좌표에 냄새를 뿌린 상어의 index, 냄새 시간, 칸에 존재하는 상어 list를 저장.
3. 로직 시작 전에 Input을 토대로 맵을 세팅한다.
4. Time이 1000이 될 떄 까지 로직 반복.
	4.1) 상어 이동
		4.1.1) 상어 이동 전에, 기존 상어가 존재하던 좌표 값에 대한 맵의 상어 list를 초기화한다.
		4.1.2) 상어가 현재 방향에 대한 우선순위 순서로 탐색하여 빈 좌표를 찾는다.
		4.1.3) 탐색 중에, 자신이 남긴 냄새를 발견한다면 임시로 저장해 놓는다.
		4.1.4) 만약, 4.1.2에서 빈 좌표를 찾았으면 그 좌표로 이동, 찾지 못했으면 자신이 남긴 냄새 좌표로 이동.
	4.2) 상어 죽이기
		4.2.1) Shark List에서 각 상어의 좌표에 2개 이상의 상어가 존재한다면
				가장 작은 상어의 index를 찾기 위해 정렬 후, 가장 작은 상어 외에 나머지 상어는 죽인다.
		4.2.2) 그 맵의 상어 list를 초기화하고, 가장 작은 상어의 index만 추가시킨다.
	4.3) 냄새 시간 감소
		맵에서 냄새가 존재하는 칸이 있으면 냄새의 시간을 1 감소시킨다.
	4.4) 냄새 뿌리기
		경쟁에서 승리한 상어들만 냄새를 뿌릴 수 있으므로 가장 마지막에 수행한다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Shark {
	int x;
	int y;
	int dir;
	int prioirty_dir[4][4];
	bool die = false;
};
struct Map {
	int idx;
	int cnt;
	vector<int> shark_list;
};
int N, M, K;
Map board[21][21];
int smell[21][21];
Shark shark_list[410];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
void Input() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j].idx;
			if (board[i][j].idx != 0) {
				int idx = board[i][j].idx;
				shark_list[idx].x = i;
				shark_list[idx].y = j;
				board[i][j].cnt = K;
				board[i][j].shark_list.push_back(idx);
			}
		}
	}
	int dir;
	for (int i = 1; i <= M; i++) {	
		cin >> dir;
		shark_list[i].dir = dir - 1;
	}
	for (int i = 1; i <= M; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				cin >> dir;
				shark_list[i].prioirty_dir[j][k] = dir - 1;
			}
		}
	}

}
void Spray_Smell() {
	for (int i = 1; i <= M; i++) {
		if (shark_list[i].die)
			continue;
		board[shark_list[i].x][shark_list[i].y].idx = i;
		board[shark_list[i].x][shark_list[i].y].cnt = K;
	}
}
void Print() {
	cout << "------------------------" << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << board[i][j].idx << "," << board[i][j].cnt << "  ";
		}
		cout << endl;
		cout << endl;
	}
	cout << "살아남은 상어 " << endl;
	for (int i = 1; i <= M; i++) {
		if (shark_list[i].die)
			continue;
		cout << i << " ";
	}
	cout << endl;
	cout << "------------------------" << endl;
}
void Move_Shark() {
	for (int i = 1; i <= M; i++) {
		if (shark_list[i].die)
			continue;
		board[shark_list[i].x][shark_list[i].y].shark_list.clear();
	}
	for (int i = 1; i <= M; i++) {
		Shark shark = shark_list[i];
		if (shark.die)
			continue;
		int x = shark.x;
		int y = shark.y;
		int dir = shark.dir;
		bool flag = false;
		int sx = -1, sy = -1, sdir = -1;
		for (int j = 0; j < 4; j++) {
			int ndir = shark.prioirty_dir[dir][j];
			int nx = x + dx[ndir];
			int ny = y + dy[ndir];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N)
				continue;
			if (board[nx][ny].cnt == 0) {
				shark.x = nx;
				shark.y = ny;
				shark.dir = ndir;
				shark_list[i] = shark;
				board[nx][ny].shark_list.push_back(i);
				flag = true;
				break;
			}
			else {
				if (board[nx][ny].idx == i) {
					if (sx == -1) {
						sx = nx;
						sy = ny;
						sdir = ndir;
					}
				}
			}
		}
		if (!flag) {
			shark_list[i].x = sx;
			shark_list[i].y = sy;
			shark_list[i].dir = sdir;
			board[sx][sy].shark_list.push_back(i);
		}
	}
}
void Kill_Shark() {
	for (int i = 1; i <= M; i++) {
		if (shark_list[i].die)
			continue;
		int x = shark_list[i].x;
		int y = shark_list[i].y;
		if (board[x][y].shark_list.size() >= 2) {
			sort(board[x][y].shark_list.begin(), board[x][y].shark_list.end());
			int win = board[x][y].shark_list[0];
			for (int j = 1; j < board[x][y].shark_list.size(); j++) {
				int idx = board[x][y].shark_list[j];
				shark_list[idx].die = true;
			}
			board[x][y].shark_list.clear();
			board[x][y].shark_list.push_back(win);
			board[x][y].idx = win;
		}
	}
}
void Time_Dec() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j].cnt > 0) {
				board[i][j].cnt--;
				if (board[i][j].cnt == 0)
					board[i][j].idx = 0;
			}
		}
	}
}
bool isFinish() {
	for (int i = 2; i <= M; i++) {
		if (!shark_list[i].die)
			return false;
	}
	return true;
}
void Solution() {
	int answer = 0;
	for (int t = 1; t <= 1001; t++) {
		//상어 이동하고
		Move_Shark();
		//상어 죽이기
		Kill_Shark();
		//냄새 시간 감소하고
		Time_Dec();
		//새로운 냄새 뿌리기
		Spray_Smell();
		//종료 검사
		if (isFinish()) {
			cout << t << endl;
			return;
		}
	}
	cout << "-1" << endl;
}
void Solve() {
	Input();
	Spray_Smell();
	Solution();
}
int main() {
	Solve();
	return 0;
}