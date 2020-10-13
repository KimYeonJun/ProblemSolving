///*
//[BO] 17837��: ���ο� ���� 2
//
//���� �ð� : 11�� 50��
//���� �ð� : 12�� 50��
//�ҿ� �ð� : 1�ð�
//
//���� Ǯ��
//1. Input()
//	1.1) board���� ü������ ��, chess_board���� �� ĭ�� �ö� �ִ� ���� index���� ����.
//2. Move_Horse()
//	2.1) �� ���� �̵���Ų��.
//	2,2) ���� ĭ�� �Ķ����̸�, ������ ��ȯ�ϰ� �ٽ� �̵��Ϸ��� ĭ�� �Ķ����� �ƴ϶�� �̵��Ѵ�.
//	2.3) ���� ĭ�� ���, �������̸� �̵�.
//	2.4) �Ѱ��� ���� �̵��� ����������, �̵� �� ��ġ�� ĭ�� ���� 4�� �̻����� Ȯ��.
//3. Move()
//	3.1) �ش� ĭ�� ���� �ִ� �� �߿���, ������ ���� index�� ã�´�.
//	3.2) ���� �� ĭ�� �������̶�� , ã�� index���� ���������� ������ �ٲ���.
//	3.3) index���� ������������ ���� �̵���Ų��.
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
//	if (board[nx][ny] == 1) { //������ ĭ�ΰ�?
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
//		if (nx<1 || nx>N || ny < 1 || ny>N || board[nx][ny] == 2) { // ��or���
//			dir = Change_Dir(dir);
//			horse_list[i].dir = dir;
//			nx = x + dx[dir];
//			ny = y + dy[dir];
//			if (nx<1 || nx>N || ny<1 || ny>N || board[nx][ny] == 2) {//�ٽ� �� or ���
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