/*
[BOJ] 17143��: ���ÿ�
���� �ð� : 20�� 33��
���� �ð� : 21�� 27��

���� Ǯ��
1. Input
	1.1) vector<int> board[][]�� �����ϴ� ��� index�� �����Ѵ�.
	1.2) shark_list[]�� �Է¹��� ����� ������ �����Ѵ�.
2. Fishing_Shark
	2.1) �� ĭ�� ������ �� 1�� ������ �ڸ��ϴ�, ���ò��� ���ִ� ������ 1����~R������� Ȯ���ϸ鼭 
		�� �����Ѵٸ� ���̰�, ���� �ش� ��ǥ�� �ʱ�ȭ.
3. Move_Shark
	3.0) ���� ������ �ʱ�ȭ ��Ų��.(������ ���� �����̹Ƿ�)
	3.1) �� �����̴� Ƚ���� ����ȭ���ش�.
		3.1.1) ������ ��,�Ʒ���� s = s % ((R-1)*2) �� ����ȭ
		3.1.2) ��,���� s = s % ((C-1)*2)�� ����ȭ
	3.2) ����ȭ�� Ƚ����ŭ �����̰�, ���� ����ٸ� ���� �ٲٰ� �ٽ� �����δ�.
4. Check_Kill
	4.1) ���� Ž���ϸ鼭 2�� �̻� �� �ִ� ��ǥ�� ã�´�.
	4.2) ����� ũ�� ������ �����ϰ�, 0�� �ε����� �� �������� ��ƸԴ´�.
	4.3) ���� �ش� ��ǥ�� �ʱ�ȭ�ϰ�, 0�� �ε����� �� �ٽ� �߰�.
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
	for (int i = 0; i < M; i++) { //�� �ʱ�ȭ
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
		if (dir == 1 || dir == 2) { //������ ����ȭ
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
		//���ÿ��� ����� ��� ���
		Fishing_Shark(i);
		//��� �̵�
		Move_Shark();
		//��ġ���� Ȯ��
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