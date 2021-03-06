/*
[BOJ] 17143번: 낚시왕
시작 시간 : 20시 33분
종료 시간 : 21시 27분

문제 풀이
1. Input
	1.1) vector<int> board[][]에 존재하는 상어 index를 저장한다.
	1.2) shark_list[]에 입력받은 상어의 정보를 저장한다.
2. Fishing_Shark
	2.1) 각 칸에 무조건 상어가 1개 있음이 자명하니, 낚시꾼이 서있는 열에서 1번행~R번행까지 확인하면서 
		상어가 존재한다면 죽이고, 맵의 해당 좌표를 초기화.
3. Move_Shark
	3.0) 맵의 정보를 초기화 시킨다.(어차피 상어는 움직이므로)
	3.1) 상어가 움직이는 횟수를 최적화해준다.
		3.1.1) 방향이 위,아래라면 s = s % ((R-1)*2) 로 최적화
		3.1.2) 좌,우라면 s = s % ((C-1)*2)로 최적화
	3.2) 최적화된 횟수만큼 움직이고, 맵을 벗어난다면 방향 바꾸고 다시 움직인다.
4. Check_Kill
	4.1) 맵을 탐색하면서 2개 이상 상어가 있는 좌표를 찾는다.
	4.2) 상어의 크기 순으로 정렬하고, 0번 인덱스의 상어가 나머지를 잡아먹는다.
	4.3) 맵의 해당 좌표를 초기화하고, 0번 인덱스의 상어만 다시 추가.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Shark {
	int x;
	int y;
	int s;
	int d;
	int z;
	bool die=false;
};
Shark shark_list[10010];
vector<int> board[101][101];
int dx[5] = { 0,-1,1,0,0 };
int dy[5] = { 0,0,0,1,-1 };
int R, C, M;
int answer = 0;
bool cmp(int s1, int s2) {
	return shark_list[s1].z > shark_list[s2].z;
}
void Input() {
	cin >> R >> C >> M;
	for (int i = 0; i < M; i++) {
		cin >> shark_list[i].x >> shark_list[i].y >> shark_list[i].s >> shark_list[i].d >> shark_list[i].z;
		board[shark_list[i].x][shark_list[i].y].push_back(i);
	
	}
}
void Fishing_Shark(int idx) {
	for (int i = 1; i <= R; i++) {
		if (board[i][idx].size() == 0)
			continue;
		int num = board[i][idx][0];
		shark_list[num].die = true;
		answer += shark_list[num].z;
		board[i][idx].clear();
		return;
	}
}
int Change_Dir(int dir) {
	if (dir == 1)
		return 2;
	if (dir == 2)
		return 1;
	if (dir == 3)
		return 4;
	if (dir == 4)
		return 3;
}
void Move_Shark() {
	for (int i = 0; i < M; i++) { //맵 초기화
		if (shark_list[i].die)
			continue;
		board[shark_list[i].x][shark_list[i].y].clear();
	}
	for (int i = 0; i < M; i++) {
		if (shark_list[i].die)
			continue;
		int x = shark_list[i].x;
		int y = shark_list[i].y;
		int dir = shark_list[i].d;
		int s = shark_list[i].s;
		if (dir == 1 || dir == 2) { //움직임 최적화
			s = s % ((R - 1) * 2);
		}
		else {
			s = s % ((C - 1) * 2);
		}
		for (int j = 0; j < s; j++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx<1 || nx>R || ny<1 || ny>C) {
				dir = Change_Dir(dir);
				nx = x + dx[dir];
				ny = y + dy[dir];
			}
			x = nx; y = ny;
		}
		shark_list[i].x = x;
		shark_list[i].y = y;
		shark_list[i].d = dir;
		board[x][y].push_back(i);
		
	}
}
void Check_Kill() {
	for (int i = 0; i < M; i++) {
		if (shark_list[i].die)
			continue;
		int x = shark_list[i].x;
		int y = shark_list[i].y;
		if (board[x][y].size() >= 2) {
			sort(board[x][y].begin(), board[x][y].end(), cmp);
			int win = board[x][y][0];
			for (int j = 1; j < board[x][y].size(); j++) {
				int nxt = board[x][y][j];
				shark_list[nxt].die = true;
			}
			board[x][y].clear();
			board[x][y].push_back(win);
		}
	}
}
void Print() {
	cout << "--------------------------" << endl;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (board[i][j].size() > 0)
				cout << char(board[i][j][0]+'A') << " ";
			else
				cout << "0 ";
		}
		cout << endl;
	}
	cout << "--------------------------" << endl;
}
void Solution() {
	for (int i = 1; i <= C; i++) {
		//낚시왕이 가까운 상어 잡고
		Fishing_Shark(i);
		//상어 이동
		Move_Shark();
		//겹치는지 확인
		Check_Kill();
		//Print();
	}
	cout << answer << endl;
}
void Solve() {
	Input();
	Solution();
}
int main() {
	Solve();
	return 0;
}