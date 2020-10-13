///*
//[BO] 17837번: 새로운 게임 2
//
//시작 시간 : 11시 50분
//종료 시간 : 12시 50분
//소요 시간 : 1시간
//
//문제 풀이
//1. Input()
//	1.1) board에는 체스판의 색, chess_board에는 각 칸에 올라가 있는 말의 index들을 저장.
//2. Move_Horse()
//	2.1) 각 말을 이동시킨다.
//	2,2) 다음 칸이 파란색이면, 방향을 전환하고 다시 이동하려는 칸이 파란색이 아니라면 이동한다.
//	2.3) 다음 칸이 흰색, 빨간색이면 이동.
//	2.4) 한개의 말의 이동이 끝날때마다, 이동 후 위치의 칸에 말이 4개 이상인지 확인.
//3. Move()
//	3.1) 해당 칸에 위에 있는 말 중에서, 움직일 말의 index를 찾는다.
//	3.2) 만약 그 칸이 빨간색이라면 , 찾은 index부터 마지막까지 순서를 바꿔줌.
//	3.3) index부터 마지막까지의 말을 이동시킨다.
//*/
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//struct Horse {
//	int x;
//	int y;
//	int dir;
//};
//int N, K;
//int board[15][15];
//vector<int> chess_board[15][15];
//Horse horse_list[15];
//int dx[4] = { 0,0,-1,1 };
//int dy[4] = { 1,-1,0,0 };
//void Input() {
//	cin >> N >> K;
//	for (int i = 1; i <= N; i++) {
//		for (int j = 1; j <= N; j++) {
//			cin >> board[i][j];
//		}
//	}
//	for (int i = 1; i <= K; i++) {
//		cin >> horse_list[i].x >> horse_list[i].y >> horse_list[i].dir;
//		horse_list[i].dir -= 1;
//		chess_board[horse_list[i].x][horse_list[i].y].push_back(i);
//	}
//}
//int Change_Dir(int dir) {
//	if (dir == 0)
//		return 1;
//	if (dir == 1)
//		return 0;
//	if (dir == 2)
//		return 3;
//	if (dir == 3)
//		return 2;
//}
//void Move(int num,int x,int y,int nx,int ny) {
//	int idx = 0;
//	for (int i = 0; i < chess_board[x][y].size(); i++) {
//		int nxt = chess_board[x][y][i];
//		if (nxt == num) {
//			idx = i;
//		}
//	}
//	if (board[nx][ny] == 1) { //빨강색 칸인가?
//		reverse(chess_board[x][y].begin() + idx, chess_board[x][y].end());
//	}
//	for (int i = idx; i < chess_board[x][y].size(); i++) {
//		int nxt = chess_board[x][y][i];
//		chess_board[nx][ny].push_back(nxt);
//		horse_list[nxt].x = nx;
//		horse_list[nxt].y = ny;
//	}
//	chess_board[x][y].erase(chess_board[x][y].begin() + idx, chess_board[x][y].end());
//}
//bool Move_Horse() {
//	for (int i = 1; i <= K; i++) {
//		int x = horse_list[i].x;
//		int y = horse_list[i].y;
//		int dir = horse_list[i].dir;
//
//		int nx = x + dx[dir];
//		int ny = y + dy[dir];
//		if (nx<1 || nx>N || ny < 1 || ny>N || board[nx][ny] == 2) { // 파or장외
//			dir = Change_Dir(dir);
//			horse_list[i].dir = dir;
//			nx = x + dx[dir];
//			ny = y + dy[dir];
//			if (nx<1 || nx>N || ny<1 || ny>N || board[nx][ny] == 2) {//다시 파 or 장외
//				continue;
//			}
//			Move(i, x, y, nx, ny);
//		}
//		else {
//			Move(i, x, y, nx, ny);
//		}
//		if (chess_board[nx][ny].size() >= 4) {
//			return false;
//		}
//	}
//	return true;
//}
//void Solution() {
//	int answer = -1;
//	for (int i = 1; i <= 1000; i++) {
//		if (!Move_Horse()) {
//			answer = i;
//			break;
//		}
//	}
//	cout << answer << endl;
//}
//void Solve() {
//	Input();
//	Solution();
//}
//int main() {
//	Solve();
//	return 0;
//}