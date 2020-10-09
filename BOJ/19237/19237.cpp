/*
[BOJ] 19237��: � ���
���� �ð� : 13�� 30��
���� �ð� : 15�� 06��
�ҿ� �ð� : 1�ð� 36��

���� Ǯ��
1. Shark ����ü�� ����ؼ� ��ġ, ���� ����, ���� �켱����, die ������ ����.
2. Map ����ü�� ����ؼ� �� ��ǥ�� ������ �Ѹ� ����� index, ���� �ð�, ĭ�� �����ϴ� ��� list�� ����.
3. ���� ���� ���� Input�� ���� ���� �����Ѵ�.
4. Time�� 1000�� �� �� ���� ���� �ݺ�.
	4.1) ��� �̵�
		4.1.1) ��� �̵� ����, ���� �� �����ϴ� ��ǥ ���� ���� ���� ��� list�� �ʱ�ȭ�Ѵ�.
		4.1.2) �� ���� ���⿡ ���� �켱���� ������ Ž���Ͽ� �� ��ǥ�� ã�´�.
		4.1.3) Ž�� �߿�, �ڽ��� ���� ������ �߰��Ѵٸ� �ӽ÷� ������ ���´�.
		4.1.4) ����, 4.1.2���� �� ��ǥ�� ã������ �� ��ǥ�� �̵�, ã�� �������� �ڽ��� ���� ���� ��ǥ�� �̵�.
	4.2) ��� ���̱�
		4.2.1) Shark List���� �� ����� ��ǥ�� 2�� �̻��� �� �����Ѵٸ�
				���� ���� ����� index�� ã�� ���� ���� ��, ���� ���� ��� �ܿ� ������ ���� ���δ�.
		4.2.2) �� ���� ��� list�� �ʱ�ȭ�ϰ�, ���� ���� ����� index�� �߰���Ų��.
	4.3) ���� �ð� ����
		�ʿ��� ������ �����ϴ� ĭ�� ������ ������ �ð��� 1 ���ҽ�Ų��.
	4.4) ���� �Ѹ���
		���￡�� �¸��� ���鸸 ������ �Ѹ� �� �����Ƿ� ���� �������� �����Ѵ�.
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
	cout << "��Ƴ��� ��� " << endl;
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
		//��� �̵��ϰ�
		Move_Shark();
		//��� ���̱�
		Kill_Shark();
		//���� �ð� �����ϰ�
		Time_Dec();
		//���ο� ���� �Ѹ���
		Spray_Smell();
		//���� �˻�
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